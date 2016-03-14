#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct student
{
    char name[16];
    int number;
    int grade;
};

struct student *all_students = 0;
int students_count = 0;

void student_append(const struct student *next_student)
{
    struct student *temp_students = malloc((students_count + 1) * sizeof(struct student));
    memcpy(temp_students, all_students, students_count * sizeof(struct student));
    memcpy(temp_students + students_count, next_student, sizeof(struct student));
    students_count++;
    free(all_students);
    all_students = temp_students;
}

void students_print(FILE *file)
{
    int i = students_count;
    struct student *cs = all_students;
    while (i--)
    {
        fprintf(file, "%d %s %d %d\n", i + 1, cs->name, cs->number, cs->grade);
        cs++;
    }
}

void insert_grade(int number, int grade)
{
    int i;
    for (i = 0; i < students_count; i++)
    {
        if (all_students[i].number == number)
        {
            all_students[i].grade = grade;
            return;
        }
    }
    fprintf(stderr, "grade for %d not found\n", number);
}

int main(int argc, char *argv[])
{
    FILE *file_of_students;
    FILE *file_of_grade;
    FILE *file_of_result;

    if (argc != 4)
    {
        fprintf(stderr, "need only 3 parametrs, you put %d", argc - 1);
        return 2;
    }

    if (!(file_of_students = fopen(argv[1], "r")))
    {
        fprintf(stderr, "cant open file %s", argv[1]);
        return 1;
    }

    struct student st;
    st.grade = 0;
    while (fscanf(file_of_students, "%15s %d\n", st.name, &st.number) == 2)
        student_append(&st);

    students_print(stdout);
    fclose(file_of_students);

    if (!(file_of_grade = fopen(argv[2], "r")))
    {
        fprintf(stderr, "cant open file %s", argv[2]);
        return 3;
    }

    int number;
    int grade;
    while (fscanf(file_of_grade, "%d %d\n", &number, &grade) == 2)
        insert_grade(number, grade);

    students_print(stdout);
    fclose(file_of_grade);

    if (!(file_of_result = fopen(argv[3], "w")))
    {
        fprintf(stderr, "cant write to %s", argv[3]);
        return 5;
    }

    students_print(file_of_result);
    fclose(file_of_result);

    free(all_students);
    return 0;
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct st_student
{
    char name[16];
    double grade_sum;
    int grade_count;

};

int students_count = 0;

int find_position_student(const struct st_student *student, char name)
{
    int i = students_count;
    while (i--)
    {
        if (strcmp(student[i].name, &name));
        return i;
    }
    return -1;
}

void student_append(const struct st_student *next_student, struct st_student **current_students)
{
    int i = find_position_student(current_students, next_student->name);
    printf ("1");
    if ( i != -1)
    {

        current_students[i]->grade_sum += next_student->grade_sum;
        current_students[i]->grade_count++;
        return;
    }
    printf ("2");
    struct st_student *temp_student = malloc((students_count + 1) * sizeof(struct st_student));
    memcpy(temp_student, current_students, students_count * sizeof(struct st_student));
    //    memcpy(temp_student + students_count, next_student, sizeof(struct student));
    students_count++;
    printf ("%d", students_count);
    free(*current_students);
    *current_students = temp_student;
}

print_list_of_students(const struct st_student *students)
{
    int i = students_count;
    while (i--)
        printf ("%s 123", students[i].name);
}

int main(int argc, char *argv[])
{
    FILE *current_file;

    struct st_student *all_students;
    struct st_student student;

    /*  if (argc < 3)
    {
        fprintf(stderr, "need choise two or more files, you put %d", argc - 1);
    }
*/
    int i;
    for (i = 1; i < argc; i++)
    {
        if (!(current_file = fopen(argv[i], "r")))
        {
            fprintf(stderr, "cant open file %s", argv[i]);
            return 1;
        }

        while (fscanf(current_file, "%15s %l", student.name, student.grade_sum) == 2)
        {
            student_append(&student, &all_students);
        }



    }
    print_list_of_students(all_students);
    return 0;
}

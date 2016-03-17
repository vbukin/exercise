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
struct st_student *all_students = 0;

int find_position_student(const char *name)
{
    int i = students_count;
    while (i--)
    {
        if (!strcmp(all_students[i].name, name))
            return i;
    }
    return -1;
}

void student_append(const struct st_student *next_student)
{
    int i = find_position_student(next_student->name);
    if (i != -1)
    {
        all_students[i].grade_sum += next_student->grade_sum;
        all_students[i].grade_count++;
        return;
    }

    struct st_student *temp_student = malloc((students_count + 1) * sizeof(struct st_student));
    memcpy(temp_student, all_students, students_count * sizeof(struct st_student));
    memcpy(temp_student + students_count, next_student, sizeof(struct st_student));
    students_count++;
    free(all_students);
    all_students = temp_student;
}

void print_list_of_students(FILE *file)
{
    int i = students_count;
    while (i--)
        fprintf (file, "%s: %lf: %lf\n", all_students[i].name, all_students[i].grade_sum, all_students[i].grade_sum/all_students[i].grade_count);
}

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        fprintf(stderr, "need choise two or more files, you put %d", argc - 1);
        return 1;
    }

    int i;
    for (i = 1; i < argc - 1; i++)
    {
        FILE *current_file;
        struct st_student student;
        student.grade_count = 1;

        if (!(current_file = fopen(argv[i], "r")))
        {
            fprintf(stderr, "cant open file %s", argv[i]);
            return 2;
        }

        while (fscanf(current_file, "%15s %lf", student.name, &student.grade_sum) == 2)
        {
            student_append(&student);
        }

        fclose(current_file);
    }

    FILE *file_out;
    if ((file_out = fopen(argv[i], "w")))
    {
        print_list_of_students(file_out);
        fclose(file_out);
    }
    else
    {
        fprintf(stderr, "cant open file %s", argv[i]);
        return 3;
    }
    return 0;
}

#include "mylib.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

char *main_str = 0;
int size_main_str = 0;

void str_append(char *str2, int count)
{
    char *new_str = malloc(size_main_str + count);
    memccpy(new_str, main_str, sizeof(char), size_main_str);
    memccpy(new_str + size_main_str, str2, sizeof(char), count);
    if (main_str)
        free(main_str);
    main_str = new_str;
    size_main_str += count;
}

int find_max(char *str, int size, int position)
{
    int max_index = position;
    int i;
    for (i = position; i < size; i++)
    {
        if (str[i] < str[max_index])
            max_index = i;
    }
    return max_index;
}

void array_roll(char *str, int e1, int e2)\
{
    char temp;
    temp = str[e1];
    str[e1] = str[e2];
    str[e2] = temp;
}


void sort(char *str, int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        array_roll(str,i ,find_max(str, size, i));
    }
}

int main(int argc, char *argv[])
{
    if (argc < 0)
    {
        fprintf(stderr, "to many parameters\n");
        return 1;
    }

    while (!feof(stdin))
    {
        const int size = 10;
        char buffer[10];
        int count_char;
        count_char = fread(buffer, sizeof(char), size, stdin);
        str_append(buffer, count_char);
    }
    sort(main_str, size_main_str);
    fwrite(main_str, sizeof(char), size_main_str, stdout);
    printf("[%d]", size_main_str);
    if (main_str)
        free(main_str);

    return 0;
}


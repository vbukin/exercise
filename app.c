#include <stdio.h>
#include <time.h>
#include <limits.h>
#include <stdint.h>
#include <stdlib.h>

#define STUDENT_COUNT 4

struct make_array
{
    int element[];
    int volume;
};

typedef struct student student_t;

void init_array(make_array *array)
{

}

void set_element(make_array *array, int number, int value)
{
    if (array->volume >= number)
        array->element[number] = value;
}

get_elemet(make_array *array, int number)
{
    return array->element[number];
}



int main(int argc, char *argv[])
{	


    /*структура, указатель на данные, размер (элементы)
     * функции, изменить размер (указатель на структуру, новый размер)
     * функция сет(*структура, номер элемента, значение)
     * функция гет(*структура, номер элемента), возвращает значение элемента.
     * функция инит (*структура)
     * /

    /*int array[array_size] = {2, 1};
    sort_array(array, array_size, compare3);
    print_array(array, array_size);
    */
    int volume;
    int *array;
    int i;

    if (scanf("%d", &volume) == 1)
    {
        array = malloc(volume * sizeof(int));
    }

    for (i = 0; i < volume; i++)
    {
        printf("array[%d] = ", i);
        scanf("%d", &array[i]);
    }

    print_array(array, volume);
    free(array);
    return 0;
}



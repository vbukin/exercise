#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "mylib.h"

struct vector
{
    int *data;
    int size;
    int heap_size;
};

void vector_init(struct vector *vector)
{
    vector->data = 0;
    vector->size = 0;
    vector->heap_size = 0;
}

int vector_at(const struct vector *vector, int index)
{
    assert((index >= 0) && (index < vector->size));
    return vector->data[index];
}

void vector_set(struct vector *vector, int index, int value)
{
    assert((index >= 0) && (index < vector->size));
    vector->data[index] = value;
}

int p2t(int value)
{
    assert(value >= 0);
    int i = 8 * sizeof(int);

    while (i--)
    {
        if (value & ( 1 << i))
            break;
    }
    return 1 << (i + 1);
}

void vector_resize(struct vector *vector, int count)
{
    if (count > vector->heap_size)
    {
        int i;
        int *new_data;
        vector->heap_size = p2t(count);
        new_data = malloc(vector->heap_size * sizeof(int));
        for (i = 0; i < count; i++)
            new_data[i] =  i < vector->size ? vector->data[i] : 0;
        if (vector->data)
            free(vector->data);
        vector->data = new_data;
        vector->size = count;
        printf("+ \n");
    }
    else
    {
        int i;
        for (i = vector->size; i < count; i++)
            vector->data[i] = 0;
        vector->size = count;
    }
}

int vector_size(const struct vector *vector)
{
    return vector->size;
}

void vector_finit(struct vector *vector)
{
    if (vector->data)
        free(vector->data);

    vector->data = 0;
    vector->size = 0;
    vector->heap_size = 0;
}

void vector_print(const struct vector *vector)
{
    int i;
    printf("(");
    for (i = 0; i < vector->size; i++)
        printf("%d ", vector->data[i]);
    printf(") %d\n", vector->heap_size);
}

void vector_append(struct vector *vector, int value)
{
    vector_resize(vector, vector_size(vector) + 1);
    vector_set(vector, vector_size(vector) - 1, value);
}

void vector_insert(struct vector *vector, int value, int position)
{
    int i;
    const int n = vector_size(vector) + 1;
    vector_resize(vector, n);
    for (i = n - 1; i > position; i--)
    {
        vector_set(vector, i, vector_at(vector,i - 1 ));
    }
    vector_set(vector, position, value);
}

struct list
{
    char data;
    struct list *next;
};

void list_print(const struct list *head)
{
    printf("{");
    while (head)
    {
        printf("%c", head->data);
        head = head->next;
    }
    printf("}\n");
}

void list_prepend(struct list **head, char value)
{
    struct list *new_head = malloc(sizeof(struct list));
    new_head->data = value;
    new_head->next = *head;
    *head = new_head;
}

void list_drop(struct list **head)
{
    struct list *new_head = (*head)->next;
    free(*head);
    *head = new_head;
}

void list_clear(struct list **head)
{
    while(*head)
        list_drop(head);
}

struct list *list_find(struct list *head, int index)
{
    while (head && index)
    {
        head = head->next;
        index--;
    }
    return head;
}

char list_at(struct list *head, int index)
{
    struct list *temp = list_find(head, index);
    assert(temp);
    return temp->data;
}

void list_set(struct list *head, int index, char value)
{
    struct list *temp = list_find(head, index);
    assert(temp);
    temp->data = value;
}

void list_insert(struct list *head, int index, char value)
{
    struct list *temp = list_find(head, index);
    assert(temp);
    list_prepend(&temp->next, value);
}

void list_remove(struct list *head, int index)
{
    struct list *temp = list_find(head, index);
    assert(temp);
    list_drop(&temp->next);
}


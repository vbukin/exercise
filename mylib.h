#ifndef MYLIB_H
#define MYLIB_H

struct vector;

void vector_init(struct vector *vector);
int vector_at(const struct vector *vector, int index);
void vector_set(struct vector *vector, int index, int value);
void vector_resize(struct vector *vector, int count);
int vector_size(const struct vector *vector);
void vector_print(const struct vector *vector);
void vector_append(struct vector *vector, int value);
void vector_insert(struct vector *vector, int value, int position);

struct list;

void list_print(const struct list *head);
void list_remove(struct list *head, int index);
void list_prepend(struct list **head, char value);
void list_drop(struct list **head);
void list_clear(struct list **head);
char list_at(struct list *head, int index);
void list_set(struct list *head, int index, char value);
void list_insert(struct list *head, int index, char value);
void list_remove(struct list *head, int index);

#endif

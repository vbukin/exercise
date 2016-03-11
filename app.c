#include "mylib.h"

int main(int argc, char *argv[])
{
    struct list *l1 = 0;
    list_prepend(&l1, 'a');
    list_prepend(&l1, 'b');

    list_insert(l1, 1, 'c');
    list_insert(l1, 1, 'E');

    list_remove(l1, 2);

    list_print(l1);

    list_clear(&l1);

    list_print(l1);

    return 0;
}


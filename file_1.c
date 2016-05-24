#include "common.h"

static int bar_file = 9;

static void foo_file(void)
{
    int bar_function;

    bar_function = 1;

}

void foo_global_1(void)
{
    foo_file();
    bar_global = 5;
}



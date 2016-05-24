#include "common.h"

static void foo_file(void);

static int bar_file;

void foo_global_2(void)
{
    foo_global_1();
    foo_file();

    bar_global = 10;
    bar_file = 7;
}

static void foo_file(void)
{
    int bar_function;
    static int bar_function_stat = 0;

    bar_function = 2;

    bar_function_stat++;
}

int bar_global;

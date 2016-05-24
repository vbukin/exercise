#include "common.h"

int bar1 = 1;
extern int bar2;
char bar3 = '1';
foo1();
void foo3(void)
{
    extern int bar4 = 1;
    char bar5 = '123';
    static int bar5 = 1;
}

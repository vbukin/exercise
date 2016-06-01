#include <stdio.h>
#include <string.h>


int error(const char *text)
{
    fprintf(stderr, "Error: %s\n", text);
    return 1;
}

void process(FILE *file, const char *pattern)
{
    const char *p = pattern;
    int good = 1;

    char buffer[strlen(pattern) + 1];
    char *b = buffer;


    while (!feof(file))
    {
        char f = fgetc(file);

        if (f == '\n')
        {
            if (good && *p == 0)
                fprintf(stdout, "{%s}\n", buffer);

            good = 1;
            p = pattern;
            b = buffer;
            continue;
        }

        if (*p == 0)
            good = 0;

        if (good && (*p == f || *p == '*'))
        {
            *b++ = f;
            p++;
        }
        else
        {
            good = 0;
        }


    }
}

int main(int argc, char *argv[])
{
    FILE *file;

    if (argc != 3)
        return error("Two parameters expected");

    if (!(file = fopen(argv[1], "r")))
        return error("Can't open file");

    process(file, argv[2]);

    fclose(file);

    return 0;
}

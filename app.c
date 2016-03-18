#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <math.h>

struct matrix
{
    int row_count;
    int col_count;
    float **rows;
};


void allocate(struct matrix *m, int rows, int cols)
{
    float** new_rows;

    new_rows = malloc(sizeof(float *) * rows);

    int i;
    for (i = 0; i < rows; i++)
    {
        float* new_row = malloc(sizeof(float) * cols);
        *(new_rows + i) = new_row;
    }

    (*m).row_count = rows;
    (*m).col_count = cols;
    (*m).rows = new_rows;
}

void deallocate(struct matrix *m)
{
    int i;
    for (i = 0; i < (*m).row_count; i++)
        free(*((*m).rows + i));
    free((*m).rows);
    (*m).col_count = 0;
    (*m).row_count = 0;
    (*m).rows = 0;
}

void set(struct matrix *m, int row, int col, float value)
{
    assert((col >= 0) && (col < (*m).col_count));
    assert((row >= 0) && (row < (*m).row_count));
    *(*((*m).rows + row) + col) = value;
}

float get(const struct matrix *m, int row, int col)
{
    assert((col >= 0) && (col < (*m).col_count));
    assert((row >= 0) && (row < (*m).row_count));
    return *(*((*m).rows + row) + col);
}

void print(const struct matrix *m, FILE *file)
{
    int row;
    for (row = 0; row < (*m).row_count; row++)
    {
        int col;
        for (col = 0; col < (*m).col_count; col++)
            fprintf(file, "%f ", *(*((*m).rows + row) + col));
        fprintf(file, "\n");
    }
    fprintf(file, "\n");
}


void sum(const struct matrix *a, const struct matrix *b, struct matrix *res)
{
    assert(((*a).col_count == (*b).col_count) && ((*a).row_count == (*b).row_count));
    assert(((*a).col_count == (*res).col_count) && ((*a).row_count == (*res).row_count));
    const int rows = (*a).row_count;
    const int cols = (*a).col_count;
    int row;
    for (row = 0; row < rows; row++)
    {
        int col;
        for (col = 0; col < cols; col++)
            *(*((*res).rows + row) + col) = *(*((*a).rows + row) + col)  + *(*((*b).rows + row) + col);
    }
}



int main(int argc, char **argv)
{
    struct matrix a;
    struct matrix b;
    struct matrix c;

    allocate(&a, 3, 2);
    allocate(&b, 3, 2);
    allocate(&c, 3, 2);

    set(&a, 1, 0, M_PI);
    set(&a, 2, 1, 2.71);

    set(&b, 0, 0, 1);
    set(&b, 2, 1, 2);

    sum(&b, &a, &c);

    print(&a, stdout);
    print(&b, stdout);
    print(&c, stdout);

    deallocate(&a);
    deallocate(&b);
    deallocate(&c);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#define ELEM(mat, i, j) ((mat)->elem[(i) * (mat)->cols + j])

typedef struct
{
     unsigned int rows;
     unsigned int cols;
     float *elem;
} MAT;

MAT *mat_create_with_type(unsigned int rows, unsigned int cols)
{
     MAT *mat = (MAT *)malloc(sizeof(MAT));
     mat->rows = rows;
     mat->cols = cols;
     mat->elem = (float *)malloc(rows * cols * sizeof(float));
     return mat;
}

MAT *mat_create_by_file(char *filename)
{
     FILE *file = fopen(filename, "matica");
     if (file == NULL)
     {
          return NULL;
     }

     unsigned int row, cols;
     fread(&rows, sizeof(unsigned int), 1, file);
     fread(&cols, sizeof(unsigned int), 1, file);
}
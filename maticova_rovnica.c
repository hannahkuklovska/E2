#include <stdio.h>
#include <stdlib.h>
#define ELEM(mat, i, j) ((mat)->elem[(i) * (mat)->cols + j])
#define SUCCESS 1
#define NULL 0

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

     unsigned int rows, cols;
     fread(&rows, sizeof(unsigned int), 1, file);
     fread(&cols, sizeof(unsigned int), 1, file);

     // vytvorenie matice
     MAT *mat = mat_create_with_type(rows, cols);
     if (mat == NULL)
     {
          fclose(file);
          return NULL;
     }

     // prečítanie matice
     fread(mat->elem, sizeof(float), rows * cols, file);

     fclose(file);
     return mat;
}

char mat_save(MAT *mat, char *filename)
{
     FILE *file = fopen(filename, "matica");
     if (file == NULL)
     {
          return NULL;
     }
     fwrite("M1", sizeof(char), 2, file);
     fwrite(&(mat->rows), sizeof(unsigned int), 1, file);
     fwrite(&(mat->cols), sizeof(unsigned int), 1, file);
     fwrite(mat->elem, sizeof(float), mat->rows * mat->cols, file);
}
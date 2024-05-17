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
     if (mat == NULL)
     {
          return NULL;
     }
     mat->rows = rows;
     mat->cols = cols;
     mat->elem = (float *)malloc(rows * cols * sizeof(float));
     if (mat->elem == NULL)
     {
          free(mat);
          return NULL;
     }
     return mat;
}

MAT *mat_create_by_file(char *filename)
{
     unsigned int rows, cols;
     FILE *file = fopen(filename, "matica");
     if (file == NULL)
     {
          return NULL;
     }

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
     fclose(file);
     return SUCCESS;
}

void mat_destroy(MAT *mat)
{
     if (mat != NULL)
     {
          free(mat->elem);
          free(mat);
     }
}

void mat_unit(MAT *mat)
{
     unsigned int i, j;
     for (i = 0; i < mat->rows; i++)
     {
          for (j = 0; j < mat->cols; j++)
          {
               if (i == j)
               {
                    ELEM(mat, i, j) = 1.0;
               }
               else
               {
                    ELEM(mat, i, j) = 0.0;
               }
          }
     }
}

void mat_random(MAT *mat)
{
     unsigned int i, j;
     for (i = 0; i < mat->rows; i++)
     {
          for (j = 0; j < mat->cols; j++)
          {
               ELEM(mat, i, j) = -1.0 + 2 * ((float)rand()) / RAND_MAX;
          }
     }
}

void mat_print(MAT *mat)
{
     unsigned int i, j;
     for (i = 0; i < mat->rows; i++)
     {
          for (j = 0; j < mat->cols; j++)
          {
               printf("%.2f\t", ELEM(mat, i, j));
          }
          printf("\n");
     }
}

char mat_division(MAT *a, MAT *b, MAT *c)
{

     // vysledna matica
     mat_unit(c);
     c->cols = b->cols;
     c->rows = a->cols;
}
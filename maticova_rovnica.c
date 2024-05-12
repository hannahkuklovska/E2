#include <stdio.h>
#include <stdlib.h>
#define ELEM(mat, i, j) ((mat)->elem[(i) * (mat)->cols + j])

typedef struct
{
     unsigned int rows;
     unsigned int cols;
     float *elem;
} MAT;

#include "prototypes.h"

int** createArray(int m, int n)
{
  int* values = calloc(m*n, sizeof(int));
  int** rows = malloc(n*sizeof(int*));
  for (int i=0; i<n; ++i)
  {
    rows[i] = values + i*m;
  }
  return rows;
}

void destroyArray(int** arr)
{
  free(*arr);
  free(arr);
}

int collide2d(float x1, float y1, float x2, float y2, float wt1, float ht1, float wt2, float ht2)
{
  return (!((x1 >= (x2+wt2/3)) || (x2 >= (x1+wt1/3)) || (y1 >= (y2+ht2/3)) || (y2 >= (y1+ht1/3))));
}

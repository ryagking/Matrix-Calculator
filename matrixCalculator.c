#include <stdio.h>
#include "matrixCalculator.h"

main()
{
  printf("Hello!\n");
  int arr[2][2];
  for(int i = 0; i < 2; i++)
  {
    for(int k = 0; k < 2; k++)
    {
      arr[i][k] = 1;
    }
  }

  printf("%d", getRank(2, 2, arr));
}

int getRank(size_t rows, size_t cols, int matrix[rows][cols]) 
{
  int rank = 0;
  for(int i = 0; i < rows; i++)
  {
    for(int k = 0; k < cols; k++)
    {
      if(matrix[i][k] != 0)
      {
        rank++;
        break;
      }
    }
  }

  return rank;
}

void getProduct(size_t rows, size_t cols, int matrix[rows][cols], size_t rows2, size_t cols2, int bmatrix[rows2][cols2])
{

}

void getSum(size_t rows, size_t cols, int matrix[rows][cols], size_t rows2, size_t cols2, int bmatrix[rows2][cols2])
{

}

void getDifference(size_t rows, size_t cols, int matrix[rows][cols], size_t rows2, size_t cols2, int bmatrix[rows2][cols2])
{

}
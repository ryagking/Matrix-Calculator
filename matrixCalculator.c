#include <stdio.h>
#include "matrixCalculator.h"

main()
{
  printf("Hello!\n");
  int arr[2][2] = { 
                    {0, 2},
                    {1, 1}};
  int brr[2][2] = {
                    {10, 20},
                    {23, 54}};
  int crr[2][2];
  printf("%d\n", getRank(2, 2, arr));
  getDifference(2, 2, arr, brr, crr);
  printMatrix(2, 2, crr);
}

//works
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

//works
void getSum(size_t rows, size_t cols, int matrix[rows][cols], int matrix2[rows][cols], int matrix3[rows][cols])
{
  for(int r = 0; r < rows; r++)
  {
    for(int c = 0; c < cols; c++)
    {
      matrix3[r][c] = matrix[r][c] + matrix2[r][c]; 
    }
  }
}

//works
void getDifference(size_t rows, size_t cols, int matrix[rows][cols], int matrix2[rows][cols], int matrix3[rows][cols])
{
  for(int r = 0; r < rows; r++)
  {
    for(int c = 0; c < cols; c++)
    {
      matrix3[r][c] = matrix[r][c] - matrix2[r][c];
    }
  }
}

/**
 * Helper function to print a matrix.
 */
void printMatrix(size_t rows, size_t cols, int matrix[rows][cols])
{
  for(int r = 0; r < rows; r++)
  {
    for(int c = 0; c < cols; c++)
    {
      printf("%d,", matrix[r][c]);
    }
    printf("\n");
  }
}
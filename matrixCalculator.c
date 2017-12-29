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
  getProduct(2, 2, arr, 2, 2, brr);
  getREF(2, 2, arr);
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

//works
void getProduct(size_t rows, size_t cols, int aMatrix[rows][cols], size_t rows2, size_t cols2, int bMatrix[rows2][cols2])
{
    if(cols != rows2)
    {
      return;
    }

    int pMatrix[rows][cols2];
    int mark = 0;

    for(int i = 0; i < rows; i++)
    {
      for(int j = 0; j < cols2; j++)
      {
          int sum = 0;
          for(int k = 0; k < cols; k++)
          {
            sum += aMatrix[i][k] * bMatrix[k][j];
          }

          pMatrix[i][j] = sum;
      }
    }

    printMatrix(rows, cols2, pMatrix);
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

void getREF(size_t rows, size_t cols, int matrix[rows][cols])
{
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            if(matrix[i][j] == 0) //if pivot is 0
            {   
                for(int m = i + 1; m < rows; m++) //look for new pivot
                {
                    if(matrix[m][j] != 0) //new pivot found
                    {
                      swap(rows, cols, matrix, i, m);
                      break;
                    }
                }
            }

            int pivot = matrix[i][j]; //select pivot

            for(int k = j + 1; k < cols; k++) //divide entire row by pivot
            {
              matrix[i][k] /= pivot;
            }

            /**
             * Set entire column to zero except for the pivot
             */
            for(int t = i + 1; t < rows; t++)
            {
              int elim = matrix[t][j] / matrix[i][j];
              for(int s = j; s < cols; s++)
              {
                matrix[t][s] -= matrix[i][s] * elim;
              }

            }
        }
        printMatrix(rows, cols, matrix);
    }
    
}

/**
 * void getInverse(size_t rows, size_t cols, int matrix[rows][cols])
 * {
 *  //calculate the matrix of minors
 *  //then turn that into the matrix of cofactors
 *  //then the adjugate
 *  //multiply that by 1/determinant
 * }
  */

void swap(size_t rows, size_t cols, int matrix[rows][cols], int a, int b)
{
    for(int j = 0; j < cols; j++)
    {
      int temp = matrix[a][j];
      matrix[b][j] = matrix[a][j];
      matrix[a][j] = temp;
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
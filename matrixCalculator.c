#include <stdio.h>
#include <math.h>
#include "matrixCalculator.h"

main()
{
  printf("Hello!\n");
  double arr[2][2] = { 
                    {0, 2},
                    {1, 1}};
  double brr[2][2] = {
                    {10, 20},
                    {23, 54}};
  double crr[2][2];
  double drr[10][10] = {{75, 64, 85, 77, 62, 66, 97, 41, 49, 93},
                        {18, 56, 92, 30, 94, 2, 90, 31, 5, 12},
                        {25, 47, 46, 33, 73, 71, 45, 80, 23, 13},
                        {67, 70, 51, 24, 53, 48, 98, 28, 59, 65},
                        {11, 82, 57, 87, 20, 21, 99, 6, 38, 84},
                        {55, 76, 37, 8, 86, 36, 27, 10, 22, 4},
                        {52, 32, 35, 19, 69, 50, 1, 43, 68, 17},
                        {83, 29, 60, 81, 72, 9, 100, 14, 15, 91},
                        {7, 88, 3, 79, 16, 74, 61, 54, 40, 58},
                        {44, 34, 42, 96, 78, 39, 89, 63, 26, 95}};
  printf("%d\n", getRank(2, 2, arr));
  getDifference(2, 2, arr, brr, crr);
  getProduct(2, 2, arr, 2, 2, brr);
  getREF(10, 10, drr);
  printMatrix(2, 2, crr);
}

//works
int getRank(size_t rows, size_t cols, double matrix[rows][cols])
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
void getProduct(size_t rows, size_t cols, double aMatrix[rows][cols], size_t rows2, size_t cols2, double bMatrix[rows2][cols2])
{
    if(cols != rows2)
    {
      return;
    }

    double pMatrix[rows][cols2];

    for(int i = 0; i < rows; i++)
    {
      for(int j = 0; j < cols2; j++)
      {
          double sum = 0;
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
void getSum(size_t rows, size_t cols, double matrix[rows][cols], double matrix2[rows][cols], double matrix3[rows][cols])
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
void getDifference(size_t rows, size_t cols, double matrix[rows][cols], double matrix2[rows][cols], double matrix3[rows][cols])
{
  for(int r = 0; r < rows; r++)
  {
    for(int c = 0; c < cols; c++)
    {
      matrix3[r][c] = matrix[r][c] - matrix2[r][c];
    }
  }
}

void getREF(size_t rows, size_t cols, double matrix[rows][cols])
{
  //printMatrix(rows, cols, matrix);
    for(int i = 0; i < rows; i++)
    {
      //printf("a");
        //for(int j = 0; j < cols; j++)
        //{
          //printf("b");
            if(matrix[i][i] == 0) //if pivot is 0
            {   
                for(int m = i + 1; m < rows; m++) //look for new pivot
                {
                  //printf("c");
                    if(matrix[m][i] != 0) //new pivot found
                    {
                      swap(rows, cols, matrix, i, m);
                      break;
                    }
                }
            }
            //printf("e");
            double pivot = matrix[i][i]; //select pivot
            //printf("\n pivot: %d\n", pivot);
            for(int k = 0; k < cols; k++) //divide entire row by pivot
            {
              //printf("row: %d\n", i);
              matrix[i][k] /= pivot;
              //printMatrix(rows, cols, matrix);
            }

            pivot = matrix[i][i];
            /**
             * Set entire column to zero except for the pivot
             */
            for(int t = 0; t < rows; t++)
            {
              if(t == i)
              {
                continue;
              }
              //printf("\nh");
              //printf("\n t: %d", t);
              double elim = matrix[t][i] / pivot;
              //printf("\n elim: %d", elim);
              for(int s = i; s < cols; s++)
              {
                matrix[t][s] -= matrix[i][s] * elim;
              }
            }
        //}
        //printf("\n");
       
    }
    printMatrix(rows, cols, matrix);
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

void swap(size_t rows, size_t cols, double matrix[rows][cols], int a, int b)
{
  //printf("d");  
    for(int j = 0; j < cols; j++)
    {
      double temp = matrix[b][j];
      matrix[b][j] = matrix[a][j];
      matrix[a][j] = temp;
    }
}

/**
 * Helper function to print a matrix.
 */
void printMatrix(size_t rows, size_t cols, double matrix[rows][cols])
{
  for(int r = 0; r < rows; r++)
  {
    for(int c = 0; c < cols; c++)
    {
      if(c + 1 == cols)
      {
        if(rint(matrix[r][c]) == matrix[r][c])
        {
          int d = matrix[r][c];
          printf("%d ", d);
        }
        else
        {
          printf("%f", matrix[r][c]);
        }
      }
      else
      {
        if(rint(matrix[r][c]) == matrix[r][c])
        {
          int d = matrix[r][c];
          printf("%d, ", d);
        }
        else
        {
          printf("%f", matrix[r][c]);
        }
      }
    }
    printf("\n");
  }
}
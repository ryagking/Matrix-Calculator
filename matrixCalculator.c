#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "matrixCalculator.h"

main()
{
  printf("Hello!\n");
}

//works
int getRank(double **matrix, int rows, int cols)
{
  int rank = 0;
  int i, k;
  for (i = 0; i < rows; i++)
  {
    for (k = 0; k < cols; k++)
    {
      if (matrix[i][k] != 0)
      {
        rank++;
        break;
      }
    }
  }

  return rank;
}

//works
void getProduct(double **aMatrix, double **bMatrix, int aRows, int aCols, int bRows, int bCols)
{
    if (aCols != bRows)
    {
      return;
    }
    int i, j, k, t;

    double **pMatrix;

    for (i = 0; i < aRows; i++)
    {
      for (j = 0; j < bCols; j++)
      {
          double sum = 0;
          for (k = 0; k < aCols; k++)
          {
            sum += aMatrix[i][k] * bMatrix[k][j];
          }

          pMatrix[i][j] = sum;
      }
    }

    //printMatrix(rows, cols2, pMatrix);
    printMatrix(pMatrix, aRows, bCols);
}

//works
void getSum(double **aMatrix, double **bMatrix, double **cMatrix, int rows, int cols)
{
  int r, c;
  for (r = 0; r < rows; r++)
  {
    for (c = 0; c < cols; c++)
    {
      cMatrix[r][c] = aMatrix[r][c] + bMatrix[r][c]; 
    }
  }
}

//works
void getDifference(double **aMatrix, double **bMatrix, double **cMatrix, int rows, int cols)
{
  int r, c;
  for (r = 0; r < rows; r++)
  {
    for (c = 0; c < cols; c++)
    {
      cMatrix[r][c] = aMatrix[r][c] - bMatrix[r][c];
    }
  }
}

void getREFgetREF(double **matrix, int rows, int cols)
{
  //printMatrix(rows, cols, matrix);
  int i, k, m, s, t;

  for (i = 0; i < rows; i++)
  {
    if(matrix[i][i] == 0) //if pivot is 0
    {   
      for(m = i + 1; m < rows; m++) //look for new pivot
      {
        if (matrix[m][i] != 0) //new pivot found
        {
          //swap(rows, cols, matrix, i, m);
          swap(matrix, i, m, rows, cols);
          break;
        }
      }
    }

    double pivot = matrix[i][i]; //select pivot
    for (k = 0; k < cols; k++) //divide entire row by pivot
    {
      matrix[i][k] /= pivot;
    }

    pivot = matrix[i][i];

    /**
     * Set entire column to zero except for the pivot
     */
    for (t = 0; t < rows; t++)
    {
      if (t == i)
      {
        continue;
      }
      
      //printf("\nh");
      //printf("\n t: %d", t);
      double elim = matrix[t][i] / pivot;
      //printf("\n elim: %d", elim);
      for (s = i; s < cols; s++)
      {
        matrix[t][s] -= matrix[i][s] * elim;
      }
    }
  }
  
  printMatrix(matrix, rows, cols);
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

void getTranspose(double **matrix, int rows, int cols)
{

}

void getDeterminant(double **matrix, int rows, int cols)
{

}

void getInverse(double **matrix, int rows, int cols)
{

}

void swap(double **matrix, int a, int b, int rows, int cols)
{
  int j; 
  for (j = 0; j < cols; j++)
  {
    double temp = matrix[b][j];
    matrix[b][j] = matrix[a][j];
    matrix[a][j] = temp;
  }
}

/**
 * Helper function to print a matrix.
 */
void printMatrix(double **matrix, int rows, int cols)
{
  int r, c;
  for (r = 0; r < rows; r++)
  {
    for (c = 0; c < cols; c++)
    {
      if (c + 1 == cols)
      {
        if (rint(matrix[r][c]) == matrix[r][c])
        {
          int d = matrix[r][c];
          printf("%d ", d);
        }
        else
        {
          printf("%f", matrix[r][c]);
        }
      }
      else if (rint(matrix[r][c]) == matrix[r][c])
      {
        int d = matrix[r][c];
        printf("%d, ", d);
      }
      else
      {
        printf("%f", matrix[r][c]);
      }
     }
    printf("\n");
  }
}
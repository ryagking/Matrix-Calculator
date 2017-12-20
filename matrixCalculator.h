int getRank(size_t rows, size_t cols, int matrix[rows][cols]);
void getProduct(size_t rows, size_t cols, int matrix[rows][cols], size_t rows2, size_t cols2, int bmatrix[rows2][cols2]);
void getSum(size_t rows, size_t cols, int matrix[rows][cols], int matrix2[rows][cols], int matrix3[rows][cols]);
void getDifference(size_t rows, size_t cols, int matrix[rows][cols], int matrix2[rows][cols], int matrix3[rows][cols]);
void transpose(size_t rows, size_t cols, int **matrix[rows][cols]);
void printMatrix(size_t rows, size_t cols, int matrix[rows][cols]);
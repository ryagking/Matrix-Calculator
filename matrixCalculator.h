int getRank(size_t rows, size_t cols, double matrix[rows][cols]);
void getProduct(size_t rows, size_t cols, double aMatrix[rows][cols], size_t rows2, size_t cols2, double bMatrix[rows2][cols2]);
void getSum(size_t rows, size_t cols, double matrix[rows][cols], double matrix2[rows][cols], double matrix3[rows][cols]);
void getDifference(size_t rows, size_t cols, double matrix[rows][cols], double matrix2[rows][cols], double matrix3[rows][cols]);
void getREF(size_t rows, size_t cols, double matrix[rows][cols]);
void swap(size_t rows, size_t cols, double matrix[rows][cols], int a, int b);
void printMatrix(size_t rows, size_t cols, double matrix[rows][cols]);
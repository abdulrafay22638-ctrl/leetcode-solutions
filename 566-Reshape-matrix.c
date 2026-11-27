int** matrixReshape(int** mat, int matSize, int* matColSize,
                    int r, int c,
                    int* returnSize, int** returnColumnSizes) {

    int rows = matSize;
    int cols = matColSize[0];

    if (rows * cols != r * c) {
        *returnSize = rows;
        *returnColumnSizes = malloc(rows * sizeof(int));

        for (int i = 0; i < rows; i++)
            (*returnColumnSizes)[i] = cols;

        return mat;
    }

    int** result = malloc(r * sizeof(int*));
    *returnColumnSizes = malloc(r * sizeof(int));

    for (int i = 0; i < r; i++) {
        result[i] = malloc(c * sizeof(int));
        (*returnColumnSizes)[i] = c;
    }

    for (int i = 0; i < rows * cols; i++) {
        result[i / c][i % c] = mat[i / cols][i % cols];
    }

    *returnSize = r;
    return result;
}
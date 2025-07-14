int longPath(int **matrix, int **mem, int m, int n, int x, int y) {
    if (mem[x][y] != 0) return mem[x][y];
    int r = 1, l = 1, u = 1, d = 1;
    
    if (x - 1 >= 0 && matrix[x-1][y] > matrix[x][y]) l = 1 + longPath(matrix, mem, m, n, x-1, y);
    if (x + 1 < m && matrix[x+1][y] > matrix[x][y]) r = 1 + longPath(matrix, mem, m, n, x+1, y);
    if (y - 1 >= 0 && matrix[x][y-1] > matrix[x][y]) d = 1 + longPath(matrix, mem, m, n, x, y-1);
    if (y + 1 < n && matrix[x][y+1] > matrix[x][y]) u = 1 + longPath(matrix, mem, m, n, x, y+1);
    
    int maior = l;
    if (maior < r) maior = r;
    if (maior < d) maior = d;
    if (maior < u) maior = u;

    mem[x][y] = maior;
    return maior;
}

int longestIncreasingPath(int** matrix, int matrixSize, int* matrixColSize) {
    int m = matrixSize, n = *matrixColSize;
    int** mem = malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++) {
        mem[i] = calloc(n, sizeof(int));
    }

    int maior = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int val = longPath(matrix, mem, m, n, i, j);
            if (maior < val) maior = val;
        }
    }

    for (int i = 0; i < m; i++) free(mem[i]);
    free(mem);

    return maior;
}

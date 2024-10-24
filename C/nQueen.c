#include <stdio.h>
#include <stdbool.h>

void printSolution(int N, int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf("%2d ", board[i][j]);
        printf("\n");
    }
}

bool isSafe(int N, int board[N][N], int row, int col) {
    // Check this row on the left side
    for (int i = 0; i < col; i++)
        if (board[row][i])
            return false;

    // Check upper diagonal on the left side
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    // Check lower diagonal on the left side
    for (int i = row, j = col; i < N && j >= 0; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

bool solveNQueensUtil(int N, int board[N][N], int col) {
    if (col >= N)
        return true;

    for (int i = 0; i < N; i++) {
        if (isSafe(N, board, i, col)) {
            board[i][col] = 1;

            if (solveNQueensUtil(N, board, col + 1))
                return true;

            board[i][col] = 0; // Backtrack
        }
    }

    return false;
}

bool solveNQueens(int N) {
    int board[N][N];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            board[i][j] = 0;

    if (!solveNQueensUtil(N, board, 0)) {
        printf("Solution does not exist.\n");
        return false;
    }

    printf("Solution for %d-Queens problem:\n", N);
    printSolution(N, board);
    return true;
}

int main() {
    int N;

    printf("Enter the value of N: ");
    scanf("%d", &N);

    solveNQueens(N);

    return 0;
}

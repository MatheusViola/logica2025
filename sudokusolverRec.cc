#include <stdio.h>

#define SIZE 9

int isValid(int grid[SIZE][SIZE], int row, int col, int num) {
    for (int i = 0; i < SIZE; i++)
        if (grid[row][i] == num || grid[i][col] == num)
            return 0;

    int startRow = row / 3 * 3, startCol = col / 3 * 3;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (grid[startRow + i][startCol + j] == num)
                return 0;

    return 1;
}

int solve(int grid[SIZE][SIZE], int row, int col) {
    if (row == SIZE) return 1;

    int nextRow = col == SIZE - 1 ? row + 1 : row;
    int nextCol = (col + 1) % SIZE;

    if (grid[row][col] != 0)
        return solve(grid, nextRow, nextCol);

    for (int num = 1; num <= 9; num++) {
        if (isValid(grid, row, col, num)) {
            grid[row][col] = num;
            if (solve(grid, nextRow, nextCol)) return 1;
            grid[row][col] = 0;
        }
    }

    return 0;
}

void printGrid(int grid[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++)
            printf("%d ", grid[i][j]);
        printf("\n");
    }
}

int main() {
    int grid[SIZE][SIZE];

    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            scanf("%d", &grid[i][j]);

    if (solve(grid, 0, 0))
        printGrid(grid);
    else
        printf("Sem solucao\n");

    return 0;
}

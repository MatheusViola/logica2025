#include <stdio.h>

#define SIZE 9

void printGrid(int grid[SIZE][SIZE]) {
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++)
            printf("%2d ", grid[i][j]);
        printf("\n");
    }
    printf("\n");
}

int main() {
    int grid[SIZE][SIZE];

    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            scanf("%d", &grid[i][j]);

    printGrid(grid);

    int row, col, num;

    while (1) {
        scanf("%d", &row);
        if (row == -1) break;
        scanf("%d %d", &col, &num);
        if (row < 1 || row > 9 || col < 1 || col > 9 || num < 1 || num > 9) continue;
        grid[row - 1][col - 1] = num;
        printGrid(grid);
    }

    return 0;
}

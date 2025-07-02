#include <stdio.h>

int checkSudoku(int grid[9][9]) {
    int i, j, k, l;
    int seen[10];

    for (i = 0; i < 9; i++) {
        for (k = 1; k <= 9; k++) seen[k] = 0;
        for (j = 0; j < 9; j++) {
            int num = grid[i][j];
            if (num < 1 || num > 9 || seen[num]) return 0;
            seen[num] = 1;
        }
    }

    for (j = 0; j < 9; j++) {
        for (k = 1; k <= 9; k++) seen[k] = 0;
        for (i = 0; i < 9; i++) {
            int num = grid[i][j];
            if (num < 1 || num > 9 || seen[num]) return 0;
            seen[num] = 1;
        }
    }

    for (i = 0; i < 9; i += 3) {
        for (j = 0; j < 9; j += 3) {
            for (k = 1; k <= 9; k++) seen[k] = 0;
            for (k = 0; k < 3; k++) {
                for (l = 0; l < 3; l++) {
                    int num = grid[i + k][j + l];
                    if (num < 1 || num > 9 || seen[num]) return 0;
                    seen[num] = 1;
                }
            }
        }
    }

    return 1;
}

int main() {
    int grid[9][9];

    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            scanf("%d", &grid[i][j]);

    if (checkSudoku(grid))
        printf("Instancia 1\nSIM\n");
    else
        printf("Instancia 1\nNAO\n");

    return 0;
}

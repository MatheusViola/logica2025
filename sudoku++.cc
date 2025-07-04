#include <stdio.h>

#define SIZE 9
#define MAX_NUM 10

int checkSudoku(int grid[SIZE][SIZE]) {
    int seen[MAX_NUM + 1];

    for (int i = 0; i < SIZE; i++) {
        for (int k = 1; k <= MAX_NUM; k++) seen[k] = 0;
        for (int j = 0; j < SIZE; j++) {
            int num = grid[i][j];
            if (num < 1 || num > MAX_NUM || seen[num]) return 0;
            seen[num] = 1;
        }
    }

    for (int j = 0; j < SIZE; j++) {
        for (int k = 1; k <= MAX_NUM; k++) seen[k] = 0;
        for (int i = 0; i < SIZE; i++) {
            int num = grid[i][j];
            if (num < 1 || num > MAX_NUM || seen[num]) return 0;
            seen[num] = 1;
        }
    }

    for (int i = 0; i < SIZE; i += 3) {
        for (int j = 0; j < SIZE; j += 3) {
            for (int k = 1; k <= MAX_NUM; k++) seen[k] = 0;
            for (int k2 = 0; k2 < 3; k2++)
                for (int l = 0; l < 3; l++) {
                    int num = grid[i + k2][j + l];
                    if (num < 1 || num > MAX_NUM || seen[num]) return 0;
                    seen[num] = 1;
                }
        }
    }

    return 1;
}

int main() {
    int grid[SIZE][SIZE];

    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            scanf("%d", &grid[i][j]);

    if (checkSudoku(grid))
        printf("Instancia 1\nSIM\n");
    else
        printf("Instancia 1\nNAO\n");

    return 0;
}

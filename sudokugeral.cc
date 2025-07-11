#include <stdio.h>

#define SIZE 9

int isUnique(char values[SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        if (values[i] == '.') continue;
        for (int j = i + 1; j < SIZE; j++) {
            if (values[i] == values[j]) return 0;
        }
    }
    return 1;
}

int main() {
    char grid[SIZE][SIZE], values[SIZE];

    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            scanf(" %c", &grid[i][j]);

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++)
            values[j] = grid[i][j];
        if (!isUnique(values)) {
            printf("Instancia 1\nNAO\n");
            return 0;
        }
    }

    for (int j = 0; j < SIZE; j++) {
        for (int i = 0; i < SIZE; i++)
            values[i] = grid[i][j];
        if (!isUnique(values)) {
            printf("Instancia 1\nNAO\n");
            return 0;
        }
    }

    for (int i = 0; i < SIZE; i += 3)
        for (int j = 0; j < SIZE; j += 3) {
            int idx = 0;
            for (int k = 0; k < 3; k++)
                for (int l = 0; l < 3; l++)
                    values[idx++] = grid[i + k][j + l];
            if (!isUnique(values)) {
                printf("Instancia 1\nNAO\n");
                return 0;
            }
        }

    printf("Instancia 1\nSIM\n");
    return 0;
}

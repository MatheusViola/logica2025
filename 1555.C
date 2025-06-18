#include <stdio.h>
#include <math.h>

int main() {
    int N, x, y;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d %d", &x, &y);
        long long r = (long long)pow(3 * x, 2) + (long long)pow(y, 2);
        long long b = 2LL * (long long)pow(x, 2) + (long long)pow(5 * y, 2);
        long long c = -100LL * x + (long long)pow(y, 3);

        if (r > b && r > c) {
            printf("Rafael ganhou\n");
        } else if (b > r && b > c) {
            printf("Beto ganhou\n");
        } else {
            printf("Carlos ganhou\n");
        }
    }

    return 0;
}

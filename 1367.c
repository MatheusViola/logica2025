#include <stdio.h>
#include <string.h>

#define MAX 26

int main() {
    int N;

    while (scanf("%d", &N) && N != 0) {
        int tempoTotal = 0, problemasResolvidos = 0;
        int resolvido[MAX] = {0};
        int penalidade[MAX] = {0};

        for (int i = 0; i < N; ++i) {
            char problema;
            int tempo;
            char resultado[10];

            scanf(" %c %d %s", &problema, &tempo, resultado);
            int idx = problema - 'A';

            if (resolvido[idx]) continue;

            if (strcmp(resultado, "correct") == 0) {
                resolvido[idx] = 1;
                tempoTotal += tempo + penalidade[idx];
                problemasResolvidos++;
            } else {
                penalidade[idx] += 20;
            }
        }

        printf("%d %d\n", problemasResolvidos, tempoTotal);
    }

    return 0;
}

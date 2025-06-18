#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    int N;
    scanf("%d\n", &N);

    for (int linha = 0; linha < N; linha++) {
        char input[1001], passo1[1001], passo2[1001];
        fgets(input, 1001, stdin);

        int len = strlen(input);
        if (input[len - 1] == '\n') {
            input[len - 1] = '\0';
            len--;
        }

        for (int i = 0; i < len; i++) {
            if (isalpha(input[i]))
                passo1[i] = input[i] + 3;
            else
                passo1[i] = input[i];
        }
        passo1[len] = '\0';

        for (int i = 0; i < len; i++) {
            passo2[i] = passo1[len - 1 - i];
        }
        passo2[len] = '\0';

        for (int i = len / 2; i < len; i++) {
            passo2[i] = passo2[i] - 1;
        }

        printf("%s\n", passo2);
    }

    return 0;
}

#include <stdio.h>
#include <string.h>

int main() {
    int N;
    scanf("%d\n", &N);

    for (int i = 0; i < N; i++) {
        char s[51];
        fgets(s, sizeof(s), stdin);
        int len = strlen(s);
        if (s[len-1] == '\n') s[len-1] = '\0';

        int k;
        scanf("%d\n", &k);

        for (int j = 0; s[j] != '\0'; j++) {
            char c = s[j];
            c = (c - 'A' - k + 26) % 26 + 'A';
            s[j] = c;
        }
        printf("%s\n", s);
    }
    return 0;
}

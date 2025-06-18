#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    int N;
    scanf("%d\n", &N);

    while (N--) {
        char line[201];
        fgets(line, sizeof(line), stdin);

        int freq[26] = {0};
        int max_freq = 0;

        for (int i = 0; line[i] != '\0'; i++) {
            if (isalpha(line[i])) {
                int idx = tolower(line[i]) - 'a';
                freq[idx]++;
                if (freq[idx] > max_freq) max_freq = freq[idx];
            }
        }

        for (int i = 0; i < 26; i++) {
            if (freq[i] == max_freq) {
                printf("%c", 'a' + i);
            }
        }
        printf("\n");
    }

    return 0;
}

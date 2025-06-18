#include <stdio.h>
#include <string.h>

void decimal_to_binary(const char *dec, char *bin) {
    char temp[3500];
    strcpy(temp, dec);
    int len = strlen(temp);
    int pos = 0;
    bin[0] = '\0';

    while (len > 0) {
        int carry = 0;
        int new_len = 0;
        for (int i = 0; i < len; i++) {
            int digit = temp[i] - '0' + carry * 10;
            int q = digit / 2;
            carry = digit % 2;
            if (new_len > 0 || q > 0) {
                temp[new_len++] = q + '0';
            }
        }
        len = new_len;
        
        bin[pos++] = carry + '0';
    }
    bin[pos] = '\0';

    for (int i = 0; i < pos / 2; i++) {
        char c = bin[i];
        bin[i] = bin[pos - 1 - i];
        bin[pos - 1 - i] = c;
    }
}

int count_ones(const char *bin) {
    int count = 0;
    for (int i = 0; bin[i] != '\0'; i++) {
        if (bin[i] == '1') count++;
    }
    return count;
}

int main() {
    int T;
    scanf("%d\n", &T);

    char dec[3500];
    char bin[35000];

    for (int i = 0; i < T; i++) {
        fgets(dec, sizeof(dec), stdin);
        int len = strlen(dec);
        if (dec[len - 1] == '\n') dec[len - 1] = '\0';

        decimal_to_binary(dec, bin);
        printf("%d\n", count_ones(bin));
    }

    return 0;
}

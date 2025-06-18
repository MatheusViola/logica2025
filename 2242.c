#include <stdio.h>
#include <string.h>

int main() {
    char s[51];
    scanf("%s", s);

    char vowels[51];
    int k = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
            vowels[k++] = s[i];
        }
    }
    vowels[k] = '\0';

    int is_palindrome = 1;
    for (int i = 0; i < k / 2; i++) {
        if (vowels[i] != vowels[k - 1 - i]) {
            is_palindrome = 0;
            break;
        }
    }

    printf("%c\n", is_palindrome ? 'S' : 'N');

    return 0;
}

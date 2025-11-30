#include <stdio.h>
#include <string.h>

int isPalindrome(char word[]) {
    int len = strlen(word);
    for (int i = 0; i < len / 2; i++) {
        if (word[i] != word[len - i - 1])
            return 0;
    }
    return 1;
}

int main() {
    int n;
    printf("Enter number of words: ");
    scanf("%d", &n);

    char words[n][50];

    for (int i = 0; i < n; i++) {
        printf("Enter word %d: ", i + 1);
        scanf("%s", words[i]);
    }

    printf("\n===== Palindrome Results =====\n");
    for (int i = 0; i < n; i++) {
        if (isPalindrome(words[i]))
            printf("%s -----> Palindrome\n", words[i]);
        else
            printf("%s -----> Not Palindrome\n", words[i]);
    }

    return 0;
}


#include <stdio.h>
#include <ctype.h>

int countVowels(char str[], int i) {
    if (str[i] == '\0') return 0;
    char ch = tolower(str[i]);
    if (ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')
        return 1 + countVowels(str, i+1);
    return countVowels(str, i+1);
}

int main() {
    char str[100];
    printf("Enter a string: ");
    gets(str);
    printf("Vowel Count: %d", countVowels(str, 0));
    return 0;
}


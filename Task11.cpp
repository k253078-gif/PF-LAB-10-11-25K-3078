#include <stdio.h>
#include <string.h>

int main() {
    char words[5][20] = {"apple", "banana", "mango", "grape", "orange"};
    char search[20];
    int found = 0, index ;

    printf("Enter a word to search: ");
    scanf("%s", search);

    for (int i = 0; i < 5; i++) {
        if (strcmp(words[i], search) == 0) {
            found = 1;
            index=i;
            break;
        }
    }

    if (found)
        printf("Found at index %d \n",index);
    else
        printf("Not Found\n");
    return 0;
}


#include <stdio.h>
#include <ctype.h>

int main() {
    FILE *fp;
    char ch;
    int chars = 0, words = 0, lines = 0;
    int inWord = 0;

    fp = fopen("text.txt", "w");
    if (!fp) {
        printf("Error creating file!\n");
        return 0;
    }

    fprintf(fp, "Hello world!\nThis is a File");
    fclose(fp);

    printf("File 'text.txt' created successfully.\n");

  
    fp = fopen("text.txt", "r");
    if (!fp) {
        printf("File not found!\n");
        return 0;
    }

    while ((ch = fgetc(fp)) != EOF) {
        chars++;

        if (ch == '\n')
            lines++;

        if (isspace(ch))
            inWord = 0;
        else if (!inWord) {
            inWord = 1;
            words++;
        }
    }

    fclose(fp);

    printf("\n===== File Analysis =====\n");
    printf("Characters: %d\n", chars);
    printf("Words: %d\n", words);
    printf("Lines: %d\n", lines);

    return 0;
}


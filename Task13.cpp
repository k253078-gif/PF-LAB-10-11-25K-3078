#include <stdio.h>

int main() {
    FILE *fp = fopen("text.txt", "w");
    if (!fp) {
        printf("Error opening file!");
        return 0;
    }
    fclose(fp);
    printf("Contents deleted successfully.\n");

    fp = fopen("data.txt", "r");
    if (fgetc(fp) == EOF)
        printf("File is empty.\n");
    fclose(fp);
    return 0;
}


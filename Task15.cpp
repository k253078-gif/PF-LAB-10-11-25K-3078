#include <stdio.h>

int main() {
    FILE *f1, *f2, *fout;
    char ch;

    f1 = fopen("file1.txt", "w");
    if (!f1) {
        printf("Error creating file1.txt\n");
        return 1;
    }
    fprintf(f1, "This is the content of file1.txt.\nLine 2 of file1.\n");
    fclose(f1);

    f2 = fopen("file2.txt", "w");
    if (!f2) {
        printf("Error creating file2.txt\n");
        return 1;
    }
    fprintf(f2, "This is the content of file2.txt.\nLine 2 of file2.\n");
    fclose(f2);

    f1 = fopen("file1.txt", "r");
    f2 = fopen("file2.txt", "r");
    fout = fopen("merged.txt", "w");

    if (!f1 || !f2 || !fout) {
        printf("Error opening files for merging\n");
        if(f1) fclose(f1);
        if(f2) fclose(f2);
        if(fout) fclose(fout);
        return 1;
    }

    while ((ch = fgetc(f1)) != EOF)
        fputc(ch, fout);

    while ((ch = fgetc(f2)) != EOF)
        fputc(ch, fout);

    fclose(f1);
    fclose(f2);
    fclose(fout);

    printf("Files created and merged successfully into merged.txt\n");

    return 0;
}


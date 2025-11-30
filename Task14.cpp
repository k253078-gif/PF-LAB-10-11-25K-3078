#include <stdio.h>
#include <time.h>

int main() {
    FILE *fp = fopen("log.txt", "a");
    if (!fp) {
        printf("Error opening file!\n");
        return 0;
    }

    time_t t = time(NULL);
    struct tm *tm_info = localtime(&t);

    fprintf(fp, "Program executed at: %04d-%02d-%02d %02d:%02d:%02d\n",
            tm_info->tm_year + 1900,
            tm_info->tm_mon + 1,
            tm_info->tm_mday,
            tm_info->tm_hour,
            tm_info->tm_min,
            tm_info->tm_sec);

    fclose(fp);

    printf("Execution time logged successfully in log.txt\n");
    return 0;
}


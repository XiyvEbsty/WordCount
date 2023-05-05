#include <stdio.h>

int main()
{
    FILE *fp;
    char ch;
    int count = 0;

    fp = fopen("hamlet.txt", "r");

    if (fp == NULL) {
        printf("File does not exist.\n");
        return 0;
    }

    while ((ch = fgetc(fp)) != EOF) {
        count++;
    }

    fclose(fp);

    printf("Number of characters: %d\n", count);

    return 0;



}


#include <stdio.h>

int main(int argc, char *argv[]) {
    char *filename = "text.txt";
    char *parameter = "-c";
    int count = 0, word_count = 0, prev_space = 1;
    FILE *fp;

    if (argc > 1) {
        parameter = argv[1];
        if (argc > 2) {
            filename = argv[2];
        }
    }

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    int c;
    while ((c = fgetc(fp)) != EOF) {
        count++;
        if (c == ' ' || c == '\n' || c == '\t') {
            prev_space = 1;
        } else if (prev_space) {
            word_count++;
            prev_space = 0;
        }
    }

    fclose(fp);

    if (parameter[1] == 'c') {
        printf("Character count: %d\n", count);
    } else if (parameter[1] == 'w') {
        printf("Word count: %d\n", word_count);
    } else {
        printf("Invalid parameter.\n");
        return 1;
    }

    return 0;
}

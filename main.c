#include <stdio.h>
#include <stdlib.h>

#include "main.h"

#define NMAX_WORDS 200
#define DEFAULT_N_CATEGORIES 4

int* n_categories;

int main(int argc, char** argv) {
    if (argc == 1) {
        *n_categories = DEFAULT_N_CATEGORIES;
    } else {
        *n_categories = atoi(argv[1]);
    }
    char *fname = malloc(150*sizeof(char));
    printf("Enter the name of the list file: ");
    scanf("%s", fname);

    FILE *f = open(fname);

    int number;
    char ***wordList = parse(f, &number);

    free(f);
    free(fname);
}

FILE* open(char *fname) {
    FILE *f = fopen(fname, "r");
    if (!f) {
        printf("Error: File not found\n");
        free(fname);
        exit(1);
    }

    return f;
}

char ***parse(FILE* f, int *number) {
    char ***wordList = initList(NMAX_WORDS);

    char charBuff;
    int i = 0, j = 0, k = 0;

    while (fscanf(f, "%c", &charBuff) != EOF) {
        switch (charBuff) {
            case 9:
                j++;
                break;
            case '\n':
                j = 0;
                i++;
                break;
            default:
                wordList[i][j][k] = charBuff;
                k++;
                break;
        }
    }

    return wordList;
}

char ***initList(int n) {
    char ***wordList = malloc(n*sizeof(char**));
    for (int i = 0; i < n; i++) {
        wordList[i] = malloc(*n_categories * sizeof(char*));
        for (int j = 0; j < *n_categories; j++) {
            wordList[i][j] = calloc(50, sizeof(char));
        }
    }

    return wordList;
}
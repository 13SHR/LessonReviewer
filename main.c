#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

#include "main.h"

#define NMAX_WORDS 200
#define DEFAULT_N_CATEGORIES 4

int n_categories;

int main(int argc, char** argv) {
    // Parse input that indicates the number of inputs per line
    if (argc == 1) {
        n_categories = DEFAULT_N_CATEGORIES;
    } else {
        n_categories = atoi(argv[1]);
    }

    // Open the file entered  by the user
    char *fname = malloc(150*sizeof(char));
    printf("Enter the name of the list file: ");
    scanf("%s", fname);
    FILE *f = open(fname);
    free(fname);

    int number = 1;
    char ***wordList = parse(f, &number);

    loop(wordList, number);

    freeList(wordList);
    fclose(f);
}

FILE* open(char *fname) {
    FILE *f = fopen(fname, "r");
    if (!f) {
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
                k = 0;
                j++;
                break;
            case '\n':
                j = 0;
                k = 0;
                i++;
                (*number)++;
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
        wordList[i] = malloc(n_categories * sizeof(char*));
        for (int j = 0; j < n_categories; j++) {
            wordList[i][j] = calloc(50, sizeof(char));
        }
    }

    return wordList;
}

void freeList(char*** list) {
    for (int i = 0; i < NMAX_WORDS; i++) {
        for (int j = 0; j < n_categories; j++) {
            free(list[i][j]);
        }
        free(list[i]);
    }
    
    free(list);

    return;
}

void loop(char*** wordList, int number) {
    srand(time(NULL));
    int count = 1;
    int n;
    char strBuff[200] = "";

    bool *success = calloc(number, sizeof(bool));
    while (count <= number) {
        strBuff[0] = 0;
        n = rand() % number;

        if (!success[n]) {
            printf("(%d/%d) ", count, number);
            printf("%s: ", wordList[n][rand() % n_categories]);
            bool good = true;
            for (int i = 0; i < n_categories; i++) {
                scanf("%s", strBuff);
                if (strcmp(wordList[n][i], strBuff)) {
                    good = false;
                    strBuff[0] = 0;
                    for (int j = 0; j < n_categories; j++) {
                        strcat(strcat(strBuff, wordList[n][j]), "\x9");
                    }
                    printf("Wrong! It was \x9%s\n", strBuff);
                    i = n_categories;
                }
            }
            if (good) {
                success[n] = true;
                count++;
            }
        }
    }

    printf("Well done! You did all the lesson!\nCome back later \e[31m\e[107m<3\e[m\n");

    return;
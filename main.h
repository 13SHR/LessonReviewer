FILE *open(char *fname);
char ***parse(FILE *f, int *number);
char ***initList(int n);
void freeList(char ***list);
void loop(char ***wordList, int number);
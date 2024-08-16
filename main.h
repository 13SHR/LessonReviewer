FILE *open(char *fname);
char ***parse(FILE *f, int *number);
char ***initList(int n);
void freeList(char ***list);
void loop(char ***wordList, int number);
void getLine(char *line, unsigned *size);
bool checkAnswer(char *answer, char *solution, char ***wordList, int lineId);
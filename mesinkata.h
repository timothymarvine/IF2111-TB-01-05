#ifndef MESINKATA_H
#define MESINKATA_H

#include "boolean.h"
#include "mesinkarakter.h"

#define NMax 50
#define BLANK ' '

typedef struct {
    char TabWord[NMax];
    int Length;
} Word;

extern Word currentWord;
extern boolean EndWord;

void STARTWORD();
void ADVWORD();
void CopyWord();
boolean WordCompareString(Word kata, char *string);
void WordToString(Word kata, char *string);
void PrintKata(Word kata);

#endif

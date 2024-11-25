#include "mesinkata.h"
#include <stdio.h>

Word currentWord;
boolean EndWord;

void STARTWORD() {
    START();
    IgnoreBlanks();
    if (currentChar == MARK) {
        EndWord = true;
    } else {
        EndWord = false;
        CopyWord();
    }
}

void ADVWORD() {
    IgnoreBlanks();
    if (currentChar == MARK) {
        EndWord = true;
    } else {
        CopyWord();
    }
}

void CopyWord() {
    int i = 0;
    while ((i < NMax) && (currentChar != BLANK) && (currentChar != MARK)) {
        currentWord.TabWord[i++] = currentChar;
        ADV();
    }
    currentWord.Length = i;
}

boolean WordCompareString(Word kata, char *string) {
    int i = 0;
    while (i < kata.Length && string[i] != '\0') {
        if (kata.TabWord[i] != string[i]) {
            return false;
        }
        i++;
    }
    return i == kata.Length && string[i] == '\0';
}

void WordToString(Word kata, char *string) {
    for (int i = 0; i < kata.Length; i++) {
        string[i] = kata.TabWord[i];
    }
    string[kata.Length] = '\0';
}

void PrintKata(Word kata) {
    for (int i = 0; i < kata.Length; i++) {
        printf("%c", kata.TabWord[i]);
    }
}

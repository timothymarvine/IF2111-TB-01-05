/* Definisi Mesin Kata: Model Akuisisi Versi I */

#ifndef __MESINKATA_H__
#define __MESINKATA_H__

#include "..\..\boolean.h"
#include "..\mesinkarakter\mesinkarakter.h"
#include "..\kustom\datatype.h"

#define NMax 50
#define BLANK ' '
#define NEWLINE '\n'
#define MAX_LEN 100

typedef struct
{
   char TabWord[NMax]; /* container penyimpan kata, indeks yang dipakai [0..NMax-1] */
   int Length;
} Word;

//[a,k,u] 3 -> "aku"

/* State Mesin Kata */
extern boolean EndWord;
extern Word currentWord;

void IgnoreBlanks();
/* Mengabaikan satu atau beberapa BLANK dan/atau ENTER (NEWLINE)
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */

// void IgnoreBlanks2();
/* Mengabaikan beberapa BLANK */

void STARTWORD();
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */

void STARTWORDFILE(char *FileName);
/* Mengakses pita dengan satu word adalah satu kalimat (mengabaikan BLANK)
   I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi dari file,
          currentChar karakter pertama sesudah karakter terakhir kata */

void STARTSENTENCE();
/* Mengakses pita dengan satu word adalah satu kata yang sebenarnya */

void STARTENTER();
/* Mesin menerima inputan enter, state program berganti */

void ADVWORD();
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */

void ADVSENTENCE();
/* Akuisisi kalimat menggunakan prosedur CopySentence */

void CopyWord();
/* Mengakuisisi kata, kata merupakan seluruh input (bisa merupakan kalimat), menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

void CopySentence();
/* Mengakuisisi kata satu persatu */ 

int Strlen(const char *s);
/* Mengembalikan panjang string s */

void WordToString(Word Kata, char *s);
/* Proses : Menerima kata dalam bentuk Word lalu mengubahnya ke bentuk string
   I.S. : Word terdefinisi
   F.S. : terbentuk sebuah string s yang berisi char dari currentWord */

int stringToInteger(char *str);

boolean WordCompareString(Word Kata, char *s);
/* Proses : Membandingkan kata dengan string, menghasilkan true jika sama 
   I.S. : Word terdefinisi, string juga terdefinisi
   F.S. : menghasilkan true jika kata sama dengan ripresentasinya pada string input */

boolean WordCompare(Word input1, Word input2);
/* Proses : Membandingkan kata dengan kata, menghasilkan true jika kata sama 
   I.S. : Word terdefinisi
   F.S. : menghasilkan true jika kedua kata sama, false jika tidak */

boolean WordCompareKapital(Word input1, Word input2);
/* Proses : Membandingkan kata dengan kata, menghasilkan true jika kata sama, 
   kata yg sama adalah tidak dibedakan kapital dan tidaknya
   I.S. : Word terdefinisi
   F.S. : menghasilkan true jika kedua kata sama, false jika tidak */

void PrintKata(Word Kata);
/* Proses : Menuliskan tipe bentukan kata ke layar
   I.S. : Word terdefinisi
   F.S. : kata yang disimpan dalam Word Kata tertulis di layar */

boolean isWordEqual(const char *stringInput, char sample[MAX_LEN]);

boolean strCmpr(char *a, char *b);

void strCopy(Produk dest, Produk src);

boolean isSave(const char *command);

void SaveInterpreter(const char *command, Word *filename);

int WordToInt(Word w);

void WordToCharArray(Word Kata, char *arr);

int manual_strcmp(char *str1, char *str2);

int isCart(Word kata);

int isHistory(Word kata);

int isWl(Word kata);

void oneWordCmd(Word kata, char* perintah, int *wordIdx);

void twoWordCmd(Word kata, char* perintah, int *wordIdx);

void dirReader(Word kata, char* dir, int *wordIdx);

void itemReader(Word kata, char* barang, int *wordIdx);

void numReader(Word kata, int *res, int *wordIdx);

#endif
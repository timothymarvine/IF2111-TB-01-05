#include <stdio.h>
#include "mesinkata.h"

boolean EndWord;
Word currentWord;

void IgnoreBlanks(){
    while ((currentChar==BLANK || currentChar==NEWLINE) && currentChar!=MARK){
        ADV();
    }
}
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */

// void IgnoreBlanks2(){
//     while (currentChar==BLANK && currentChar!=MARK){
//         ADV();
//     }
// }
// /* Mengabaikan beberapa BLANK */

void STARTWORD(){
    START();
    if (pita != NULL){
        IgnoreBlanks();
        if (currentChar==MARK){
            EndWord=true;
        } else {
            EndWord=false;
            CopyWord();
        }
    }
}
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */

void STARTSENTENCE(){
    START();
    if (pita != NULL){
        IgnoreBlanks();
        if (currentChar==MARK){
            EndWord=true;
        } else {
            EndWord=false;
            CopySentence();
        }
    }
}
/* Mengakses pita dengan satu word adalah satu kata yang sebenarnya */

void STARTWORDFILE(char *FileName){
    STARTFILE(FileName);
    if (pita != NULL){
        IgnoreBlanks();
        if (currentChar==MARK){
            EndWord=true;
        } else {
            EndWord=false;
            CopySentence();
        }
    }
}
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi dari file,
          currentChar karakter pertama sesudah karakter terakhir kata */

void STARTENTER(){
    START();
    if (currentChar=='\n'){
        EndWord=true;
    } else {
        printf("\nTekan <ENTER> "); STARTENTER();
    }
}
/* Mesin menerima inputan enter, state program berganti */

void ADVWORD(){
    IgnoreBlanks();
    if (currentChar==MARK){
        EndWord=true;
    } else{
        CopyWord();
    }
}
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */

void ADVSENTENCE(){
    IgnoreBlanks();
    if (currentChar==MARK){
        EndWord=true;
    } else{
        CopySentence();
    }
}
/* Digunakan pada STARTWORD2 */

int Strlen(const char *s){
    int i = 0;
    while (s[i]!='\0'){
        i++;
    } return i;
}
/* Mengembalikan panjang string s */

void CopyWord(){
    int i = 0;
    while (currentChar!=NEWLINE && currentChar!=BLANK){
        if (i<NMax){
            currentWord.TabWord[i]=currentChar;
        }
        ADV(); i++;
    }
    if (i<NMax) {
        currentWord.Length=i;
    } else {currentWord.Length=NMax;}
}
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

void CopySentence(){
    int i = 0;
    while (currentChar!=NEWLINE){
        if (i<NMax){
            currentWord.TabWord[i]=currentChar;
        }
        ADV(); i++;
    }
    if (i<NMax) {
        currentWord.Length=i;
    } else {currentWord.Length=NMax;}
}
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

void WordToString(Word Kata, char *s){
    for (int i = 0; i<Kata.Length; i++){
        s[i]=Kata.TabWord[i];
    }
    for (int i = Kata.Length; i < Strlen(s); i++) 
    {
        if (s[i] != '\0') {
            s[i] = '\0';
        }
    }
}
int stringToInteger(char str[]) 
{
    int result = 0;     // Variabel untuk menyimpan hasil konversi
    int i = 0;          // Indeks untuk iterasi string
    int sign = 1;       // Penanda untuk angka negatif

    // Periksa jika angka memiliki tanda negatif
    if (str[0] == '-') {
        sign = -1;  // Tandai sebagai negatif
        i++;        // Mulai iterasi dari karakter berikutnya
    }

    // Iterasi setiap karakter dalam string
    while (str[i] != '\0') {
        // Jika karakter bukan digit, return error
        if (str[i] < '0' || str[i] > '9') {
            printf("Error: String tidak valid untuk konversi\n");
            return 0;
        }

        // Konversi karakter ke angka dan tambahkan ke hasil
        result = result * 10 + (str[i] - '0');
        i++;
    }

    // Kalikan hasil dengan tanda (positif/negatif)
    return result * sign;
}
/* Proses : Menerima kata dalam bentuk Word lalu mengubahnya ke bentuk string
   I.S. : currentWord terdefinisi
   F.S. : terbentuk sebuah string s yang berisi char dari currentWord*/

boolean WordCompareString(Word Kata, char *s){
    boolean found = true;
    int i = 0;
    while (i<Kata.Length && found){
        if (Kata.TabWord[i]!=s[i]){
            found = false;
        }
        else {
            i++;
        }
    } return found;
}
/* Proses : Membandingkan kata dengan string, menghasilkan true jika sama 
   I.S. : Word terdefinisi, string juga terdefinisi
   F.S. : menghasilkan true jika kata sama dengan ripresentasinya pada string input */

boolean WordCompare(Word input1, Word input2){
    if (input1.Length!=input2.Length){
        return false;
    } else {
        boolean found = true;
        int i = 0;
        while (i<input1.Length && found){
            if (input1.TabWord[i]!=input2.TabWord[i]){
                found = false;
            }
            else {
                i++;
            }
        } return found;
    }
}
/* Proses : Membandingkan kata dengan kata, menghasilkan true jika kata sama 
   I.S. : Word terdefinisi
   F.S. : menghasilkan true jika kedua kata sama, false jika tidak */

boolean WordCompareKapital(Word input1, Word input2){
    if (input1.Length!=input2.Length){
        return false;
    } else {
        boolean found = true;
        int i = 0;
        while (i<input1.Length && found){
            if (input1.TabWord[i]!=input2.TabWord[i] && input1.TabWord[i]!=input2.TabWord[i]-32 && input1.TabWord[i]!=input2.TabWord[i]+32){
                found = false;
            }
            else {
                i++;
            }
        } return found;
    }
}
/* Proses : Membandingkan kata dengan kata, menghasilkan true jika kata sama, 
   kata yg sama adalah tidak dibedakan kapital dan tidaknya
   I.S. : Word terdefinisi
   F.S. : menghasilkan true jika kedua kata sama, false jika tidak */

void PrintKata(Word Kata){
    for (int i = 0; i<Kata.Length; i++){
        printf("%c", Kata.TabWord[i]);
    }
}
/* Proses : Menuliskan tipe bentukan kata ke layar
   I.S. : Word terdefinisi
   F.S. : kata yang disimpan dalam Word Kata tertulis di layar */

boolean isWordEqual(const char *stringInput, char sample[MAX_LEN]) {
    int i;

    // Periksa apakah panjang currentWord sama dengan panjang stringInput
    if (Strlen(sample) != Strlen(stringInput)) {
        return false; // Panjang berbeda, langsung return false
    }

    // Bandingkan karakter satu per satu
    for (i = 0; i < Strlen(sample); i++) {
        if (sample[i] != stringInput[i]) {
            return false; // Jika ada karakter berbeda, return false
        }
    }

    return true; // Semua karakter sama
}

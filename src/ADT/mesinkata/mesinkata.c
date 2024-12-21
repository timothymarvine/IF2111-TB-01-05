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
    currentWord.Length = 0;
    for(int i = 0; i < NMax; i++){
        currentWord.TabWord[i] = '\0';
    }
    if (pita != NULL){
        IgnoreBlanks();
        if (currentChar==MARK || currentChar==NEWLINE){
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
    currentWord.Length = 0;
    for(int i = 0; i < NMax; i++){
        currentWord.TabWord[i] = '\0';
    }
    if (pita != NULL){
        IgnoreBlanks();
        if (currentChar==MARK || currentChar==NEWLINE){
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
    
    s[Kata.Length] = '\0';
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

boolean strCmpr(char *a, char *b) {
    while (*a && *b) {
        if (*a++ != *b++) return false;
    }
    return *a == '\0' && *b == '\0';
}

void strCopy(Produk dest, Produk src){
	for(int i = 0; i < 50; i++){
		if(src[i] == '\0'){
			dest[i] = '\0';
			break;
		}
		dest[i] = src[i];
	}
}

boolean isSave(const char *command){
    char save[4] = "SAVE"; int i = 0;
    while(i < 4){
        if(command[i] != save[i]){
            return false;
        }
         i++;
    }
    return true;
}

void SaveInterpreter(const char *command, Word *filename){
    int i = 5;
    for(int j = 0; j < MAX_LEN; j++){
        if(command[i] == '\0') break;
        filename->TabWord[j] = command[i];
        i++; filename->Length++;
    }
    // filename.Length--;
}

int WordToInt(Word w) {
    int result = 0;  // Hasil konversi
    int i;

    // Loop melalui setiap karakter dalam Word
    for (i = 0; i < w.Length; i++) {
        // Pastikan karakter valid (angka 0-9)
        if (w.TabWord[i] >= '0' && w.TabWord[i] <= '9') {
            result = result * 10 + (w.TabWord[i] - '0');
        } else {
            // Jika ada karakter non-angka, keluarkan error
            printf("Error: Word contains non-numeric character.\n");
            return -1; // Nilai error
        }
    }

    return result;
}

void WordToCharArray(Word Kata, char *arr) {
    for (int i = 0; i < Kata.Length; i++) {
        arr[i] = Kata.TabWord[i];
    }
    arr[Kata.Length] = '\0'; // Tambahkan null-terminator
}

/* buat bandingin string*/
int manual_strcmp(char *str1, char *str2) {
    while (*str1 && *str2) {
        if (*str1 != *str2) {
            return *str1 - *str2;
        }
        str1++;
        str2++;
    }
    return *str1 - *str2;
}

int isCart(Word kata){
    int a = 0; char cart[4];
    for(int b = 0; b < 4; b++){
        cart[b] = kata.TabWord[b]; 
    }
    if(!strCmpr(cart, "CART")){
        return 0;
    }

    int i = 5, j = 0; char next[10];
    for(i; i != ' ' && i != '\0' && i != '\n'; i++){
        next[j] = kata.TabWord[i];
        j++;
    }
    if(strCmpr(next, "ADD")){
        return 1;
    } else if(strCmpr(next, "REMOVE")){
        return 2;
    } else if(strCmpr(next, "SHOW")){
        return 3;
    } else if(strCmpr(next, "PAY")){
        return 4;
    } else {
        return 0;
    }
}

int isHistory(Word kata){
    int i = 0; char history[7];
    for(i; i < 7; i++){
        history[i] = kata.TabWord[i];
    }
    if(!strCmpr(history, "HISTORY")){
        return 0;
    } else {
        return 1;
    }
}

int isWl(Word kata){
    int i = 0; char wl[8];
    for(i; i < 8; i++){
        wl[i] = kata.TabWord[i];
    }
    if(!strCmpr(wl, "WISHLIST")){
        return 0;
    }

    i = 9; char next[10]; int j = 0;
    for(i; i != ' ' && i != '\n' && i != MARK; i++){
        next[j] = kata.TabWord[i];
        j++;
    }
    if(strCmpr(next, "ADD")){
        return 1;
    } else if(strCmpr(next, "SWAP")){
        return 2;
    } else if(strCmpr(next, "REMOVE")){
        return 3;
    } else if(strCmpr(next, "CLEAR")){
        return 4;
    } else if(strCmpr(next, "SHOW")){
        return 5;
    } else {
        return 0;
    }
}

void oneWordCmd(Word kata, char perintah[], int *wordIdx){
    int i = *wordIdx;
    while(kata.TabWord[i] != ' ' && kata.TabWord[i] != '\n'){
        perintah[i] = kata.TabWord[i]; i++;
    }
    perintah[i] = '\0';
    *wordIdx = i + 1;
}

void twoWordCmd(Word kata, char perintah[], int *wordIdx){
    int i = *wordIdx, j = 0;
    while(kata.TabWord[i] != ' ' && kata.TabWord[i] != '\n'){
        perintah[j] = kata.TabWord[i]; i++; j++;
    }
    perintah[j] = '\0';
    *wordIdx = i + 1;
}

void itemReader(Word kata, char barang[], int *wordIdx){
    int i = *wordIdx, j = 0;
    while(kata.TabWord[i] != ' ' && kata.TabWord[i] != '\n'){
        barang[j] = kata.TabWord[i]; i++; j++;
    }
    barang[j] = '\0';
    *wordIdx = i + 1;
}

void numReader(Word kata, int *res, int *wordIdx){
    int i = *wordIdx; *res = 0;
    while(kata.TabWord[i] != ' ' && kata.TabWord[i] != '\n'){
        if(kata.TabWord[i] >= '0' || kata.TabWord[i] <= '9'){
            *res = *res * 10 + (kata.TabWord[i] - '0');
            i++;
        } else {
            printf("Masukkan input angka yang benar.");
            return;
        }
    }
    *wordIdx = i + 1;
}

void dirReader(Word kata, char dir[], int *wordIdx){
    int i = *wordIdx, j = 0;
    while(kata.TabWord[i] != ' ' && kata.TabWord[i] != '\n'){
        dir[j] = kata.TabWord[i]; i++; j++;
    }
    dir[j] = '\0';
    *wordIdx = i + 1;
}

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "boolean.h"
#include "wordl399.h"
#include "mesinkata.h"

#define COST_TO_PLAY 500
#define REWARD 1500
#define WORD_LENGTH 5
#define MAX_ATTEMPTS 5


const char *word_pool[] = {"STEIK", "CISCO", "JAKET", "HUJAN", "LUCKY"};
const int word_pool_size = 5;

// deklarasi fungsi 
int bandingkan_strings (const char *strr1, const char *str2);
void pilih_kata_acak (char *selected_word);
void proses_tebak (const char *guess, const char *target, char *result);
int panjang_string (const char *str);
void display_progress ( char guesses[MAX_ATTEMPTS][WORD_LENGTH*2+1], char *result);
void play_WORDL399(int *uang_asal);
void main_tebak_angka(int *uang_asal);



// Fungsi memilih kata acak
void pilih_kata_acak(char *selected_word) {
    srand(time(NULL));
    int index = rand() % word_pool_size;
    for (int i = 0; i < WORD_LENGTH; i++) {
        selected_word[i] = word_pool[index][i];
    }
    selected_word[WORD_LENGTH] = '\0'; // Null-terminator
}

// Fungsi memproses tebakan
void proses_tebak (const char *guess, const char *target, char *result) {
    bool used[WORD_LENGTH] = {false};

    for (int i = 0; i < WORD_LENGTH; i++) {
        if (guess[i] == target[i]) {
            result[i * 2] = guess[i]; // Huruf dan posisi benar
            result[i * 2 + 1] = ' ';
            used[i] = true;
        
        }
    }

    for (int i = 0; i < WORD_LENGTH; i++) {
        if (guess[i ] != target[i]) {
            bool found = false;
            for (int j = 0; j < WORD_LENGTH; j++) {
                if (!used[j] && guess[i] == target[j]) {
                    result[i*2] = guess[i];
                    result[i * 2 + 1] = '*'; // Huruf benar, posisi salah
                    used[j] = true;
                    found = true;
                    break;
                }
            }
            if (!found){
                result[i*2] = guess[i];
                result[i*2 + 1] = '%';
            }
            
        }
    }

    result[WORD_LENGTH * 2] = '\0'; // Null-terminator
}

// Fungsi bandingkan string
int bandingkan_string(const char *str1, const char *str2) {
    while (*str1 && (*str1 == *str2)) {
        str1++;
        str2++;
    }
    return *(unsigned char *)str1 - *(unsigned char *)str2;
}

// Fungsi mencetak papan
void display_progres (char guesses[MAX_ATTEMPTS][WORD_LENGTH * 2 + 1], int attempts) {
  
    for (int i = 0; i < MAX_ATTEMPTS; i++) {
        if (i < attempts) {
            printf("%s\n", guesses[i]);
        } else {
            for (int j = 0; j < WORD_LENGTH; j++) {
                printf("_ ");
            }
            printf("\n");
        }
    }
    printf("\n");
}




// Permainan Wordl399
void play_wordl399(int *uang_asal) {
    if (*uang_asal < COST_TO_PLAY) {
        printf("Uang Anda tidak cukup untuk memainkan W0RDL399.\n");
        return;
    }

    *uang_asal -= COST_TO_PLAY;
    printf("\nWELCOME TO W0RDL3, YOU HAVE %d CHANCES TO ANSWER BEFORE YOU LOSE!\n\n", MAX_ATTEMPTS);

    char target_word[WORD_LENGTH + 1];
    select_random_word(target_word);

    char guesses[MAX_ATTEMPTS][WORD_LENGTH * 2 + 1] = {0};
    int attempts = 0;
    bool guessed_correctly = false;

    while (attempts < MAX_ATTEMPTS && !guessed_correctly) {
        display_progress(guesses, attempts);

        char guess[WORD_LENGTH + 1];
        printf("Masukan kata tebakan Anda: ");
        scanf("%s", guess);

        if (string_length(guess) != WORD_LENGTH) {
            printf("Kata harus terdiri dari %d huruf. Coba lagi.\n", WORD_LENGTH);
            continue;
        }

        process_guess(guess, target_word, guesses[attempts]);
        printf("Hasil:\n");
        display_progress(guesses, attempts + 1);

        if (compare_strings(guess, target_word) == 0) {
            guessed_correctly = true;
            printf("Selamat, Anda menang!\n");
            printf("+%d rupiah telah ditambahkan ke akun Anda.\n", REWARD);
            *uang_asal += REWARD;
            printf("Uang Anda sekarang: %d\n", *uang_asal);
            return;
        }

        attempts++;
    }

    printf("Maaf, Anda kalah! Kata yang benar adalah: %s\n", target_word);
    printf("Uang Anda tersisa: %d\n", *uang_asal);
}

// Permainan Tebak Angka (contoh sederhana)
void play_tebak_angka(int *uang_asal) {
    printf("Permainan Tebak Angka masih dalam pengembangan.\n");
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "wordl399.h"

#define MAX_ATTEMPTS 6
#define WORD_LENGTH 5
#define COST_TO_PLAY 500
#define REWARD 1500

// Kata acak untuk permainan
const char *word_pool[] = {"STEIK", "CISCO", "JAKET", "HUJAN", "LUCKY"};
const int word_pool_size = 5;

// Fungsi untuk memilih kata acak
void select_random_word(char *selected_word) {
    srand(time(NULL));
    int index = rand() % word_pool_size;
    for (int i = 0; i < WORD_LENGTH; i++) {
        selected_word[i] = word_pool[index][i];
    }
    selected_word[WORD_LENGTH] = '\0';
}

// Proses tebakan pemain
void process_guess(const char *guess, const char *target, char *result) {
    for (int i = 0; i < WORD_LENGTH; i++) {
        if (guess[i] == target[i]) {
            result[i * 2] = guess[i];
            result[i * 2 + 1] = ' '; // Huruf benar dan posisi benar
        } else if (strchr(target, guess[i])) {
            result[i * 2] = guess[i];
            result[i * 2 + 1] = '*'; // Huruf benar tetapi posisi salah
        } else {
            result[i * 2] = guess[i];
            result[i * 2 + 1] = '%'; // Huruf salah
        }
    }
    result[WORD_LENGTH * 2] = '\0';
}

// Permainan Wordl399
void wordl399(int *uang_asal) {
    if (*uang_asal < COST_TO_PLAY) {
        printf("Uang Anda tidak cukup untuk memainkan W0RDL399.\n");
        return;
    }

    *uang_asal -= COST_TO_PLAY; // Kurangi biaya bermain
    printf("Selamat datang di W0RDL399! Anda memiliki %d kesempatan untuk menang!\n", MAX_ATTEMPTS);
    printf("Uang Anda tersisa: %d\n\n", *uang_asal);

    char target_word[WORD_LENGTH + 1];
    select_random_word(target_word);

    int attempts = 0;
    bool guessed_correctly = false;

    char guess[WORD_LENGTH + 1];
    char result[WORD_LENGTH * 2 + 1];

    while (attempts < MAX_ATTEMPTS && !guessed_correctly) {
        printf("Masukkan tebakan Anda (%d huruf): ", WORD_LENGTH);
        scanf("%s", guess);

        // Proses tebakan
        process_guess(guess, target_word, result);

        printf("Hasil: %s\n", result);

        if (strcmp(guess, target_word) == 0) {
            guessed_correctly = true;
            printf("Selamat, Anda menang! %d rupiah telah ditambahkan ke akun Anda.\n", REWARD);
            *uang_asal += REWARD;
            printf("Uang Anda sekarang: %d\n", *uang_asal);
            return;
        }

        attempts++;
        printf("Kesempatan tersisa: %d\n\n", MAX_ATTEMPTS - attempts);
    }

    printf("Maaf, Anda kalah! Kata yang benar adalah: %s\n", target_word);
    printf("Uang Anda tersisa: %d\n", *uang_asal);
}

#ifndef WORDL399_H
#define WORDL399_H


// Konstanta permainan
#define BIAYA_PERMAINAN 500
#define HADIAH 1500
#define PANJANG_KATA 5
#define MAX_PELUANG 6

// Deklarasi fungsi untuk menangani logika permainan
int string_length(const char *str);

// Fungsi untuk memilih kata acak dari kumpulan kata
void pilih_kata_acak(char *kata_terpilih);

// Fungsi untuk memproses tebakan
void proses_tebakan(const char *tebakan, const char *target, char *hasil);

// Fungsi untuk membandingkan dua string
int bandingkan_string(const char *str1, const char *str2);

// Fungsi untuk menampilkan progres permainan
void tampilkan_progress(char tebakan[MAX_PELUANG][PANJANG_KATA * 2 + 1], int peluang);

// Fungsi utama permainan W0RDL399
void WORDL399(int *uang_asal);


#endif
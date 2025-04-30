#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char papan[3][3];
char pemainSekarang;
int modePermainan; 

void inisialisasiPapan() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            papan[i][j] = ' ';
        }
    }
}

void tampilkanPapan() {
    printf("-------------\n");
    for (int i = 0; i < 3; i++) {
        printf("| ");
        for (int j = 0; j < 3; j++) {
            printf("%c | ", papan[i][j]);
        }
        printf("\n");
        printf("-------------\n");
    }
}

int cekMenang() {
    for (int i = 0; i < 3; i++) {
        if (papan[i][0] != ' ' && papan[i][0] == papan[i][1] && papan[i][1] == papan[i][2]) {
            return 1;
        }
        if (papan[0][i] != ' ' && papan[0][i] == papan[1][i] && papan[1][i] == papan[2][i]) {
            return 1;
        }
    }
    if (papan[0][0] != ' ' && papan[0][0] == papan[1][1] && papan[1][1] == papan[2][2]) {
        return 1;
    }
    if (papan[0][2] != ' ' && papan[0][2] == papan[1][1] && papan[1][1] == papan[2][0]) {
        return 1;
    }
    return 0;
}

int cekSeri() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (papan[i][j] == ' ') {
                return 0;
            }
        }
    }
    return 1;
}

void giliranKomputer() {
    int baris, kolom;
    srand(time(NULL));
    while (1) {
        baris = rand() % 3;
        kolom = rand() % 3;
        if (papan[baris][kolom] == ' ') {
            papan[baris][kolom] = 'O';
            printf("Komputer memilih baris %d kolom %d\n", baris + 1, kolom + 1);
            break;
        }
    }
}

void mainMenu() {
    printf("=== TIC TAC TOE ===\n");
    printf("1. Player vs Player\n");
    printf("2. Player vs Komputer\n");
    printf("3. Keluar\n");
    printf("Pilih mode (1-3): ");
    scanf("%d", &modePermainan);
}

int main() {
    int baris, kolom;
    int permainanSelesai;

    do {
        mainMenu();
        if (modePermainan == 3) {
            printf("Terima kasih sudah bermain!\n");
            return 0;
        }
        inisialisasiPapan();
        pemainSekarang = 'X';
        permainanSelesai = 0;

        while (!permainanSelesai) {
            tampilkanPapan();
            if (modePermainan == 2 && pemainSekarang == 'O') {
                giliranKomputer();
            } else {
                printf("Pemain %c, masukkan baris dan kolom (1-3): ", pemainSekarang);
                scanf("%d %d", &baris, &kolom);
                baris--;
                kolom--;
                if (baris < 0 || baris > 2 || kolom < 0 || kolom > 2) {
                    printf("Input tidak valid. Coba lagi.\n");
                    continue;
                }
                if (papan[baris][kolom] != ' ') {
                    printf("Kotak sudah terisi. Coba lagi.\n");
                    continue;
                }
                papan[baris][kolom] = pemainSekarang;
            }

            if (cekMenang()) {
                tampilkanPapan();
                if (modePermainan == 2 && pemainSekarang == 'O') {
                    printf("Komputer menang!\n");
                } else {
                    printf("Pemain %c menang!\n", pemainSekarang);
                }
                permainanSelesai = 1;
            } else if (cekSeri()) {
                tampilkanPapan();
                printf("Permainan seri!\n");
                permainanSelesai = 1;
            } else {
                pemainSekarang = (pemainSekarang == 'X') ? 'O' : 'X';
            }
        }

        printf("Kembali ke menu utama...\n\n");

    } while (1);

    return 0;
}

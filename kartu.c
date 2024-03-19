#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ANGKA_MAX 100 

int nilaiKartu(char krt[]) {
    if (strcmp(krt, "J") == 0) return 11;
    if (strcmp(krt, "Q") == 0) return 12;
    if (strcmp(krt, "K") == 0) return 13;
    return atoi(krt); 
}

int main() {
    int jumlahAngka;
    printf("Masukkan Banyaknya angka: ");
    scanf("%d", &jumlahAngka);

   
    if (jumlahAngka > ANGKA_MAX) {
        printf("Jumlah angka terlalu besar.\n");
        return 1;
    }

    char krt[ANGKA_MAX][3]; 
    for(int i = 0; i < jumlahAngka; i++) {
        scanf("%2s", krt[i]); 
    }

    int pertukaran = 0;

    for(int i = 0; i < jumlahAngka; i++) {
        int angkaTerkecil = i;
        for(int j = i+1; j < jumlahAngka; j++) {
            if(nilaiKartu(krt[j]) < nilaiKartu(krt[angkaTerkecil])) {
                angkaTerkecil = j;
            }
        }

        if (angkaTerkecil != i) {
            char temp[3];
            strcpy(temp, krt[i]);
            strcpy(krt[i], krt[angkaTerkecil]);
            strcpy(krt[angkaTerkecil], temp);
            pertukaran++;

            printf("\nPertukaran %d: ", pertukaran);
            for (int L = 0; L < jumlahAngka; L++) {
                printf("%s ", krt[L]);
            }
        }
    }

    printf("\n\nJumlah langkah pertukaran: %d\n", pertukaran);
    return 0;
}

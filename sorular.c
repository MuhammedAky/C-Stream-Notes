Lab Soruları:

1.Hafta: Girilen N tane sayının içinden en büyük olanı bulup ekrana yazdıran programı yazınız.

#include <stdio.h>

int main() {

    int N;

    printf("Kac sayi girilecek: ");
    scanf("%d", &N);

    int sayilar[N];

    for (int i = 0; i < N; i++) {
        printf("%d. sayiyi giriniz: ", i + 1);
        scanf("%d", &sayilar[i]);
    }

    int max = sayilar[0];

    for (int i = 0; i < N; i++) {
        if (sayilar[i] > max) {
            max = sayilar[i];
        }
    }

    printf("Max: %d", max);


    return 0;
}

2.Hafta: Girilen N tane sayıdan asal olanların -3 katının 5 fazlasını ekrana yazdıran eğer girilen sayı asal değil ise tekrar bir sayi isteyen 
programı yazın.

#include <stdio.h>

int main() {
    int N;

    printf("Kac sayi girilecek: ");
    scanf("%d", &N);

    int sayilar[N];

    for (int i = 0; i < N; i++) {
        printf("%d. sayiyi giriniz: ", i + 1);
        scanf("%d", &sayilar[i]);

        // Sayının asal olup olmadığını kontrol et
        int asal = 1;  // 1: Asal, 0: Asal değil

        for (int j = 2; j * j <= sayilar[i]; j++) {
            if (sayilar[i] % j == 0) {
                asal = 0;  // Asal değil
                break;
            }
        }

        // Sadece asal sayıları işle
        if (asal) {
            printf("Asal sayinin -3 katinin 5 fazlasi: %d\n", (-3 * sayilar[i]) + 5);
        }
    }

    return 0;
}

1.1.Soru: aslında resimler küçük pixellerden oluşurlar ve bu pixeller 0 ile 255 arasında değerler alabilirler. bize bir resim tanımlandığını ve 
bu resimin genişlik değerinin 1024, yükseklik değerinin 768 olduğunu varsayıp bu resimde keskinleştirme işlemi yapılmak isteniyor. keskinleştirme
işlemi ise şöyle yapılacak pixel değerinin 50'den küçük olması durumunda 0'a yani siyaha, 180'den büyük olması durumunda ise 255'e yani beyaza
dönüştürülmesi isteniyor. (resimin tanımlandığını varsayınız.)

#include <stdio.h>

int main() {

    int resim[1024][768];

    for (int i = 0; i < 1024; i++) {
        for (int j = 0; j < 768; j++) {
            if (resim[i][j] < 50) {
                resim[i][j] = 0; // siyah
            } else if (resim[i][j] > 180) {
                resim[i][j] = 255; // beyaz
            }
        }
    }

    return 0;
}

1.2.Soru: bu resimdeki beyaz ve siyah renk pixelleri arasındaki farkı bulan programı yazınız.
fark değerinin pozitif olmasına dikkat ediniz.


#include <stdio.h>
#include <math.>

int main() {

    int resim[1024][768];

    // int beyazlar = 0;
    // int siyahlar = 0;

    int fark = 0;

    for (int i = 0; i < 1024; i++) {
        for (int j = 0; j < 768; j++) {
            if (resim[i][j] == 0) { // siyah pixeller için
                fark++;
                // siyahlar++;
            } else if (resim[i][j] == 255) { // beyaz pixeller için
                fark--;
                // beyazlar++;
            }
        }
    }

    // return siyahlar - beyazlar;
    return fark;

    // return 0;
}
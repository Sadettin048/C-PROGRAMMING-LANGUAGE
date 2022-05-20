/*Sadettin Tilkioğlu*/
//struct yapısında öğrenci kaydında sýarlama ve numaraya,isme,soyisme göre arama yapma
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define len 30

struct ogrenci{
    char ad[len];
    char soyadi[len];
    int ogrenciNo;
};

void siralama_yap(int, struct ogrenci ogr[]);
void arama_yap(int, struct ogrenci ogr[]);
void arama_yap2(int, struct ogrenci ogr[], int);

int main(){

    srand(time(NULL));

    char isimler[][len] = {"Ahmet", "Veli", "Ayse", "Mehmet", "Fatma", "Ekrem", "Samet", "Nur", "Gul", "Cicek"};
    char soyisimler[][len] = { "Turgut", "Kirmizi", "Su", "Yardimsev", "Hosgul", "Temizsev", "Aydogan", "Gunbatimi"};

    printf("Kac tane ogrenci sisteme kayit edilecek: ");
    int ogrenci_sayisi;
    scanf("%d", &ogrenci_sayisi);
    printf("\n");

    struct ogrenci ogr[ogrenci_sayisi];

    int i;
    for (i = 0 ; i < ogrenci_sayisi ; i++) {
        strcpy(ogr[i].ad, isimler[rand () % sizeof isimler / sizeof *isimler]);
        strcpy(ogr[i].soyadi, soyisimler[ rand () % sizeof soyisimler / sizeof *soyisimler]);
        ogr[i].ogrenciNo = rand() % 1000; // ogr[i].ogrenciNo = i + 1;
    }

    int a = 5;
    while(a > 0){
        printf("        MENU                      \n");
        printf("1- Numaraya gore siralama yap.    \n");
        printf("2- Arama yap.                     \n");
        printf("3- Cikis yap.                     \n");
        printf("\n");
        printf("Islem seciniz: ");
        int islem;
        scanf("%d", &islem);

        switch(islem) {
            case 1:
                    siralama_yap(ogrenci_sayisi, ogr);
                    break;
            case 2:
                    arama_yap(ogrenci_sayisi, ogr);
                    break;
            case 3:
                    a = -1;
                    printf("Cikis yapiliyor...\n");
                    break;
            default:
                    printf("Gecersiz islem!\n");
        }
        printf("\n");
    }
    return 0;
}

void siralama_yap(int ogrenci_sayisi, struct ogrenci ogr[]) { // numaraya gore siralama

    int dizi[ogrenci_sayisi];
    int i, j, k;

    for(k = 0; k < ogrenci_sayisi; k++){
        dizi[k] = ogr[k].ogrenciNo;
    }

    for (i = 0 ; i < ogrenci_sayisi - 1 ; i++) {
        if(!(dizi[i] <= dizi[i+1])){
            int temp = dizi [i];
            dizi [i] = dizi [i + 1];
            dizi [i + 1] = temp;
            i = -1;
        }
    }

    for( j = 0 ; j < ogrenci_sayisi ; j++) {
        arama_yap2(ogrenci_sayisi, ogr, dizi[j]);
    }

}

void arama_yap(int ogrenci_sayisi, struct ogrenci ogr[]) {
    printf("Aramak istediginiz kelimeyi giriniz: ");
    char aranilacak_ifade[len];
    scanf("%s", aranilacak_ifade);

    int ogrenciBulunduMu = 0; //false

    int i;
    for(i = 0 ; i < ogrenci_sayisi ; ++i) {
        char temp[len];
        if (strcmp(ogr[i].ad, aranilacak_ifade) == 0 || strcmp(ogr[i].soyadi, aranilacak_ifade) == 0 || strcmp(itoa( ogr[i].ogrenciNo, temp, 10), aranilacak_ifade) == 0) { // temp = "123";

            if(ogrenciBulunduMu == 0) {
                printf("Ogrenci bulundu. \n");
            }
            printf("Ogrenci no: %d \t%s %s \n", ogr[i].ogrenciNo, ogr[i].ad, ogr[i].soyadi);
            ogrenciBulunduMu = 1;
        }
    }

    if (!ogrenciBulunduMu) {
        printf("Aradiginiz ifadede ogrenci bulunamadi. \n");
    }
}

void arama_yap2(int ogrenci_sayisi, struct ogrenci ogr[], int aranilacak_ifade) {

    int i;
    for(i = 0 ; i < ogrenci_sayisi ; ++i) {
        if (ogr[i].ogrenciNo == aranilacak_ifade) {
            printf("Ogrenci no: %d \t%s %s \n", ogr[i].ogrenciNo, ogr[i].ad, ogr[i].soyadi);
        }
    }
}

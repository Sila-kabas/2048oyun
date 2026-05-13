#include "tahta.hpp"
#include <ctime>
#include <cstdlib>
#include <iostream>

Tahta::Tahta(){
    sifirla();
    srand(time(0));

    rastgeleSayiEkle();
    rastgeleSayiEkle();

}

void Tahta::sifirla() {
    skor = 0;
    for(int satir = 0; satir < 4; satir++) {
        for(int sutun = 0; sutun < 4; sutun++) {
            matris[satir][sutun] = 0;
        }
    }
}

void Tahta::rastgeleSayiEkle(){
    int bosKareSayisi=0;
    int sayac=0;
    for(int satir=0; satir<4; satir++) {
        for(int sutun= 0; sutun<4; sutun++) {
           if (matris[satir][sutun]==0){
            bosKareSayisi++;
           }
        }
    }

    if (bosKareSayisi==0){//bos kare yoksa fonk kapat
        return;
    }

    int secilenBosKare= rand()% bosKareSayisi;

    for(int satir=0; satir< 4; satir++) {
        for(int sutun= 0; sutun <4; sutun++) {
            if (matris[satir][sutun] ==0){
                if(sayac==secilenBosKare){//tahtayı tarıyoruz sectigimiz kareyi bulana kadar
                    matris[satir][sutun]=(rand()%75==0)? 4:2;
                }
                sayac++;
            }
        }
    }
}

void Tahta::solaKaydir(){
     for(int satir=0; satir<4; satir++){ //boslukları sola kaydır
        int yazilacakYer=0;
         for(int sutun=0; sutun<4; sutun++){
            if(matris[satir][sutun]!=0){
                int sayi=matris[satir][sutun];
                matris[satir][sutun]=0;
                matris[satir][yazilacakYer]=sayi;
                yazilacakYer++;
            }
         }
 
         for(int sutun=0; sutun<3; sutun++){//yan yana iki kare aynıysa topla ve sola kaydır
            if(matris[satir][sutun]!=0 && matris[satir][sutun]==matris[satir][sutun+1]){
                matris[satir][sutun]=matris[satir][sutun]*2;
                skor+=matris[satir][sutun];
                matris[satir][sutun+1]=0;
            }
         }
          yazilacakYer=0;
            for(int sutun=0; sutun<4; sutun++){
                if(matris[satir][sutun]!=0){
                    int sayi=matris[satir][sutun];
                    matris[satir][sutun]=0;
                    matris[satir][yazilacakYer]=sayi;
                    yazilacakYer++;
                }
            }
         }
    }

    void Tahta::sagaKaydir(){
    for(int satir=0; satir<4; satir++){ //boslukları saga kaydır

        int yazilacakYer=3;
         for(int sutun=3; sutun>=0; sutun--){
            if(matris[satir][sutun]!=0){
                int sayi=matris[satir][sutun];
                matris[satir][sutun]=0;
                matris[satir][yazilacakYer]=sayi;
                yazilacakYer--;
            }
         }
 
         for(int sutun=3; sutun>0; sutun--){//yan yana iki kare aynıysa topla ve saga kaydır
            if(matris[satir][sutun]!=0 && matris[satir][sutun]==matris[satir][sutun-1]){
                matris[satir][sutun]=matris[satir][sutun]*2;
                skor+=matris[satir][sutun];
                matris[satir][sutun-1]=0;
            }
         }
          yazilacakYer=3;
            for(int sutun=3; sutun>=0; sutun--){
                if(matris[satir][sutun]!=0){
                    int sayi=matris[satir][sutun];
                    matris[satir][sutun]=0;
                    matris[satir][yazilacakYer]=sayi;
                    yazilacakYer--;
                }
            }
         }
    }
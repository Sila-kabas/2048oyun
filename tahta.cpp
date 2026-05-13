#include "tahta.hpp"
#include <ctime>
#include <cstdlib>

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
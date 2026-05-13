#ifndef TAHTA_HPP
#define TAHTA_HPP
#include <SFML/Graphics.hpp>

class Tahta{
private:
    int matris[4][4];
    int skor;
    sf:: Font font;
public:
    Tahta();
    void sifirla();
    void rastgeleSayiEkle();
    void solaKaydir();
    void sagaKaydir();
    void asagiKaydir();
    void yukariKaydir();


    int getDeger(int satir, int sutun) {
        return matris[satir][sutun];
    }
};

#endif
#include "oyun.hpp"
#include <string>
#include <iostream>

Oyun::Oyun() : window(sf::VideoMode(700,700), "2048 oyunu"){ //pencere acma
    window.setFramerateLimit(60);
    // Önce bir üst klasörde ara, bulamazsa olduğu klasörde ara
if (!font.loadFromFile("../arial.ttf")) {
    if (!font.loadFromFile("arial.ttf")) {
    }
}
    font.loadFromFile("arial.ttf");
    tahta.sifirla();
    }

    void Oyun::olaylar(){
        sf:: Event event;
        while(window.pollEvent(event)){
            if(event.type==sf::Event::Closed){
                window.close();
            }
 

                if(event.type==sf::Event::KeyPressed){
                    if(event.key.code==sf::Keyboard::Left){
                        tahta.solaKaydir();
                        tahta.rastgeleSayiEkle();

                    }
                    else if(event.key.code==sf::Keyboard::Right){
                        tahta.sagaKaydir();
                        tahta.rastgeleSayiEkle();
                    }
                    else if(event.key.code==sf::Keyboard::Down){
                        tahta.asagiKaydir();
                        tahta.rastgeleSayiEkle();
                    }
                    else if(event.key.code==sf::Keyboard::Up){
                        tahta.yukariKaydir();
                        tahta.rastgeleSayiEkle();
                    }
                if(tahta.oyunBittiMi()){
                    std::cout<<"game over"<<std::endl;
                    bittiMi=true;
                }
            }
        }
    }

 
    //cizdiren fonk
     void Oyun::ciz(){
     window.clear(sf::Color(187, 173, 160)); // arka plan rengi

     for(int satir=0; satir<4; satir++){
       for(int sutun=0; sutun<4; sutun++){
        sf::RectangleShape kare(sf::Vector2f(150, 150)); // her karenin boyutu
        kare.setPosition(sutun * 170 + 25, satir * 170 + 25);   // kareler arası bosluk

         int deger=tahta.matris[satir][sutun];
          sf::Color kareRengi;
          if (deger == 0){
                 kareRengi = sf::Color(205, 193, 180);}
             else if (deger == 2){
                 kareRengi = sf::Color(238, 228, 218);}
             else if (deger == 4) {
                kareRengi = sf::Color(237, 224, 200);}
             else if (deger == 8) {
                kareRengi = sf::Color(242, 177, 121);}
             else if (deger == 16){
                 kareRengi = sf::Color(245, 149, 99);}
             else if (deger == 32) {
                kareRengi = sf::Color(246, 124, 95);}
             else if (deger == 64) {
                kareRengi = sf::Color(246, 94, 59);}
             else if (deger == 128) {
                kareRengi = sf::Color(237, 207, 114);}
             else if (deger == 256) {
                kareRengi = sf::Color(237, 204, 97);}
             else if (deger == 512) {
                kareRengi = sf::Color(237, 200, 80);}
             else if (deger == 1024) {
                kareRengi = sf::Color(237, 197, 63);}
             else if (deger == 2048) {
                kareRengi = sf::Color(237, 194, 46);}
             kare.setFillColor(kareRengi);

        window.draw(kare);

        

          if(tahta.matris[satir][sutun]!=0){
            sf::Text yazi;
            yazi.setFont(font);
            yazi.setString(std::to_string(tahta.matris[satir][sutun]));
            yazi.setCharacterSize(75);
            yazi.setFillColor(sf::Color::Black);
            yazi.setStyle(sf::Text::Bold);
            yazi.setPosition(sutun*170+75, satir*170+40);
            window.draw(yazi);
          }

          
    }
}
    
    if(bittiMi){
        sf::RectangleShape ekran(sf::Vector2f(1200, 1200)); //
          ekran.setFillColor(sf::Color(205, 193, 180));     //
          window.draw(ekran);
 
            sf::Text bitisyazisi;
            bitisyazisi.setFont(font);
            bitisyazisi.setString("game over");
            bitisyazisi.setCharacterSize(75);
            bitisyazisi.setFillColor(sf::Color::Black);
            bitisyazisi.setStyle(sf::Text::Bold);
            bitisyazisi.setPosition(190,200);
            window.draw(bitisyazisi);
    }

    window.display();//cizilenleri ekranda gosterir
}
 
    // Oyunu başlatan burası
void Oyun::calistir(){
    while (window.isOpen()) {
        olaylar();
        ciz();
    }
}
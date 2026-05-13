#include <SFML/Graphics.hpp>
#include "oyun.hpp"
#include <string>
#include <iostream>


Oyun::Oyun() : window(sf::VideoMode(700,700), "2048 Oyunu"){ //pencere olusturdum
    window.setFramerateLimit(60);
}

void Oyun::olaylar() {
    while (window.isOpen()) {
        sf::Event olay;
        while (window.pollEvent(olay)) {// kapatma tuşuna basılırsa
            if (olay.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color(187, 173, 160)); // arka plan rengi 

         for(int satir=0; satir<4; satir++){
       for(int sutun=0; sutun<4; sutun++){
        sf::RectangleShape kare(sf::Vector2f(150, 150)); // her karenin boyutu
          kare.setPosition(sutun * 170 + 25, satir * 170 + 25);   // kareler arası bosluk
          window.draw(kare);
       }
    }

        window.display(); // cizdirdiklerimizi gosterecek
}
}
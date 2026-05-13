#ifndef OYUN_HPP
#define OYUN_HPP
#include <SFML/Graphics.hpp>
#include "tahta.hpp"

class Oyun {
private:
    sf::RenderWindow window;  
    Tahta tahta;  
    sf::Font font;    
      
public:
    Oyun();     
    void olaylar(); 
};

#endif
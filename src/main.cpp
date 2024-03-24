#include <iostream>
#include <SFML/Graphics.hpp>

int main(){
    std::cout << "hello world";

    sf::RenderWindow window(sf::VideoMode(200, 200), "SPACE SHOOTAN!");

    window.clear(sf::Color::White);
    window.display();

}

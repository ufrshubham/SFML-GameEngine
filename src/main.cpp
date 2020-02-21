#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow windows(sf::VideoMode(640, 360), "Demo App");

    while (windows.isOpen())
    {
        sf::Event event;
        while (windows.pollEvent(event))
        {
            if (sf::Event::Closed == event.type)
            {
                windows.close();
            }
        }

        windows.clear();
        //windows.draw();
        windows.display();
    }

    return 0;
}
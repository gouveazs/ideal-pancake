#include <SFML/Graphics.hpp>
#include <optional>

int main()
{
    sf::RenderWindow window(
        sf::VideoMode({960, 540}),
        "Ideal Pancake - Investigation Prototype"
    );

    window.setFramerateLimit(60);

    sf::CircleShape marker(48.0f);
    marker.setFillColor(sf::Color(220, 80, 80));
    marker.setPosition({456.0f, 222.0f});

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }

        window.clear(sf::Color(24, 28, 36));
        window.draw(marker);
        window.display();
    }

    return 0;
}

#pragma once

#include <SFML/Graphics.hpp>

#include "Scene.h"

class MainMenuScene
{
public:
    MainMenuScene(const sf::Font& font, const sf::Texture& backgroundTexture);

    SceneID handleEvent(const sf::Event& event);
    void draw(sf::RenderWindow& window) const;

private:
    sf::Sprite background;
    sf::Text title;
    sf::Text subtitle;
    sf::Text startText;
    sf::Text quitText;
};

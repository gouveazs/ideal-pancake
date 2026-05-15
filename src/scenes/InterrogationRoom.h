#pragma once

#include <SFML/Graphics.hpp>

#include <array>
#include <string>
#include <vector>

#include "Scene.h"

class InterrogationRoom
{
public:
    InterrogationRoom(
        const sf::Font& font,
        const sf::Texture& backgroundTexture,
        const sf::Texture& detectiveTexture
    );

    SceneID handleEvent(const sf::Event& event);
    void draw(sf::RenderWindow& window) const;

private:
    sf::Sprite background;
    sf::Sprite detective;
    sf::RectangleShape namePlate;
    sf::Text nameText;
    sf::RectangleShape dialogueBox;
    sf::Text dialogueText;
    sf::Text continueText;
    sf::Text backText;
    std::array<sf::RectangleShape, 3> actionButtons;
    std::array<sf::Text, 3> actionTexts;
    std::vector<std::string> dialogueLines;
    std::size_t currentLine;

    void advanceDialogue();
};

#include <SFML/Graphics.hpp>

#include <array>
#include <iostream>
#include <optional>
#include <string>
#include <vector>

int main()
{
    sf::RenderWindow window(
        sf::VideoMode({960, 540}),
        "Ideal Pancake - Dialogue Prototype"
    );

    window.setFramerateLimit(60);

    sf::Font font;
    if (!font.openFromFile("/usr/share/fonts/TTF/OpenSans-Regular.ttf"))
    {
        std::cerr << "Could not load font.\n";
        return 1;
    }

    const std::vector<std::string> dialogueLines = {
        "Detetive, encontrei algo estranho no depoimento.",
        "A testemunha disse que estava na sala as 8:40...",
        "Mas o relatorio da vitima aponta outro horario.",
        "Talvez seja a hora de apresentar uma evidencia."
    };

    std::size_t currentLine = 0;

    sf::RectangleShape background({960.0f, 540.0f});
    background.setFillColor(sf::Color(34, 39, 54));

    sf::RectangleShape backWall({960.0f, 250.0f});
    backWall.setPosition({0.0f, 0.0f});
    backWall.setFillColor(sf::Color(50, 58, 78));

    sf::RectangleShape desk({960.0f, 95.0f});
    desk.setPosition({0.0f, 265.0f});
    desk.setFillColor(sf::Color(84, 61, 48));

    sf::RectangleShape suspectBody({150.0f, 190.0f});
    suspectBody.setPosition({405.0f, 105.0f});
    suspectBody.setFillColor(sf::Color(94, 116, 168));

    sf::CircleShape suspectHead(54.0f);
    suspectHead.setPosition({426.0f, 38.0f});
    suspectHead.setFillColor(sf::Color(222, 179, 143));

    sf::RectangleShape namePlate({220.0f, 42.0f});
    namePlate.setPosition({48.0f, 326.0f});
    namePlate.setFillColor(sf::Color(123, 42, 54));
    namePlate.setOutlineThickness(3.0f);
    namePlate.setOutlineColor(sf::Color(242, 221, 165));

    sf::Text nameText(font, "Investigador", 22);
    nameText.setPosition({68.0f, 333.0f});
    nameText.setFillColor(sf::Color::White);

    sf::RectangleShape dialogueBox({864.0f, 135.0f});
    dialogueBox.setPosition({48.0f, 365.0f});
    dialogueBox.setFillColor(sf::Color(18, 22, 34, 235));
    dialogueBox.setOutlineThickness(4.0f);
    dialogueBox.setOutlineColor(sf::Color(242, 221, 165));

    sf::Text dialogueText(font, dialogueLines[currentLine], 26);
    dialogueText.setPosition({78.0f, 395.0f});
    dialogueText.setFillColor(sf::Color::White);

    sf::Text continueText(font, "Espaco / clique: avancar", 16);
    continueText.setPosition({690.0f, 468.0f});
    continueText.setFillColor(sf::Color(195, 205, 225));

    const std::array<std::string, 3> actionLabels = {
        "Pressionar",
        "Apresentar",
        "Registro"
    };

    std::array<sf::RectangleShape, 3> actionButtons;
    std::array<sf::Text, 3> actionTexts = {
        sf::Text(font, actionLabels[0], 18),
        sf::Text(font, actionLabels[1], 18),
        sf::Text(font, actionLabels[2], 18)
    };

    for (std::size_t i = 0; i < actionButtons.size(); ++i)
    {
        const float y = 48.0f + static_cast<float>(i) * 58.0f;

        actionButtons[i].setSize({150.0f, 42.0f});
        actionButtons[i].setPosition({760.0f, y});
        actionButtons[i].setFillColor(sf::Color(32, 38, 55));
        actionButtons[i].setOutlineThickness(2.0f);
        actionButtons[i].setOutlineColor(sf::Color(146, 164, 205));

        actionTexts[i].setPosition({778.0f, y + 8.0f});
        actionTexts[i].setFillColor(sf::Color::White);
    }

    auto advanceDialogue = [&currentLine, &dialogueLines, &dialogueText]()
    {
        currentLine = (currentLine + 1) % dialogueLines.size();
        dialogueText.setString(dialogueLines[currentLine]);
    };

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }

            if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
            {
                if (keyPressed->code == sf::Keyboard::Key::Space
                    || keyPressed->code == sf::Keyboard::Key::Enter)
                {
                    advanceDialogue();
                }
            }

            if (const auto* mousePressed = event->getIf<sf::Event::MouseButtonPressed>())
            {
                if (mousePressed->button == sf::Mouse::Button::Left)
                {
                    advanceDialogue();
                }
            }
        }

        window.clear();
        window.draw(background);
        window.draw(backWall);
        window.draw(desk);
        window.draw(suspectBody);
        window.draw(suspectHead);

        for (std::size_t i = 0; i < actionButtons.size(); ++i)
        {
            window.draw(actionButtons[i]);
            window.draw(actionTexts[i]);
        }

        window.draw(namePlate);
        window.draw(nameText);
        window.draw(dialogueBox);
        window.draw(dialogueText);
        window.draw(continueText);
        window.display();
    }
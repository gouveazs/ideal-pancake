#include "InterrogationRoom.h"

InterrogationRoom::InterrogationRoom(
    const sf::Font& font,
    const sf::Texture& backgroundTexture,
    const sf::Texture& detectiveTexture
)
    : background(backgroundTexture)
    , detective(detectiveTexture)
    , nameText(font, "Investigador", 22)
    , dialogueText(font, "", 26)
    , continueText(font, "Espaco / clique: avancar", 16)
    , backText(font, "Esc: voltar ao menu", 16)
    , actionTexts{
        sf::Text(font, "Pressionar", 18),
        sf::Text(font, "Apresentar", 18),
        sf::Text(font, "Registro", 18)
    }
    , dialogueLines{
        "Detetive, encontrei algo estranho no depoimento.",
        "A testemunha disse que estava na sala as 8:40...",
        "Mas o relatorio da vitima aponta outro horario.",
        "Talvez seja a hora de apresentar uma evidencia."
    }
    , currentLine(0)
{
    detective.setPosition({384.0f, 38.0f});
    detective.setScale({0.75f, 0.75f});

    namePlate.setSize({220.0f, 42.0f});
    namePlate.setPosition({48.0f, 326.0f});
    namePlate.setFillColor(sf::Color(123, 42, 54));
    namePlate.setOutlineThickness(3.0f);
    namePlate.setOutlineColor(sf::Color(242, 221, 165));

    nameText.setPosition({68.0f, 333.0f});
    nameText.setFillColor(sf::Color::White);

    dialogueBox.setSize({864.0f, 135.0f});
    dialogueBox.setPosition({48.0f, 365.0f});
    dialogueBox.setFillColor(sf::Color(18, 22, 34, 235));
    dialogueBox.setOutlineThickness(4.0f);
    dialogueBox.setOutlineColor(sf::Color(242, 221, 165));

    dialogueText.setPosition({78.0f, 395.0f});
    dialogueText.setFillColor(sf::Color::White);
    dialogueText.setString(dialogueLines[currentLine]);

    continueText.setPosition({690.0f, 468.0f});
    continueText.setFillColor(sf::Color(195, 205, 225));

    backText.setPosition({78.0f, 468.0f});
    backText.setFillColor(sf::Color(195, 205, 225));

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
}

SceneID InterrogationRoom::handleEvent(const sf::Event& event)
{
    if (const auto* keyPressed = event.getIf<sf::Event::KeyPressed>())
    {
        if (keyPressed->code == sf::Keyboard::Key::Escape)
        {
            return SceneID::MainMenu;
        }

        if (keyPressed->code == sf::Keyboard::Key::Space
            || keyPressed->code == sf::Keyboard::Key::Enter)
        {
            advanceDialogue();
        }
    }

    if (const auto* mousePressed = event.getIf<sf::Event::MouseButtonPressed>())
    {
        if (mousePressed->button == sf::Mouse::Button::Left)
        {
            advanceDialogue();
        }
    }

    return SceneID::Interrogation;
}

void InterrogationRoom::draw(sf::RenderWindow& window) const
{
    window.draw(background);
    window.draw(detective);

    for (std::size_t i = 0; i < actionButtons.size(); ++i)
    {
        window.draw(actionButtons[i]);
        window.draw(actionTexts[i]);
    }

    window.draw(namePlate);
    window.draw(nameText);
    window.draw(dialogueBox);
    window.draw(dialogueText);
    window.draw(backText);
    window.draw(continueText);
}

void InterrogationRoom::advanceDialogue()
{
    currentLine = (currentLine + 1) % dialogueLines.size();
    dialogueText.setString(dialogueLines[currentLine]);
}

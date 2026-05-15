#include "MainMenuScene.h"

MainMenuScene::MainMenuScene(const sf::Font& font, const sf::Texture& backgroundTexture)
    : background(backgroundTexture)
    , title(font, "Casa das Folhas", 54)
    , subtitle(font, "Um caso de investigacao", 24)
    , startText(font, "Enter - iniciar interrogatorio", 24)
    , quitText(font, "Esc - sair", 18)
{
    title.setPosition({260.0f, 145.0f});
    title.setFillColor(sf::Color(242, 221, 165));

    subtitle.setPosition({330.0f, 220.0f});
    subtitle.setFillColor(sf::Color(214, 222, 239));

    startText.setPosition({300.0f, 335.0f});
    startText.setFillColor(sf::Color::White);

    quitText.setPosition({430.0f, 380.0f});
    quitText.setFillColor(sf::Color(173, 186, 210));
}

SceneID MainMenuScene::handleEvent(const sf::Event& event)
{
    if (const auto* keyPressed = event.getIf<sf::Event::KeyPressed>())
    {
        if (keyPressed->code == sf::Keyboard::Key::Enter)
        {
            return SceneID::Interrogation;
        }

        if (keyPressed->code == sf::Keyboard::Key::Escape)
        {
            return SceneID::Quit;
        }
    }

    return SceneID::MainMenu;
}

void MainMenuScene::draw(sf::RenderWindow& window) const
{
    window.draw(background);
    window.draw(title);
    window.draw(subtitle);
    window.draw(startText);
    window.draw(quitText);
}

#include "Game.h"

#include <iostream>
#include <optional>

Game::Game()
    : window(sf::VideoMode({960, 540}), "Ideal Pancake")
    , mainMenuScene(font, menuBackgroundTexture)
    , interrogationRoom(font, interrogationBackgroundTexture, detectiveTexture)
    , currentScene(SceneID::MainMenu)
{
    window.setFramerateLimit(60);
}

int Game::run()
{
    if (!loadAssets())
    {
        return 1;
    }

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }

            if (currentScene == SceneID::MainMenu)
            {
                changeScene(mainMenuScene.handleEvent(*event));
            }
            else if (currentScene == SceneID::Interrogation)
            {
                changeScene(interrogationRoom.handleEvent(*event));
            }
        }

        window.clear();

        if (currentScene == SceneID::MainMenu)
        {
            mainMenuScene.draw(window);
        }
        else if (currentScene == SceneID::Interrogation)
        {
            interrogationRoom.draw(window);
        }

        window.display();
    }

    return 0;
}

bool Game::loadAssets()
{
    if (!font.openFromFile("/usr/share/fonts/TTF/OpenSans-Regular.ttf"))
    {
        std::cerr << "Could not load font.\n";
        return false;
    }

    if (!menuBackgroundTexture.loadFromFile("assets/images/backgrounds/main_menu.png"))
    {
        std::cerr << "Could not load menu background.\n";
        return false;
    }

    if (!interrogationBackgroundTexture.loadFromFile("assets/images/backgrounds/interrogation_room.png"))
    {
        std::cerr << "Could not load interrogation background.\n";
        return false;
    }

    if (!detectiveTexture.loadFromFile("assets/images/characters/detective.png"))
    {
        std::cerr << "Could not load detective image.\n";
        return false;
    }

    return true;
}

void Game::changeScene(SceneID nextScene)
{
    if (nextScene == SceneID::Quit)
    {
        window.close();
        return;
    }

    currentScene = nextScene;
}

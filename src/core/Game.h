#pragma once

#include <SFML/Graphics.hpp>

#include "../scenes/InterrogationRoom.h"
#include "../scenes/MainMenuScene.h"
#include "../scenes/Scene.h"

class Game
{
public:
    Game();

    int run();

private:
    sf::RenderWindow window;
    sf::Font font;
    sf::Texture menuBackgroundTexture;
    sf::Texture interrogationBackgroundTexture;
    sf::Texture detectiveTexture;

    MainMenuScene mainMenuScene;
    InterrogationRoom interrogationRoom;
    SceneID currentScene;

    bool loadAssets();
    void changeScene(SceneID nextScene);
};

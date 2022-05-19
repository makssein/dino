#pragma once

#include <myHeaders.h>
#include <assetManager.hpp>

class app{
public:
    app();
    ~app();

    bool isRunning();
    void update();
    void render();

private:
    sf::RenderWindow m_window;
    sf::Event m_event;

    assetManager<sf::Texture> m_textureManager;

    void initWindow();
    void handleEvents();
    void startGame();
};
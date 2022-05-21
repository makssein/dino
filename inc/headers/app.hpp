#pragma once

#include <myHeaders.h>
#include <assetManager.hpp>
#include <game.hpp>

class app{
public:
    app();
    ~app();

    bool isRunning();
    void update(float &myT);
    void render();

    void treesMove(bool& status){m_game.treesMove(status);}

private:
    sf::RenderWindow m_window;
    sf::Event m_event;

    bool wantJump = false;

    game m_game;

    assetManager<sf::Texture> m_textureManager;

    void initWindow();
    void handleEvents(float &myT);
};
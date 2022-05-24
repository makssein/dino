#pragma once

#include <myHeaders.h>
#include <assetManager.hpp>
#include <menu.hpp>
#include <stateMachine.hpp>

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
    stateMachine* m_machine;

    bool wantJump = false;

    assetManager<sf::Texture> m_textureManager;

    void initWindow();
    void handleEvents();
    void initStates();
};
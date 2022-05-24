#pragma once
#include "myHeaders.h"
#include "assetManager.hpp"

class State;

class stateMachine {
public:
    stateMachine(sf::RenderWindow& window);
    ~stateMachine();

    void addStateAtTop(State* state);

    void fixedUpdate();
    void update();
    void render();

    void clearAndPush(State* state);

    sf::RenderWindow& m_window;

private:
    sf::Sprite		   m_frameSprite;
    sf::RenderTexture  m_frame;
    std::stack<State*> m_states;

    void clearStates();
};

class State {
public:
    State(stateMachine& machine);
    virtual ~State();

    virtual void fixedUpdate() = 0;
    virtual void update() = 0;
    virtual void render(sf::RenderTarget& target) = 0;

    const bool isRunning() const;

    sf::Vector2f getMousePos() const;

protected:
    stateMachine& i_machine;

    sf::RenderWindow& i_window;
    bool i_isRunning = true;
};
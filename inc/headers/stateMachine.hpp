#pragma once
#include "myHeaders.h"
#include "assetManager.hpp"

class State;

class stateMachine {
public:
    stateMachine(sf::RenderWindow& window);
    ~stateMachine();

    void addStateAtTop(State* state);

    void update();
    void render();

    sf::RenderWindow& m_window;

    void addStateAtBottom(State* state);


private:
    sf::Sprite m_frameSprite;
    sf::RenderTexture m_frame;
    std::stack<State*> m_states;

    void clearStates();
};

class State {
public:
    State(stateMachine& machine);
    virtual ~State();

    virtual void update() = 0;
    virtual void render(sf::RenderTarget& target) = 0;

    const bool isRunning() const;

    sf::Vector2f getMousePos() const;

protected:
    stateMachine& i_machine;

    sf::RenderWindow& i_window;
    bool i_isRunning = true;
};
#include "myHeaders.h"
#include "stateMachine.hpp"

stateMachine::stateMachine(sf::RenderWindow& window) : m_window(window){
    m_frame.create(WINDOW_WIDTH, WINDOW_HEIGHT);
}

stateMachine::~stateMachine() {
    clearStates();
}

void stateMachine::update() {
    if (!m_states.empty()) {
        m_states.top()->update();
        if (!m_states.top()->isRunning()) {
            delete m_states.top();
            m_states.pop();
        }
    }
    else {
        m_window.close();
    }
}

void stateMachine::render() {
    m_frame.clear();

    if (!m_states.empty())
        m_states.top()->render(m_frame);
    m_frame.display();

    m_frameSprite.setTexture(m_frame.getTexture());


    m_window.draw(m_frameSprite);

}

void stateMachine::clearStates() {
    while (!m_states.empty()) {
        delete m_states.top();
        m_states.pop();
    }
}

State::State(stateMachine& machine) : i_machine(machine), i_window(machine.m_window){}

State::~State() {}

const bool State::isRunning() const {
    return i_isRunning;
}

sf::Vector2f State::getMousePos() const {
    return i_window.mapPixelToCoords(sf::Mouse::getPosition(i_window));
}

void stateMachine::addStateAtTop(State* state) {
    m_states.push(state);
}

void stateMachine::addStateAtBottom(State* state) {
    if (m_states.empty()) {
        m_states.push(state);
    }
    else {
        State* temp = m_states.top();
        m_states.pop();
        addStateAtBottom(state);
        m_states.push(temp);
    }
}
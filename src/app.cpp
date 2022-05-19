#include <app.hpp>

app::app(){
    initWindow();
}

app::~app(){}

void app::initWindow(){
    sf::VideoMode videoMode(WINDOW_WIDTH, WINDOW_HEIGHT);

    sf::Image image;
    image.loadFromFile("../inc/img/icon.png");

    m_window.create(videoMode, "DINOOOOO!", sf::Style::Default);
    m_window.setIcon(image.getSize().x, image.getSize().y, image.getPixelsPtr());
}

bool app::isRunning() {
    return m_window.isOpen();
}

void app::handleEvents() {
    while(m_window.pollEvent(m_event)){
        switch (m_event.type) {
            case sf::Event::Closed:
                m_window.close();
                break;
        }
    }
}

void app::update() {
    handleEvents();
}

void app::render() {
    m_window.clear();
    m_game.render(m_window);
    m_window.display();
}


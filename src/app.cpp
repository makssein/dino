#include <app.hpp>

app::app(){
    initWindow();
    initStates();
}

app::~app(){
    delete m_machine;
}

void app::initWindow(){
    sf::VideoMode videoMode(WINDOW_WIDTH, WINDOW_HEIGHT);

    sf::Image image;
    image.loadFromFile("../inc/img/icon.png");

    m_window.create(videoMode, "DINOOOOO!", sf::Style::None);
    m_window.setIcon(image.getSize().x, image.getSize().y, image.getPixelsPtr());

    m_window.setFramerateLimit(60);
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
    m_machine->update();
}

void app::render() {
    m_window.clear();
    m_machine->render();
    m_window.display();
}

void app::initStates() {
    m_machine = new stateMachine(m_window);

    m_machine->addStateAtTop(new menu(*m_machine));
}


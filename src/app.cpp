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

    m_window.setFramerateLimit(60);
}

bool app::isRunning() {
    return m_window.isOpen();
}

void app::handleEvents(float &myT) {
    while(m_window.pollEvent(m_event)){
        switch (m_event.type) {
            case sf::Event::Closed:
                m_window.close();
                break;
            case sf::Event::KeyPressed:
                if(m_event.key.code == sf::Keyboard::Space){
                    if(!wantJump){
                        wantJump = true;
                        myT=0;
                    }
                }
        }
    }
    if(wantJump)
        m_game.dinoWantJump(myT,wantJump);

}

void app::update(float &myT) {
    handleEvents(myT);
}

void app::render() {
    m_window.clear();
    m_game.render(m_window);
    m_window.display();
}


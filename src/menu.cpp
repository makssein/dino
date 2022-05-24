#include <menu.hpp>

menu::menu(stateMachine& machine) : State(machine)  {
    initAssets();
    initSprites();
}

menu::~menu(){}

void menu::fixedUpdate() {}

void menu::update() {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
        sf::IntRect(m_sprites["startButton"].getPosition().x - m_sprites["startButton"].getOrigin().x - 100,
                    m_sprites["startButton"].getPosition().y - m_sprites["startButton"].getOrigin().y,
                    m_textureManager.get("startButton").getSize().x * 2,
                    m_textureManager.get("startButton").getSize().y * 2)
                .contains(getMousePos().x, getMousePos().y)) {
        i_machine.clearAndPush(new game(i_machine));
    }

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
        sf::IntRect(m_sprites["exitButton"].getPosition().x - m_sprites["exitButton"].getOrigin().x - 100,
                    m_sprites["exitButton"].getPosition().y - m_sprites["exitButton"].getOrigin().y,
                    m_textureManager.get("exitButton").getSize().x * 2,
                    m_textureManager.get("exitButton").getSize().y * 2)
                .contains(getMousePos().x, getMousePos().y)) {
        i_isRunning = false;
    }
}

void menu::render(sf::RenderTarget& target) {

    for(const auto& sprites : m_sprites) {
        target.draw(sprites.second);
    }

}

void menu::initSprites(){
    //title
    auto& title = m_sprites["title"];
    title.setTexture(m_textureManager.get("title"));
    sf::Texture titleTexture = m_textureManager.get("title");

    title.setOrigin(titleTexture.getSize().x/2, titleTexture.getSize().y/2);
    title.setScale(1.5,1.5);
    title.setPosition(WINDOW_WIDTH/2,200);


    //exitButton
    auto& exitButton = m_sprites["exitButton"];
    exitButton.setTexture(m_textureManager.get("exitButton"));
    sf::Texture exitButtonTexture = m_textureManager.get("exitButton");

    exitButton.setOrigin(exitButtonTexture.getSize().x/2, exitButtonTexture.getSize().y/2);
    exitButton.setScale(1.7,1.7);
    exitButton.setPosition(500,1150);


    //startButton
    auto& startButton = m_sprites["startButton"];
    startButton.setTexture(m_textureManager.get("startButton"));
    sf::Texture startButtonTexture = m_textureManager.get("startButton");

    startButton.setOrigin(startButtonTexture.getSize().x/2, startButtonTexture.getSize().y/2);
    startButton.setScale(1.7,1.7);
    startButton.setPosition(500,1000);

    //background
    auto& background = m_sprites["background"];
    background.setTexture(m_textureManager.get("background"));

    sf::Texture backgroundTexture = m_textureManager.get("background");
    background.setScale(static_cast<double>(WINDOW_WIDTH)/backgroundTexture.getSize().x, static_cast<double>(WINDOW_HEIGHT)/backgroundTexture.getSize().y);
}

void menu::initAssets() {
    m_textureManager.load("background", "../inc/img/menu.jpg");
    m_textureManager.load("title", "../inc/img/title.png");
    m_textureManager.load("startButton", "../inc/img/startButton.png");
    m_textureManager.load("exitButton", "../inc/img/exitButton.png");

    m_fontManager.load("font", "../inc/fonts/font.ttf");
}


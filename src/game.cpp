#include <game.hpp>
#include <iostream>
#include <iomanip>

game::game(stateMachine& machine) : State(machine)  {
    initAssets();
    initScore();
    initTrees();
    initSprites();

}

game::~game(){}

void game::fixedUpdate() {}

void game::update() {
    updateScore();

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        if (!m_jump) {
            m_jump = true;
            m_t = 0;
        }
    }

    if(m_jump && m_isPlaying){
        m_dino.jump(m_t, m_jump, WINDOW_HEIGHT);
    }

    treesMove();
    collisionCheck();

    m_t+=0.7;
}

void game::render(sf::RenderTarget& target) {
    for(const auto& sprites : m_sprites) {
        target.draw(sprites.second);
    }

    target.draw(*m_dino.getDino());
    target.draw(m_scoreText);

    for(const auto& tree : m_trees) {
        target.draw(*tree->getTree());
    }

}

void game::initTrees() {
    for(int i = 0; i < 3; i++){
        m_trees.push_back(new tree());
    }
}

void game::initSprites(){
    //road
    auto& road = m_sprites["road"];
    road.setTexture(m_textureManager.get("road"));
    sf::Texture roadTexture = m_textureManager.get("background");

    road.setScale(1,0.2);
    road.setPosition(0, WINDOW_HEIGHT-roadTexture.getSize().y*0.1);


    //background
    auto& background = m_sprites["background"];
    background.setTexture(m_textureManager.get("background"));

    sf::Texture backgroundTexture = m_textureManager.get("background");
    background.setScale(static_cast<double>(WINDOW_WIDTH)/backgroundTexture.getSize().x, static_cast<double>(WINDOW_HEIGHT)/backgroundTexture.getSize().y);
}

void game::initAssets() {
    m_textureManager.load("background", "../inc/img/back.jpg");
    m_textureManager.load("road", "../inc/img/road.png");
    m_fontManager.load("font", "../inc/fonts/font.ttf");
}

void game::treesMove() {
    for(const auto& tree : m_trees) {
        if(m_isPlaying)
            tree->move();

        if(tree->getX() <= 0) {
            tree->setX(WINDOW_WIDTH+random::randInt(0, 2000));
        }
    }
}

void game::collisionCheck() {
    for(int i = 0; i < m_trees.size(); i++){
        int x_dino  = m_dino.getX();
        int y_dino = m_dino.getY();
        int sizeX_dino = m_dino.sizeX();
        int sizeY_dino = m_dino.sizeY();

        int x_tree = m_trees[i]->getX();
        int y_tree = m_trees[i]->getY();
        int sizeX_tree = m_trees[i]->sizeX();
        int sizeY_tree = m_trees[i]->sizeY();
        if(m_isPlaying) {
            if ((sizeX_dino / 2 - 50 + sizeX_tree / 2 - 25 >= abs(x_tree - x_dino)) &&
                (sizeY_dino / 2 - sizeY_tree / 2 <= y_dino - y_tree)) {
                m_dino.gameOver();
                m_isPlaying = false;
                break;
            } else m_score=m_timeClock.getElapsedTime().asSeconds();
        }
    }
}

void game::initScore(){
    m_scoreText.setString("0.000000");
    m_scoreText.setFillColor(sf::Color(255,255,255,255));
    m_scoreText.setFont(m_fontManager.get("font"));
    m_scoreText.setCharacterSize(200);
    m_scoreText.setPosition(WINDOW_WIDTH/2, 200);
    m_scoreText.setOrigin(sf::Vector2f(unsigned(m_scoreText.getGlobalBounds().width) / 2, unsigned(m_scoreText.getGlobalBounds().height + m_scoreText.getCharacterSize()) / 2));
}

void game::updateScore() {
    m_scoreText.setString(std::to_string(m_score));
}
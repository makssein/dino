#include <game.hpp>


game::game(){
    initAssets();
    initTrees();
    initSprites();
}

game::~game(){}

void game::render(sf::RenderWindow& window) {
    for(const auto& sprites : m_sprites) {
        window.draw(sprites.second);
    }

    window.draw(*m_dino.getDino());

    for(const auto& tree : m_trees) {
        window.draw(*tree->getTree());
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
}

void game::dinoWantJump(float t, bool &type) {
    m_dino.jump(t, type, WINDOW_HEIGHT);
}

void game::treesMove(bool &status) {
    for(const auto& tree : m_trees) {
        if(status)
            tree->move();

        if(tree->getX() <= 0) {
            tree->setX(WINDOW_WIDTH+random::randInt(0, 2000));
        }
    }
}
#include <game.hpp>
#include <iostream>

game::game(){
    initAsset();
    initDino();
    initTrees();
    initSprites();
}

game::~game(){}

void game::render(sf::RenderWindow& window) {
    for(const auto& sprites : m_sprites) {
        window.draw(sprites.second);
    }
}

void game::initDino() {
    dino();
}

void game::initTrees() {
    m_trees.push_back(tree());
    m_trees.push_back(tree());
    m_trees.push_back(tree());
}

void game::initSprites(){
    auto& background = m_sprites["background"];
    background.setTexture(m_textureManager.get("background"));

    auto& road = m_sprites["road"];
    background.setTexture(m_textureManager.get("road"));
}

void game::initAsset() {
    m_textureManager.load("background", "../inc/img/back.jpg");
    m_textureManager.load("road", "../inc/img/road.png");
}
#include <tree.hpp>

tree::tree(){
    initAssets();
    initTrees();
}
tree::~tree(){}

void tree::initAssets() {
    m_textureManager.load("tree", "../inc/img/tree.png");
}

void tree::initTrees(){
    m_tree = new sf::Sprite;

    sf::Texture texture = m_textureManager.get("tree");

    m_x = WINDOW_WIDTH+random::randInt(0, 2000);
    m_y = WINDOW_HEIGHT-texture.getSize().y/2;

    m_tree->setTexture(m_textureManager.get("tree"));


    m_tree->setScale(1.3,1.3);
    m_sizeX = texture.getSize().x;
    m_sizeY = texture.getSize().y;
    m_tree->setOrigin(texture.getSize().x/2, texture.getSize().y/2);
    m_tree->setPosition(m_x, m_y-texture.getSize().y/2);
}

void tree::move(){
    m_x-=30;
    m_tree->setPosition(m_x, m_y);
}
void tree::setX(int x){
    m_x = x;
    m_tree->setPosition(m_x, m_y);
}
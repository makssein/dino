#include <tree.hpp>


tree::tree(){
    initTrees();
    initAssets();
}
void tree::initAssets() {
    m_textureManager.load("tree", "../inc/img/tree.png");
}

void tree::initTrees(){
    m_tree = new sf::Sprite;
    m_x = WINDOW_WIDTH+(rand()%(1920-1080)+1080);
    m_y = WINDOW_HEIGHT-m_treetexture.getSize().y/2;
    m_tree->setTexture(m_textureManager.get("tree"));
    m_tree->setScale(1.3,1.3);
    m_sizeX = m_treetexture.getSize().x;
    m_sizeY = m_treetexture.getSize().y;
    m_tree->setOrigin(m_treetexture.getSize().x/2, m_treetexture.getSize().y/2);
    m_tree->setPosition(m_x, m_y-m_treetexture.getSize().y/2);
}

tree::~tree(){}

void tree::move(){
    m_x-=30;
    m_tree->setPosition(m_x, m_y);
}
void tree::setX(int x){
    m_x = x;
    m_tree->setPosition(m_x, m_y);
}
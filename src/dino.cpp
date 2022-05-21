#include <dino.hpp>
#include <iostream>

dino::dino(){
    initAssets();
    initDino();
}

dino::~dino(){ delete m_dino; };

void dino::initDino() {
    m_x = WINDOW_WIDTH;
    m_y = WINDOW_HEIGHT;

    m_dino = new sf::Sprite;

    m_dino->setTexture(m_textureManager.get("dinoTexture"));

    sf::Texture texture = m_textureManager.get("dinoTexture");
    m_sizeX = texture.getSize().x;
    m_sizeY = texture.getSize().y;
    m_dino->setOrigin(texture.getSize().x/2, texture.getSize().y);
    m_dino->setPosition(m_x/2,m_y);

}

void dino::initAssets() {
    m_textureManager.load("dinoTexture", "../inc/img/dino.png");
    m_textureManager.load("dinoGameOver", "../inc/img/dino_gameover.png");
}

void dino::jump(float &t, bool& jump, int window_y){
    m_window_y = window_y;
    m_y = m_window_y + 110 * sin(30 ) * t + 9.8 * t * t/2;
    if(m_y>=m_window_y+1){
        m_y=m_window_y;
        jump=false;
    }
    m_dino->setPosition(m_x/2,m_y);
   // std::cout <<

}
void dino::gameOver() {
    m_dino->setTexture(m_textureManager.get("dinoGameOver"));
}
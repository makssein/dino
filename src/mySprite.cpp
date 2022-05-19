#include <mySprite.hpp>

mySprite::mySprite(sf::Texture texture, float scale_x, float scale_y, int position_x, int position_y) {
    m_spriteTexture = texture;
    m_scale_x = scale_x;
    m_scale_y = scale_y;
    m_position_x = position_x;
    m_position_y = position_y;

    m_mySprite = new sf::Sprite;
    m_mySprite->setTexture(m_spriteTexture);
    m_mySprite->setScale(m_scale_x,m_scale_y);
    m_mySprite->setPosition(m_position_x, m_position_y);
}
mySprite::~mySprite() {delete m_mySprite;}
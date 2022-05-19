#include <myHeaders.h>

class mySprite {
public:
    mySprite(sf::Texture texture, float scale_x, float scale_y, int position_x, int position_y);
    ~mySprite();
    sf::Sprite* get(){return m_mySprite;}
private:
    sf::Texture m_spriteTexture;
    float m_scale_x, m_scale_y;
    int m_position_x, m_position_y;
    sf::Sprite* m_mySprite;
};
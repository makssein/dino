#include <myHeaders.h>
#include <assetManager.hpp>

class dino{
public:
    dino();
    ~dino();
    sf::Sprite* getDino(){return m_dino;}
    void jump(float &t, bool& jump, int window_y);
    int sizeX(){return m_sizeX;}
    int sizeY(){return m_sizeY;}

    int getY(){return m_y;}
    int getX(){return m_x;}

    void gameOver();
    void initDino();
private:
    int m_x, m_y, m_window_y, m_sizeX, m_sizeY;
    sf::Sprite* m_dino;

    assetManager<sf::Texture> m_textureManager;

    void initAssets();

};
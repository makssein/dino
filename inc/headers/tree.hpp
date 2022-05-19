#include <myHeaders.h>
#include <assetManager.hpp>

class tree{
public:
    tree();
    ~tree();
    sf::Sprite* getTree(){return m_tree;}
    void move();
    int getX(){return m_x;}
    int getY(){return m_y;}
    void setX(int x);
    int sizeX(){return m_sizeX;}
    int sizeY(){return m_sizeY;}
private:
    int m_y, m_x, m_sizeX, m_sizeY;
    sf::Texture m_treetexture;
    sf::Sprite* m_tree;

    assetManager<sf::Texture> m_textureManager;

    void initAssets();
    void initTrees();
};
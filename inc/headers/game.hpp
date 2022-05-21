#pragma once
#include <myHeaders.h>
#include <assetManager.hpp>

#include <dino.hpp>
#include <tree.hpp>


class game{
public:
    game();
    ~game();

    void render(sf::RenderWindow& window);

    void dinoWantJump(float t, bool &type);

    void treesMove(bool& status);

private:
    assetManager<sf::Texture> m_textureManager;
    std::unordered_map<std::string, sf::Sprite> m_sprites;

    dino m_dino;

    std::vector<tree*> m_trees;

    void initAssets();
    void initTrees();
    void initSprites();


};
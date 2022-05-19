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

private:
    assetManager<sf::Texture> m_textureManager;
    std::unordered_map<std::string, sf::Sprite> m_sprites;

    void initAsset();
    void initDino();
    void initTrees();
    void initSprites();

    std::vector<tree> m_trees;
};
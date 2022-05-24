#pragma once
#include <myHeaders.h>
#include <assetManager.hpp>
#include <game.hpp>

#include <stateMachine.hpp>


class menu : public State{
public:
    menu(stateMachine& machine);
    ~menu();

    virtual void fixedUpdate();
    virtual void update();
    virtual void render(sf::RenderTarget& target);

private:
    assetManager<sf::Texture> m_textureManager;
    assetManager<sf::Font> m_fontManager;
    std::unordered_map<std::string, sf::Sprite> m_sprites;

    sf::Text m_lastScore;
    sf::Text m_lastScoreTitle;

    void initAssets();
    void initSprites();
    void initTexts();
};
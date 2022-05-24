#pragma once
#include <myHeaders.h>
#include <assetManager.hpp>
#include <menu.hpp>
#include <stateMachine.hpp>
#include <save.hpp>

#include <dino.hpp>
#include <tree.hpp>


class game : public State{
public:
    game(stateMachine& machine);
    ~game();

    virtual void fixedUpdate();
    virtual void update();
    virtual void render(sf::RenderTarget& target);

    void treesMove();
    void collisionCheck();

private:
    assetManager<sf::Texture> m_textureManager;
    assetManager<sf::Font> m_fontManager;
    std::unordered_map<std::string, sf::Sprite> m_sprites;
    std::unordered_map<std::string, sf::Sprite> m_spritesGameOver;



    sf::Text m_scoreText;
    sf::Text m_yourScoreText;
    sf::Clock m_timeClock;

    sf::Sprite m_blur;

    bool m_isPlaying = true;
    bool m_jump = false;
    float m_t = 0;
    float m_score = 0.0f;

    dino m_dino;

    std::vector<tree*> m_trees;

    void initAssets();
    void initTrees();
    void initSprites();
    void initScore();
    void initYourScore();

    void updateScore();

};
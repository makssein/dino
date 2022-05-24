#include <game.hpp>

game::game(stateMachine& machine) : State(machine)  {
    initAssets();
    initScore();
    initTrees();
    initSprites();
    initYourScore();
}

game::~game(){}

void game::fixedUpdate() {}

void game::update() {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
        sf::IntRect(m_spritesGameOver["menuButton"].getPosition().x - m_spritesGameOver["menuButton"].getOrigin().x - 100,
                    m_spritesGameOver["menuButton"].getPosition().y - m_spritesGameOver["menuButton"].getOrigin().y,
                    m_textureManager.get("menuButton").getSize().x * 2,
                    m_textureManager.get("menuButton").getSize().y * 2)
                .contains(getMousePos().x, getMousePos().y)) {
        i_isRunning = false;
        i_machine.addStateAtBottom(new menu(i_machine));
    }

    updateScore();

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        if (!m_jump) {
            m_jump = true;
            m_t = 0;
        }
    }

    if(m_jump && m_isPlaying){
        m_dino.jump(m_t, m_jump, WINDOW_HEIGHT);
    }

    treesMove();
    collisionCheck();

    m_t+=0.7;
}

void game::render(sf::RenderTarget& target) {
    for(const auto& sprites : m_sprites) {
        target.draw(sprites.second);
    }

    target.draw(*m_dino.getDino());


    for(const auto& tree : m_trees) {
        target.draw(*tree->getTree());
    }

    if(!m_isPlaying) {
        target.draw(m_blur);
        for(const auto& sprites : m_spritesGameOver) {
            target.draw(sprites.second);
        }
        target.draw(m_yourScoreText);
        target.draw(m_scoreText);
    }
    else
        target.draw(m_scoreText);

}

void game::initTrees() {
    for(int i = 0; i < 3; i++){
        m_trees.push_back(new tree());
    }
}

void game::initSprites(){
    //blur
    m_blur.setTexture(m_textureManager.get("blur"));

    sf::Texture m_blurTexture = m_textureManager.get("blur");
    m_blur.setScale(static_cast<double>(WINDOW_WIDTH)/m_blurTexture.getSize().x, static_cast<double>(WINDOW_HEIGHT)/m_blurTexture.getSize().y);


    //menu button
    auto& menuButton = m_spritesGameOver["menuButton"];
    menuButton.setTexture(m_textureManager.get("menuButton"));
    sf::Texture menuButtonTexture = m_textureManager.get("menuButton");

    menuButton.setOrigin(menuButtonTexture.getSize().x/2, menuButtonTexture.getSize().y/2);
    menuButton.setScale(1.7,1.7);
    menuButton.setPosition(WINDOW_WIDTH/2,WINDOW_HEIGHT/2);


    //road
    auto& road = m_sprites["road"];
    road.setTexture(m_textureManager.get("road"));
    sf::Texture roadTexture = m_textureManager.get("background");

    road.setScale(1,0.2);
    road.setPosition(0, WINDOW_HEIGHT-roadTexture.getSize().y*0.1);


    //background
    auto& background = m_sprites["background"];
    background.setTexture(m_textureManager.get("background"));

    sf::Texture backgroundTexture = m_textureManager.get("background");
    background.setScale(static_cast<double>(WINDOW_WIDTH)/backgroundTexture.getSize().x, static_cast<double>(WINDOW_HEIGHT)/backgroundTexture.getSize().y);
}

void game::initAssets() {
    m_textureManager.load("background", "../inc/img/back.jpg");
    m_textureManager.load("road", "../inc/img/road.png");
    m_textureManager.load("blur", "../inc/img/blur.png");
    m_textureManager.load("menuButton", "../inc/img/menuButton.png");

    m_fontManager.load("font", "../inc/fonts/font.ttf");
}

void game::treesMove() {
    for(const auto& tree : m_trees) {
        if(m_isPlaying)
            tree->move();

        if(tree->getX() <= 0) {
            tree->setX(WINDOW_WIDTH+random::randInt(0, 2000));
        }
    }
}

void game::collisionCheck() {
    for(int i = 0; i < m_trees.size(); i++){
        int x_dino  = m_dino.getX();
        int y_dino = m_dino.getY();
        int sizeX_dino = m_dino.sizeX();
        int sizeY_dino = m_dino.sizeY();

        int x_tree = m_trees[i]->getX();
        int y_tree = m_trees[i]->getY();
        int sizeX_tree = m_trees[i]->sizeX();
        int sizeY_tree = m_trees[i]->sizeY();
        if(m_isPlaying) {
            if ((sizeX_dino / 2 - 50 + sizeX_tree / 2 - 25 >= abs(x_tree - x_dino)) &&
                (sizeY_dino / 2 - sizeY_tree / 2 <= y_dino - y_tree)) {
                m_dino.gameOver();
                m_isPlaying = false;
                saveFile::save("../inc/save.txt", std::to_string(m_score));
                break;
            } else m_score=m_timeClock.getElapsedTime().asSeconds();
        }
    }
}

void game::initScore(){
    m_scoreText.setString("0.000000");
    m_scoreText.setFillColor(sf::Color(255,255,255,255));
    m_scoreText.setFont(m_fontManager.get("font"));
    m_scoreText.setCharacterSize(200);
    m_scoreText.setPosition(WINDOW_WIDTH/2, 200);
    m_scoreText.setOrigin(sf::Vector2f(unsigned(m_scoreText.getGlobalBounds().width) / 2, unsigned(m_scoreText.getGlobalBounds().height + m_scoreText.getCharacterSize()) / 2));
}

void game::updateScore() {
    m_scoreText.setString(std::to_string(m_score));

    if(!m_isPlaying)
        m_scoreText.setPosition(WINDOW_WIDTH/2, 400);
}

void game::initYourScore() {
    m_yourScoreText.setString("You scored:");
    m_yourScoreText.setFillColor(sf::Color(255,255,255,255));
    m_yourScoreText.setFont(m_fontManager.get("font"));
    m_yourScoreText.setCharacterSize(200);
    m_yourScoreText.setPosition(WINDOW_WIDTH/2, 200);
    m_yourScoreText.setOrigin(sf::Vector2f(unsigned(m_yourScoreText.getGlobalBounds().width) / 2, unsigned(m_yourScoreText.getGlobalBounds().height + m_scoreText.getCharacterSize()) / 2));
}
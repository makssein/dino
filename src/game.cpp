#include <game.hpp>


game::game(){
    initAssets();
    initTrees();
    initSprites();
}

game::~game(){}

void game::render(sf::RenderWindow& window) {
    for(const auto& sprites : m_sprites) {
        window.draw(sprites.second);
    }

    window.draw(*m_dino.getDino());

    for(const auto& tree : m_trees) {
        window.draw(*tree->getTree());
    }
}

void game::initTrees() {
    for(int i = 0; i < 3; i++){
        m_trees.push_back(new tree());
    }
}

void game::initSprites(){
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
}

void game::dinoWantJump(float t, bool &type) {
    m_dino.jump(t, type, WINDOW_HEIGHT);
}

void game::treesMove(bool &status) {
    for(const auto& tree : m_trees) {
        if(status)
            tree->move();

        if(tree->getX() <= 0) {
            tree->setX(WINDOW_WIDTH+random::randInt(0, 2000));
        }
    }
}

void game::collisionCheck(bool& status) {
    for(int i = 0; i < m_trees.size(); i++){
        int x_dino  = m_dino.getX();
        int y_dino = m_dino.getY();
        int sizeX_dino = m_dino.sizeX();
        int sizeY_dino = m_dino.sizeY();

        int x_tree = m_trees[i]->getX();
        int y_tree = m_trees[i]->getY();
        int sizeX_tree = m_trees[i]->sizeX();
        int sizeY_tree = m_trees[i]->sizeY();
        if(status) {
            if ((sizeX_dino / 2 - 50 + sizeX_tree / 2 - 25 >= abs(x_tree - x_dino)) &&
                (sizeY_dino / 2 - sizeY_tree / 2 <= y_dino - y_tree)) {
                m_dino.gameOver();
                status = false;
                //score = score;
                /*if(score > best_score) {
                    best_score = score;
                }
                textGameover.newString("You lost\n"
                                       "Press R to replay");*/
                break;
            } //else score++;
        }
    }
}
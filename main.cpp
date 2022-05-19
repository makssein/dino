/*#include <SFML/Graphics.hpp>
#include <dino.hpp>
#include <tree.hpp>
#include <myText.hpp>
#include <mySprite.hpp>
#include <iostream>

int main(){
    srand(time(0));
    sf::RenderWindow window(sf::VideoMode(2880, 1620), L"Dinoooooo!");
    window.setFramerateLimit(60);

    float t = 0;
    int score = 0;
    bool jump = false;
    bool isPlaying = true;
    int best_score = 0;

    //uploading files
    sf::Texture dinotx;
    dinotx.setSmooth(true);
    if(!dinotx.loadFromFile("inc/img/dino.png")){
        std::cout << "ERROR: dino.png not found";
        return -1;
    }


    sf::Texture back;
    back.setSmooth(true);
    if(!back.loadFromFile("inc/img/back.jpg")){
        std::cout << "ERROR: back.jpg not found";
        return -1;
    }

    sf::Texture dino_gameover;
    dino_gameover.setSmooth(true);
    if(!dino_gameover.loadFromFile("inc/img/dino_gameover.png")){
        std::cout << "ERROR: dino_gameover.png not found";
        return -1;
    }

    sf::Texture road;
    road.setSmooth(true);
    if(!road.loadFromFile("inc/img/road.png")){
        std::cout << "ERROR: road.png not found";
        return -1;
    }

    sf::Texture treetx;
    treetx.setSmooth(true);
    if(!treetx.loadFromFile("inc/img/tree.png")){
        std::cout << "ERROR: tree.png not found";
        return -1;
    }

    sf::Font font;
    if (!font.loadFromFile("inc/fonts/font.otf")){
        std::cout << "ERROR: font was not loaded." << std::endl;
        return -1;
    }

    sf::Texture score_textTexture;
    score_textTexture.setSmooth(true);
    if (!score_textTexture.loadFromFile("inc/img/score.png")) {
        std::cout << "ERROR: score.png was not loaded." << std::endl;
        return -1;
    }

    sf::Texture bestScore_textTexture;
    bestScore_textTexture.setSmooth(true);
    if (!bestScore_textTexture.loadFromFile("inc/img/best_score.png")) {
        std::cout << "ERROR: best_score.png was not loaded." << std::endl;
        return -1;
    }
    // end uploading files

    sf::Color color_Text = sf::Color(243, 118, 68);

    //creating objects
    std::vector<tree*> trees;
    for(int i = 0; i < 3; i++){
        trees.push_back(new tree(treetx, window.getSize().x+(rand()%(1920-1080)+1080)*i, window.getSize().y));
    }

    dino dino(dinotx, window.getSize().x, window.getSize().y);
    mySprite roadsp(road,1,0.2,0,window.getSize().y-road.getSize().y*0.2);

    mySprite score_text(score_textTexture,0.2,0.2,20,0);
    mySprite background(back,static_cast<double>(window.getSize().x)/back.getSize().x,
                                   static_cast<double>(window.getSize().y)/back.getSize().y,0,0);

    mySprite bestScore_text(bestScore_textTexture,0.2,0.2,0,
                                       score_textTexture.getSize().y*0.2);

    myText scoreText(font, std::to_string(score),100,color_Text,
                                score_textTexture.getSize().x*0.2+50,10);

    myText bestScoreText(font,std::to_string(best_score),100,color_Text,
                                    bestScore_textTexture.getSize().x*0.2+50,score_textTexture.getSize().y*0.2+10);

    myText textGameover(font,"",50,color_Text,window.getSize().x/2,25);
    //end creating objects

    while (window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event)){
            switch(event.type){
                case sf::Event::Closed:
                    window.close();
                case sf::Event::KeyPressed:
                    if(event.key.code == sf::Keyboard::Space){
                        if(!jump){
                            jump = true;
                            t=0;
                        }
                    }
                    if(event.key.code == sf::Keyboard::R){
                        if(!isPlaying){
                            for(int i = 0; i < trees.size(); i++)
                                trees[i]->setX(window.getSize().x+(rand()%(1920-1080)+1080)*i);
                            score = 0;
                            isPlaying = true;
                            dino.newTexture(dinotx);
                            textGameover.newString("");
                        }
                    }
            }
        }

        if(jump){
            dino.jump(t,jump, window.getSize().y);
        }
        for(const auto& tree : trees){
            if(isPlaying)
                tree->move();
            if(tree->getX() <= 0)
                tree->setX(window.getSize().x+rand()%(7000-4000)+3000);
        }

        for(int i = 0; i < trees.size(); i++){
            int x_dino  = dino.getX();
            int y_dino = dino.getY();
            int sizeX_dino = dino.sizeX();
            int sizeY_dino = dino.sizeY();

            int x_tree = trees[i]->getX();
            int y_tree = trees[i]->getY();
            int sizeX_tree = trees[i]->sizeX();
            int sizeY_tree = trees[i]->sizeY();
            if(isPlaying) {
                if ((sizeX_dino / 2 - 50 + sizeX_tree / 2 - 25 >= abs(x_tree - x_dino / 2)) &&
                    (sizeY_dino / 2 - sizeY_tree / 2 <= y_dino - y_tree)) {
                    dino.newTexture(dino_gameover);
                    isPlaying = false;
                    score = score;
                    if(score > best_score) {
                        best_score = score;
                    }
                    textGameover.newString("You lost\n"
                                         "Press R to replay");
                    break;
                } else score++;
            }
        }
        window.clear();
        window.draw(*background.get());
        window.draw(*roadsp.get());
        for(const auto& tree : trees)
            window.draw(*tree->get());
        window.draw(*dino.get());
        scoreText.newString(std::to_string(score));
        bestScoreText.newString(std::to_string(best_score));
        window.draw(*scoreText.get());
        window.draw(*bestScoreText.get());
        window.draw(*bestScore_text.get());
        window.draw(*score_text.get());
        window.draw(*textGameover.get());
        window.display();

        t+=0.7;
    }
    return 0;
}
*/

#include <app.hpp>

int main(){
    app app;

    while(app.isRunning()){
        app.update();
        app.render();
    }

    return 0;
}
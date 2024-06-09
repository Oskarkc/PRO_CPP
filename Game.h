//
// Created by Oskar Koc on 24/05/2024.
//

#ifndef PRO_GAME_H
#define PRO_GAME_H
#include <SFML/Graphics.hpp>
#include <vector>

class Game {
public:
Game();
void start();
private:
    sf::RenderWindow window;
    sf::Font font;
    std::vector<sf::Font> fonty;
    std::vector<sf::Text> words;
    sf::Texture texture;
    sf::Sprite logo;
    sf::Text about;
    sf::Text buttonStart;
    sf::Text buttonSettings;
    sf::Text buttonAbout;
    sf::Text buttonBack;
    sf::Text buttonExit;
    sf::Text tryAgain;
    sf::Text yourInput;
    sf::Text backtoMenu;
    sf::RectangleShape panel;
    sf::Text timer;
    double number=0.0;
    int scorenumber=0;
    sf::Text score;
    sf::Text lifesleft;
    sf::Text gameover;
    int zycia = 5;
    sf::Text actualscore;
    sf::Text livetext;
    sf::Clock zegar;
    sf::Time czas;
    sf::Text wylosowaneslowo;
    std::vector<sf::Text> slowanaekranie;
    bool isMenu = true;
    bool isSettings = false;
    bool isAbout = false;
    bool isGame = false;
    bool isGameover = false;
    bool pausegame = false;
    float move=0.1;
    float respawn=2;
    void dodajslowa();
    sf::Text slowo();
    void generator();
    void respawntime();
    void loadfonts();
    void gameButtonsettings();
    void resetGame();
};


#endif //PRO_GAME_H

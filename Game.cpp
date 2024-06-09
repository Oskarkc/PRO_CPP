//
// Created by Oskar Koc on 24/05/2024.
//

#include "Game.h"
#include <SFML/Graphics.hpp>
#include <iostream>

Game::Game() : window(sf::VideoMode(1200, 700), "MonkeyTyperByOskar",
                      sf::Style::Default, sf::ContextSettings(0, 0, 4)) {

    font = sf::Font();
    if (!font.loadFromFile("../arial.ttf")) {
        std::cout << "Failed to load font.\n";
    }
    fonty.push_back(font);

    loadfonts();

    if(!texture.loadFromFile("../logo.png")){
        std::cout << "Failed to load image.\n";
    }
    logo = sf::Sprite();
    logo.setTexture(texture);
    logo.setPosition(50,-100);



    panel.setSize(sf::Vector2f(1200,100));
    panel.setFillColor(sf::Color::White);
    panel.setPosition(0,0);

    buttonStart = sf::Text(sf::String("START"), font, 64);
    buttonSettings = sf::Text(sf::String("SETTINGS"), font, 64);
    buttonAbout = sf::Text(sf::String("ABOUT"), font, 64);
    buttonBack = sf::Text(sf::String("BACK"), font, 32);
    buttonExit = sf::Text(sf::String("EXIT"),font,56);
    about = sf::Text(sf::String("Projekt wykonany na polecenie imperatora FK przedstawia prosta wersje gry\n typu monkeytyper. Gra wykonana w celu zaliczenia przedmiotu pjc.\n Kotlin Krol "),font,24);
    timer = sf::Text(sf::String("TIMER: "+std::to_string(number)), font , 32);
    score = sf::Text(sf::String("SCORE: "+std::to_string(scorenumber)), font, 32);
    lifesleft = sf::Text(sf::String("WORDS LEFT: "+std::to_string(zycia)), font , 32);
    gameover = sf::Text(sf::String("Game over"), font , 64);
    tryAgain = sf::Text(sf::String("Try Again"),font , 32);
    yourInput = sf::Text(sf::String("Your Input:"),font,32);
    backtoMenu = sf::Text(sf::String("BACK TO MENU"),font,32);


    buttonStart.setPosition(200, 300);
    buttonStart.setFillColor(sf::Color::White);
    buttonSettings.setPosition(200, 400);
    buttonSettings.setFillColor(sf::Color::White);
    buttonAbout.setPosition(200, 500);
    buttonAbout.setFillColor(sf::Color::White);
    buttonBack.setPosition(300, 600);
    buttonBack.setFillColor(sf::Color::White);
    buttonExit.setPosition(200,600);
    buttonExit.setFillColor(sf::Color::White);
    about.setPosition(200,400);
    about.setFillColor(sf::Color::White);
    backtoMenu.setFillColor(sf::Color::White);
    backtoMenu.setPosition(350,650);
    gameover.setFillColor(sf::Color::White);
    gameover.setPosition(350,300);
    tryAgain.setFillColor(sf::Color::White);
    tryAgain.setPosition(350,575);
    yourInput.setFillColor(sf::Color::Black);
    yourInput.setPosition(5,5);

    dodajslowa();

}

void Game::start() {

    std::string text="";
    auto livetext = sf::Text(text,font,32);
    livetext.setFillColor(sf::Color::Black);
    livetext.setPosition(50,50);

    auto mousepos = sf::Mouse::getPosition(window);
    auto event = sf::Event();
    while (window.isOpen()) {
        mousepos = sf::Mouse::getPosition(window);
        czas = zegar.getElapsedTime();
        if (isMenu) {
            window.draw(logo);
            window.draw(buttonStart);
            window.draw(buttonSettings);
            window.draw(buttonAbout);
            window.draw(buttonExit);


        }
        if (isSettings) {
            window.clear(sf::Color::Black);
            window.draw(logo);
            window.draw(buttonBack);
        }
        if(isAbout) {
            window.clear(sf::Color::Black);
            window.draw(logo);
            window.draw(about);
            window.draw(buttonBack);
        }
        if(isGame) {
            window.draw(panel);
            window.draw(timer);
            window.draw(score);
            window.draw(lifesleft);
            window.draw(yourInput);
            lifesleft.setString("WORDS LEFT: "+std::to_string(zycia));
            timer.setString("TIMER: "+std::to_string(number++/1000));
            score.setString("SCORE: "+std::to_string(scorenumber));
            livetext.setString(text);
            window.draw(livetext);
            window.draw(actualscore);
            gameButtonsettings();
            generator();
            if(zycia==0){
                isGame=false;
                isGameover=true;
            }
        }
        if(isGameover){
            window.draw(gameover);
            window.draw(score);
            score.setFillColor(sf::Color::White);
            score.setPosition(350,450);
            window.draw(timer);
            timer.setFillColor(sf::Color::White);
            timer.setPosition(350,500);
            window.draw(tryAgain);
        }
        if(pausegame){
            window.draw(logo);
            window.draw(score);
            score.setFillColor(sf::Color::White);
            score.setPosition(350,450);
            window.draw(buttonBack);
            window.draw(backtoMenu);
        }
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (isMenu) {
                if (event.type == sf::Event::MouseMoved) {
                    mousepos = sf::Mouse::getPosition(window);
                    if (buttonStart.getGlobalBounds().contains((mousepos.x),(mousepos.y))) {
                        buttonStart.setFillColor(sf::Color(169, 169, 169));
                    } else {
                        buttonStart.setFillColor(sf::Color::White);
                    }
                    if (buttonSettings.getGlobalBounds().contains((mousepos.x),(mousepos.y))) {
                        buttonSettings.setFillColor(sf::Color(169, 169, 169));
                    } else {
                        buttonSettings.setFillColor(sf::Color::White);
                    }
                    if (buttonAbout.getGlobalBounds().contains((mousepos.x),(mousepos.y))) {
                        buttonAbout.setFillColor(sf::Color(169, 169, 169));
                    } else {
                        buttonAbout.setFillColor(sf::Color::White);
                    }if (buttonExit.getGlobalBounds().contains((mousepos.x),(mousepos.y))) {
                        buttonExit.setFillColor(sf::Color(169, 169, 169));
                    } else {
                        buttonExit.setFillColor(sf::Color::White);
                    }
                }
                    if (event.type == sf::Event::MouseButtonPressed) {
                        if (buttonStart.getGlobalBounds().contains((mousepos.x),(mousepos.y))) {
                        isMenu = false;
                        isGame = true;
                        zegar.restart();
                    } else if (buttonSettings.getGlobalBounds().contains((mousepos.x),(mousepos.y))) {
                        isMenu = false;
                        isSettings = true;
                    } else if(buttonAbout.getGlobalBounds().contains((mousepos.x),(mousepos.y))){
                            isMenu = false;
                            isAbout = true;
                        }else if(buttonExit.getGlobalBounds().contains((mousepos.x),(mousepos.y))){
                            window.close();
                        }
                }
            } else if (isSettings) {
                if (event.type == sf::Event::MouseMoved) {
                    mousepos = sf::Mouse::getPosition(window);
                    if (buttonBack.getGlobalBounds().contains((mousepos.x),(mousepos.y))) {
                        buttonBack.setFillColor(sf::Color(169, 169, 169));
                    } else {
                        buttonBack.setFillColor(sf::Color::White);
                    }
                }
                if (event.type == sf::Event::MouseButtonPressed) {
                    if (buttonBack.getGlobalBounds().contains((mousepos.x),(mousepos.y))) {
                        isSettings = false;
                        isMenu = true;
                    }
                }

            } else if(isAbout){
                if (event.type == sf::Event::MouseMoved) {
                    mousepos = sf::Mouse::getPosition(window);
                    if (buttonBack.getGlobalBounds().contains((mousepos.x),(mousepos.y))) {
                        buttonBack.setFillColor(sf::Color(169, 169, 169));
                    } else {
                        buttonBack.setFillColor(sf::Color::White);
                    }
                }
                if (event.type == sf::Event::MouseButtonPressed) {
                    if (buttonBack.getGlobalBounds().contains((mousepos.x),(mousepos.y))) {
                        isAbout = false;
                        isMenu = true;
                    }
                }
            }else if(isGame){
                if(event.type==sf::Event::TextEntered){
                    if(std::isalnum(event.text.unicode)){ //https://en.cppreference.com/w/cpp/string/byte/isalnum
                        text+=event.text.unicode;
                    }
                }
                if(event.type==sf::Event::KeyPressed){
                    if(event.key.code == sf::Keyboard::Enter) {
                        for (auto it = slowanaekranie.begin() ; it!=slowanaekranie.end(); ) {
                            if (it->getString() == livetext.getString()) {
                                slowanaekranie.erase(it);
                                score.setString("SCORE: "+std::to_string(++scorenumber));
                                break;

                            }else
                                ++it;
                        }
                        text="";
                        respawntime();
                    } else if ( event.key.code == sf::Keyboard::BackSpace){
                        text.pop_back();
                    } else if (event.key.code == sf::Keyboard::Escape){
                        isGame=false;
                        pausegame = true;
                    }

                }
            }else if(isGameover){
                if(event.type == sf::Event::MouseMoved)
                    if(tryAgain.getGlobalBounds().contains(mousepos.x,mousepos.y)){
                        tryAgain.setFillColor(sf::Color(169, 169, 169));
                    }else
                        tryAgain.setFillColor(sf::Color::White);
                if(event.type == sf::Event::MouseButtonPressed)
                    if(tryAgain.getGlobalBounds().contains(mousepos.x,mousepos.y)){
                        resetGame();
                        isGameover = false;
                        isGame = true;
                    }
            }else  if(pausegame){
                if ( event.type == sf::Event::MouseMoved){
                    if (buttonBack.getGlobalBounds().contains((mousepos.x),(mousepos.y))) {
                        buttonBack.setFillColor(sf::Color(169, 169, 169));
                    } else {
                        buttonBack.setFillColor(sf::Color::White);
                    }
                    if (backtoMenu.getGlobalBounds().contains((mousepos.x),(mousepos.y))) {
                        backtoMenu.setFillColor(sf::Color(169, 169, 169));
                    } else {
                        backtoMenu.setFillColor(sf::Color::White);
                    }
                }else if(event.type == sf::Event::MouseButtonPressed)
                    if(buttonBack.getGlobalBounds().contains(mousepos.x,mousepos.y)){
                        isGame=true;
                        pausegame=false;
                    }else if(backtoMenu.getGlobalBounds().contains(mousepos.x,mousepos.y)){
                        resetGame();
                        pausegame=false;
                        isMenu=true;
                    }
            }

        }
        window.display();
        window.clear(sf::Color::Black);
    }
}
void Game::dodajslowa() {
    words={sf::Text(sf::String("hejka"),font,32),
           sf::Text(sf::String("elo"),font,32),
           sf::Text(sf::String("witam"),font,32),
           sf::Text(sf::String("bonjour"),font,32),
           sf::Text(sf::String("hi"),font,32),
           sf::Text(sf::String("welcome"),font,32),
           sf::Text(sf::String("vamos"),font,32)};
}
sf::Text Game::slowo(){
    auto randomY = rand()%500+101;
    auto random = rand()%words.size();
    words[random].setPosition(-50, randomY);
    words[random].setFillColor(sf::Color::White);
    words[random].setCharacterSize(rand()%32+18);
    words[random].setFont(fonty[rand()%fonty.size()]);
    return words[random];
}
void Game::generator(){

    for(sf::Text& s : slowanaekranie){
        window.draw(s);
        s.move(move,0);
    }
    for (auto it = slowanaekranie.begin() ; it!=slowanaekranie.end(); ) {
        if(it->getPosition().x > 600 && it->getPosition().x < 899){
            it->setFillColor(sf::Color::Yellow);
            ++it;
        }else if(it->getPosition().x > 900 && it->getPosition().x  < 1199 ){
            it->setFillColor(sf::Color::Red);
            ++it;
        }else if(it->getPosition().x > 1200) {
            slowanaekranie.erase(it);
            zycia-=1;
            break;

        }else
            ++it;
    }

    if (czas.asSeconds() > respawn) {
        slowanaekranie.push_back(slowo());
        zegar.restart();
    }
}
void Game::respawntime() {
    if(scorenumber%5==0){
        move+=0.02;
        respawn-=0.3;
    }
    if(respawn<=0.5){
        respawn=0.5;
    }
}
void Game::loadfonts(){
    sf::Font tfont;
    if (!tfont.loadFromFile("../monaque.otf")) {
        std::cout << "Failed to load font.\n";
    }
    fonty.push_back(tfont);
    if (!tfont.loadFromFile("../toper.otf")) {
        std::cout << "Failed to load font.\n";
    }
    fonty.push_back(tfont);
}
void Game::gameButtonsettings(){

    timer.setPosition(850,50);
    timer.setFillColor(sf::Color::Black);
    score.setPosition(500,50);
    score.setFillColor(sf::Color::Black);
    lifesleft.setFillColor(sf::Color::Black);
    lifesleft.setPosition(500,10);
}
void Game::resetGame(){
    number = 0;
    zycia = 5;
    scorenumber=0;
    gameButtonsettings();
    for(auto it = slowanaekranie.begin(); it != slowanaekranie.end();){
        slowanaekranie.erase(it);
    }
}
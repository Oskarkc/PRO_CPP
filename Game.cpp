//
// Created by Oskar Koc on 24/05/2024.
//

#include "Game.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>

Game::Game() : window(sf::VideoMode(1200, 700), "MonkeyTyperByOskar",
                      sf::Style::Default, sf::ContextSettings(0, 0, 4)) {

    font = sf::Font();
    if (!font.loadFromFile("../arial.ttf")) {
        std::cout << "Failed to load font.\n";
    }
    chosenfont=font;
    fonty.push_back(font);

    loadfonts();

    if(!texture.loadFromFile("../logo.png")){
        std::cout << "Failed to load image.\n";
    }
    logo = sf::Sprite();
    logo.setTexture(texture);
    logo.setPosition(50,-100);

    if(!backgroundtext.loadFromFile("../background.jpeg")){
        std::cout << "Failed to load image.\n";
    }
    backgroundsprite = sf::Sprite();
    backgroundsprite.setTexture(backgroundtext);
    backgroundsprite.setPosition(475,300);

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
    chooseLanguage = sf::Text(sf::String("Choose Language"),font,32);
    chooseFont = sf::Text(sf::String("Choose Font"),font , 32);
    FR = sf::Text(sf::String("FR"),font,32);
    ENG = sf::Text(sf::String("ENG"),font,32);
    PL = sf::Text(sf::String("PL"),font,32);
    ESP = sf::Text(sf::String("ESP"),font,32);
    EASY = sf::Text(sf::String("Easy"),font,32);
    HARD = sf::Text(sf::String("Hard"),font,32);
    font1 = sf::Text(sf::String("abcdefgABCDEFG"),fonty[0],32);
    font2 = sf::Text(sf::String("abcdefgABCDEFG"),fonty[1],32);
    font3 = sf::Text(sf::String("abcdefgABCDEFG"),fonty[2],32);



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
    chooseLanguage.setPosition(200,400);
    chooseLanguage.setFillColor(sf::Color::White);
    chooseFont.setPosition(200,450);
    chooseFont.setFillColor(sf::Color::White);
    FR.setPosition(250,450);
    FR.setFillColor(sf::Color::White);
    ENG.setPosition(475,450);
    ENG.setFillColor(sf::Color::White);
    ESP.setPosition(390,450);
    ESP.setFillColor(sf::Color::White);
    PL.setFillColor(sf::Color::White);
    PL.setPosition(325,450);
    EASY.setFillColor(sf::Color::White);
    EASY.setPosition(250,350);
    HARD.setFillColor(sf::Color::White);
    HARD.setPosition(450,350);
    font1.setPosition(300,350);
    font2.setPosition(300,400);
    font3.setPosition(300,450);
    font1.setFillColor(sf::Color::White);
    font2.setFillColor(sf::Color::White);
    font3.setFillColor(sf::Color::White);



}

void Game::start() {

    std::string text="";
    livetext = sf::Text(text,font,32);
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
            window.draw(logo);
            window.draw(buttonBack);
            window.draw(chooseLanguage);
            window.draw(chooseFont);

        }
        if(isChooseFont){
            window.draw(logo);
            window.draw(font1);
            window.draw(font2);
            window.draw(font3);
            window.draw(buttonBack);
        }
        if(isChooseLanguage){
            window.draw(FR);
            window.draw(PL);
            window.draw(ESP);
            window.draw(ENG);
            window.draw(buttonBack);
            window.draw(logo);
        }
        if(chooselevel){
            window.draw(logo);
            window.draw(EASY);
            window.draw(HARD);
            window.draw(buttonBack);
        }
        if(isAbout) {
            window.draw(logo);
            window.draw(about);
            window.draw(buttonBack);
        }
        if(isGame) {
            window.draw(backgroundsprite);
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
                text = "";
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
                        dodajslowa();
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
                    if (chooseLanguage.getGlobalBounds().contains((mousepos.x),(mousepos.y))) {
                        chooseLanguage.setFillColor(sf::Color(169, 169, 169));
                    } else {
                        chooseLanguage.setFillColor(sf::Color::White);
                    }
                    if (chooseFont.getGlobalBounds().contains((mousepos.x),(mousepos.y))) {
                        chooseFont.setFillColor(sf::Color(169, 169, 169));
                    } else {
                        chooseFont.setFillColor(sf::Color::White);
                    }
                }
                if (event.type == sf::Event::MouseButtonPressed) {
                    if (buttonBack.getGlobalBounds().contains((mousepos.x),(mousepos.y))) {
                        isSettings = false;
                        isMenu = true;
                    }
                    if(chooseLanguage.getGlobalBounds().contains(mousepos.x,mousepos.y)){
                        isSettings = false;
                        isChooseLanguage = true;
                    }
                    if(chooseFont.getGlobalBounds().contains(mousepos.x,mousepos.y)){
                        isSettings=false;
                        isChooseFont=true;
                    }

                }
            }
            else if(isChooseLanguage) {
                if (event.type == sf::Event::MouseMoved) {
                    mousepos = sf::Mouse::getPosition(window);
                    if (buttonBack.getGlobalBounds().contains((mousepos.x),(mousepos.y))) {
                        buttonBack.setFillColor(sf::Color(169, 169, 169));
                    } else {
                        buttonBack.setFillColor(sf::Color::White);
                    }
                    if (ENG.getGlobalBounds().contains((mousepos.x),(mousepos.y))) {
                        ENG.setFillColor(sf::Color(169, 169, 169));
                    } else {
                        ENG.setFillColor(sf::Color::White);
                    }
                    if (ESP.getGlobalBounds().contains((mousepos.x),(mousepos.y))) {
                        ESP.setFillColor(sf::Color(169, 169, 169));
                    } else {
                        ESP.setFillColor(sf::Color::White);
                    }
                    if (PL.getGlobalBounds().contains((mousepos.x),(mousepos.y))) {
                        PL.setFillColor(sf::Color(169, 169, 169));
                    } else {
                        PL.setFillColor(sf::Color::White);
                    }
                    if (FR.getGlobalBounds().contains((mousepos.x),(mousepos.y))) {
                        FR.setFillColor(sf::Color(169, 169, 169));
                    } else {
                        FR.setFillColor(sf::Color::White);
                    }
                }
                if (event.type == sf::Event::MouseButtonPressed) {
                    if (buttonBack.getGlobalBounds().contains((mousepos.x), (mousepos.y))) {
                        isChooseLanguage = false;
                        isSettings = true;
                    }
                    if (ENG.getGlobalBounds().contains((mousepos.x),(mousepos.y))) {
                        chooselevel= true;
                        isChooseLanguage = false;
                        language = "../ENGslownik";
                    }
                    if (FR.getGlobalBounds().contains((mousepos.x),(mousepos.y))) {
                        chooselevel = true;
                        isChooseLanguage = false;
                        language = "../FRslownik";
                    }
                    if (ESP.getGlobalBounds().contains((mousepos.x),(mousepos.y))) {
                        chooselevel = true;
                        isChooseLanguage = false;
                        language = "../ESPslownik";
                    }
                    if (PL.getGlobalBounds().contains((mousepos.x),(mousepos.y))) {
                        chooselevel = true;
                        isChooseLanguage = false;
                        language = "../PLslownik";
                    }
                }
            }
            else if(chooselevel) {
                if (event.type == sf::Event::MouseMoved) {
                    mousepos = sf::Mouse::getPosition(window);
                    if (buttonBack.getGlobalBounds().contains((mousepos.x), (mousepos.y))) {
                        buttonBack.setFillColor(sf::Color(169, 169, 169));
                    } else {
                        buttonBack.setFillColor(sf::Color::White);
                    }
                    if (EASY.getGlobalBounds().contains((mousepos.x),(mousepos.y))) {
                        EASY.setFillColor(sf::Color(169, 169, 169));
                    } else {
                        EASY.setFillColor(sf::Color::White);
                    }
                    if (HARD.getGlobalBounds().contains((mousepos.x),(mousepos.y))) {
                        HARD.setFillColor(sf::Color(169, 169, 169));
                    } else {
                        HARD.setFillColor(sf::Color::White);
                    }
                }
                if (event.type == sf::Event::MouseButtonPressed) {
                    if(EASY.getGlobalBounds().contains(mousepos.x,mousepos.y)){
                        chooselevel = false;
                        isSettings= true;
                    }
                    if(HARD.getGlobalBounds().contains(mousepos.x,mousepos.y)){
                        language.push_back('h');
                        chooselevel = false;
                        isSettings = true;
                    }
                }

            }
            else if(isChooseFont){
                if (event.type == sf::Event::MouseMoved) {
                    mousepos = sf::Mouse::getPosition(window);
                    if (buttonBack.getGlobalBounds().contains((mousepos.x),(mousepos.y))) {
                        buttonBack.setFillColor(sf::Color(169, 169, 169));
                    } else {
                        buttonBack.setFillColor(sf::Color::White);
                    }
                    if (font1.getGlobalBounds().contains((mousepos.x),(mousepos.y))) {
                        font1.setFillColor(sf::Color(169, 169, 169));
                    } else {
                        font1.setFillColor(sf::Color::White);
                    }
                    if (font2.getGlobalBounds().contains((mousepos.x),(mousepos.y))) {
                        font2.setFillColor(sf::Color(169, 169, 169));
                    } else {
                        font2.setFillColor(sf::Color::White);
                    }
                    if (font3.getGlobalBounds().contains((mousepos.x),(mousepos.y))) {
                        font3.setFillColor(sf::Color(169, 169, 169));
                    } else {
                        font3.setFillColor(sf::Color::White);
                    }
                }
                if (event.type == sf::Event::MouseButtonPressed) {
                    if (buttonBack.getGlobalBounds().contains((mousepos.x), (mousepos.y))) {
                        isChooseFont = false;
                        isSettings = true;
                    }
                    if(font1.getGlobalBounds().contains(mousepos.x,mousepos.y)){
                        chosenfont = fonty[0];
                        isChooseFont= false;
                        isSettings = true;
                    }
                    if(font2.getGlobalBounds().contains(mousepos.x,mousepos.y)){
                        chosenfont = fonty[1];
                        isChooseFont= false;
                        isSettings = true;
                    }
                    if(font3.getGlobalBounds().contains(mousepos.x,mousepos.y)){
                        chosenfont = fonty[2];
                        isChooseFont= false;
                        isSettings = true;
                    }
                }

            }
            else if(isAbout){
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
                    for (auto it = slowanaekranie.begin() ; it!=slowanaekranie.end();++it) {
                        if(*text.begin() == *it->getString().begin()){
                            it->setFillColor(sf::Color::Green);
                            break;
                        }
                        else if(*text.begin() != *it->getString().begin()){
                            it->setFillColor(sf::Color::White);
                        }
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
                        if(!text.empty()){
                            text.pop_back();
                        }
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
    auto file = std::fstream(language);
    std::string line;
    while (std::getline(file, line)) {
        words.push_back(sf::Text(sf::String(line), font, 64));
    }
}
sf::Text Game::slowo(){
    auto randomY = rand()%500+101;
    auto random = rand()%words.size();
    words[random].setPosition(-50, randomY);
    for(int i=0 ; i < slowanaekranie.size() ; i++){
        if (words[random].getGlobalBounds().intersects(slowanaekranie[i].getGlobalBounds())){
            return slowo();
        }
    }
    words[random].setFillColor(sf::Color::White);
    words[random].setCharacterSize(24);
    words[random].setFont(chosenfont);
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
    move = 0.1;
    respawn = 2;
    gameButtonsettings();
    for(auto it = slowanaekranie.begin(); it != slowanaekranie.end();){
        slowanaekranie.erase(it);
    }
}
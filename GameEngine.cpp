#include "GameEngine.h"

GameEngine::GameEngine(){
    //todo
}
GameEngine::~GameEngine(){
    //todo
}

void GameEngine::setupGame(){
    tileBag = new TileBag();
}

void GameEngine::newGame(){
    //todo
}

void GameEngine::addPlayer(std::string playerName){
    //todo
}
void GameEngine::setPlayerScore(Player* player, int score){
    //todo
}
void GameEngine::setPlayerName(Player* player, std::string name){
    //todo
}

void GameEngine::placeTile(){
    //todo
}
int GameEngine::calculateScore(){
    //todo
    return 0;
}
void GameEngine::replaceTile(){
    //todo
}
void GameEngine::drawCard(){
    //todo
}

std::string GameEngine::displayBoard(){
    //todo
    return "";
}

void GameEngine::saveGame(std::string fileName){
    //todo
}
bool GameEngine::loadGame(std::string fileName){
    bool check = false;
    //todo
    return check;
}
bool GameEngine::gameOver(){
    bool check = false;
    //todo
    return check;
}
void GameEngine::quit(){
    //todo
}
int GameEngine::convertLetterToNum(char letter){
    int n = letter;
    return n - 97;
}
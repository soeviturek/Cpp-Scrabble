#include "GameEngine.h"

GameEngine::GameEngine(){
    //todo
}
GameEngine::~GameEngine(){
    //todo
}

void GameEngine::setupGame(){
    tileBag = new TileBag();
    //hand
}

void GameEngine::newGame(){
    //todo
}

bool GameEngine::addPlayer(std::string playerName){
    bool check = false;
    if(checkPlayerNameValidity(playerName) && players.size() != MAX_PLAYERS){
        Player* player = new Player(playerName);
        players.push_back(player);
        check = true;
    }
    return check;
}
void GameEngine::setPlayerScore(Player* player, int score){
    //todo
}
void GameEngine::setPlayerName(Player* player, std::string name){
    //todo
}

void GameEngine::placeTile(Tile* tile, int row, int col){
    //todo
}
int GameEngine::calculateScore(std::vector<Tile*> tiles){
    //todo
    return 0;
}
void GameEngine::replaceTile(Tile* tile){
    //todo
}
Tile* GameEngine::drawTile(){
    //todo
    return nullptr;
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
bool GameEngine::checkPlayerNameValidity(std::string name){
    bool check = false;
    if(name.compare("1") == 0){
        check = true;
    }
    return check;
}
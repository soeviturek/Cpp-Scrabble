#include "GameEngine.h"
#include <iostream>

GameEngine::GameEngine(){
    tileBag = nullptr;
    board = nullptr;
}
GameEngine::~GameEngine(){
    if(tileBag != nullptr){
        delete tileBag;
    }
    if(board != nullptr){
        delete board;
    }
}

void GameEngine::setupGame(){
    tileBag = new TileBag();
    board = new Board();
    //hand
    for(Player* player : players){
        player->setHand(tileBag->initiateHand());
    }
}

void GameEngine::newGame(){
    //todo
    Player* currentPlayer = nullptr;
    std::cout<<currentPlayer->getName()<<", it's your turn" << std::endl;
    for(Player* player : players){
        std::cout<<"Score for" << player->getName() << ": " << std::endl;
    }
    std::cout << board << std::endl;
    std::cout << "Your hand is\n" << currentPlayer->getHand();
    
    std::string input = "";
    std::vector<std::string> tokens;
    bool check = false;
    //not sure about this
    while (std::getline(std::cin, input) && !check){
        if(input.find("place")){
            currentPlayer->setPassTime(0);
        }else if(input.find("replace")){
            currentPlayer->setPassTime(0);
        }else if(input.find("pass")){
            currentPlayer->pass();
        }
    }
    //check if game ends;
//??????????????????????????????????????
for (std::string s : tokens) //Gets all tokens one by one
    for(char c : s){// Gets all char in each token
        if(islower(c)){// Checks if thats a lowercase letter
            std::cout << c << std::endl;
        }
    }

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
    player->setScore(score);
}
void GameEngine::setPlayerName(Player* player, std::string name){
    player->setName(name);
}

void GameEngine::placeTile(Tile* tile, int row, int col){

}
int GameEngine::calculateScore(std::vector<Tile*> tiles){
    int score = 0;
    for(Tile* tile : tiles){
        score += tile->value;
    }
    return score;
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
    bool check = true;
    for(char c : name){
        if(!isupper(c)){
            check = false;
        }
    }
    return check;
}
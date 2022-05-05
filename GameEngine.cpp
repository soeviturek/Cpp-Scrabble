#include "GameEngine.h"
#include <iostream>

GameEngine::GameEngine(){
    //todo
}
GameEngine::~GameEngine(){
    //todo
}

void GameEngine::setupGame(){
    tileBag = new TileBag();
    board = new Board();
    //hand
    for(int i = 0; i < players.size();++i){
        Player* player = players[i];
        player->setHand(tileBag->initiateHand());
    }
}

void GameEngine::newGame(){
    //todo
    Player* currentPlayer = nullptr;
    std::cout<<currentPlayer->getName()<<", it's your turn" << std::endl;
    for(int i = 0; i < players.size(); ++i){
        std::cout<<"Score for" << players[i] << ": " << std::endl;
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
    for (char c : s)// Gets all char in each token
        if (islower(c))// Checks if thats a lowercase letter
            std::cout << c << std::endl;
    if(input == "pass"){

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
    for(int i = 0; i < tiles.size(); ++i){
        score += tiles[i]->value;
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
    bool check = false;
    if(name.compare("1") == 0){
        check = true;
    }
    return check;
}
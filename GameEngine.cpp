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
        tileBag->initiateHand(player->getHand());
    }
    // tileBag->initiateHand(players[0]->getHand());
}

void GameEngine::newGame(){
    //todo
    Player* currentPlayer = players[0];
    std::cout<<currentPlayer->getName()<<", it's your turn" << std::endl;
    for(Player* player : players){
        std::cout<<"Score for " << player->getName() << ": " << player->getScore() << std::endl;
    }
    std::cout << board->printBoard();
    std::cout << currentPlayer->getHand()->printHand();
    
    std::string input = "";
    bool check = false;

    //get use input
    std::cout << "> ";
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, input);
    while (!check){
        std::vector<char> tokens;
        std::cout << ">";
        std::cin.clear();
        std::getline(std::cin, input);
        std::cout << "checking input..\n";
        if(input.find("place") != std::string::npos){
            input.erase(0,5);
            if(input.find("at") != std::string::npos){
                for(char c : input){
                    if(c != ' '){
                        tokens.push_back(c);
                    }
                }
                if(tokens.size() == 5 && isupper(tokens[0])&& isupper(tokens[3]) && isdigit(tokens[4])){
                    Tile* tile = new Tile();
                    tile->letter = tokens[0];
                    tile->value = tile->getValue(tokens[0]);
                    int row = convertLetterToNum(tokens[3]);
                    int col = tokens[4] - '0'; //ascii for 0 starts at 48
                    currentPlayer->placeTile(tile,row,col);
                    board->placeTile(tile,row,col);
                    currentPlayer->setPassTime(0);
                    check = true;
                    std::cout << board->printBoard();
                }else{
                    std::cout<<"Wrong format!\n";
                }
            }
        }else if(input.find("replace") != std::string::npos){
            currentPlayer->setPassTime(0);
            check = true;
        }else if(input.find("pass") != std::string::npos){
            currentPlayer->pass();
            check = true;
        }else{
            std::cout << "Invalid Input!" << std::endl;
        }
    }
    //check if game ends;
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
    return n - 'A';
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
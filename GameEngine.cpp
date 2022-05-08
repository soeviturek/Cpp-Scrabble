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
    bool gameover = false;
    while(!gameover){
    Player* currentPlayer = players[0];
    std::cout<<currentPlayer->getName()<<", it's your turn" << std::endl;
    for(Player* player : players){
        std::cout<<"Score for " << player->getName() << ": " << player->getScore() << std::endl;
    }
    Tile* test = new Tile();
    test->letter = 'Q';
    board->placeTile(test,8,8);
    
    std::cout << board->printBoard();
    std::cout << currentPlayer->getHand()->printHand();
    std::string input = "";
    bool check = false;

    //get user input
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::vector<std::string> placedTiles;
    Hand* tempCopyHand = new Hand(*currentPlayer->getHand());

    std::vector<Tile*> tiles; //tile to store all the tile object
    std::vector<int> rows; //to store all rows
    std::vector<int> cols; //to store all cols
    bool legal = true; //assume the placement is legal
    while (!check){
        std::vector<char> tokens;
        std::cout << "> ";
        std::cin.clear();
        std::getline(std::cin, input);
        if(input.find("place") != std::string::npos){
            input.erase(0,5);
            if(input.find("DONE")!= std::string::npos){
                for(char c: input){
                    if(c != ' '){
                        tokens.push_back(c);
                    }
                }
                if(tokens.size() == 4){ //check if place DONE is correctly formatted
                    for(std::string s : placedTiles){
                        std::cout << s << std::endl;
                        if(legal){
                            Tile* tile = new Tile();
                            tile->letter = s.at(0);
                            tile->value = tile->getValue(tile->letter);
                            int row = convertLetterToNum(s[1]);
                            int col = s[2] - '0';
                            std::cout << tile->letter << ":" << row <<","<<col<<std::endl;
                            //check if the current tile exists, and if that location is empty and
                            if(tempCopyHand->hasTile(tile) && board->getSquare(row,col) == ' '){
                                std::cout<<"player has that tile in hand and that spot is empty!\n";
                                //check if the tile placed has other tiles around it, place it, put the coordinates in the vector
                                if(board->getSquare(row+1,col) != ' ' || board->getSquare(row-1,col) != ' ' || board->getSquare(row,col+1) != ' ' || board->getSquare(row,col-1) != ' '){
                                    std::cout<<"tile(s) around that spot, legal spot to place!";
                                    board->placeTile(tile,row,col);
                                    tempCopyHand->delTile(tile);
                                }else{
                                    legal = false;
                                }
                            }else{
                                legal = false;
                            }
                        }
                    }
                    //check if tiles are on the same row
                    if(legal){
                        std::cout<<"check if on the sam row or col\n";
                        int rowCompare = rows[0];
                        bool sameRow = true;
                        int colCompare = cols[0];
                        bool sameCol = true;
                        for(int i : rows){
                            if(i != rowCompare){
                                sameRow = false;
                            }
                        }
                        for(int i : cols){
                            if(i != colCompare){
                                sameCol = false;
                            }
                        }
                        if(sameRow || sameCol){
                            std::cout<<"all legal! place tiles\n";
                            int index = 0;
                            for(Tile* tile : tiles){
                                currentPlayer->placeTile(tile, rows[0], cols[0]);
                                currentPlayer->drawTile(tileBag->getRandomTile());
                                index++;
                            }
                        }
                    }else{
                        std::cout << "illegal, cannot place tiles\n";
                        int index = 0;
                        for(int row: rows){
                            board->placeTile(nullptr,row,cols[0]);
                            index++;
                        }
                    }
                    check = true;
                }else{
                    std::cout<<"Invalid Command!" << std::endl;  
                }
            }else if(input.find("at") != std::string::npos){
                for(char c : input){
                    if(c != ' '){
                        tokens.push_back(c);
                    }
                }
                if(tokens.size() == 5 && isupper(tokens[0])&& isupper(tokens[3]) && isdigit(tokens[4])){ //check if is XatXX
                    std::string tileString = "";
                    tileString+=tokens[0]; //add tile letter X
                    tileString+=tokens[3]; //add tile row letter
                    tileString+=tokens[4]; //add tile col
                    placedTiles.push_back(tileString);                  
                }else{
                    std::cout<<"Wrong format!\n";
                }
            }else{
                std::cout << "Wrong format!\n";
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
    gameover = gameOver();

    }
    quit();
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
    if(tileBag->getNumOfTiles() == 0){
        for(Player* player : players){
            if(player->getHand()->getNumOfTiles() == 0){
                check = true;
            }else if(player->getpassTime() == 2){
                check = true;
            }
        }
    }
    return check;
}
void GameEngine::quit(){
    exit(EXIT_SUCCESS);
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
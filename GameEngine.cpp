#include "GameEngine.h"
#include <iostream>

GameEngine::GameEngine(){
    tileBag = nullptr;
    board = nullptr;
    currentPlayerIndex = 0;
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
    tileBag->readTileBagFromFile();
    board = new Board();
    //hand
    for(Player* player : players){
        tileBag->initiateHand(player->getHand());
    }
}

void GameEngine::newGame(){
    bool gameover = false;
    while(!gameover){
    Player* currentPlayer = players[currentPlayerIndex];
    std::cout<<currentPlayer->getName()<<", it's your turn" << std::endl;
    for(Player* player : players){
        std::cout<<"Score for " << player->getName() << ": " << player->getScore() << std::endl;
    }
    Tile* test = new Tile();
    test->letter = 'Q';
    board->placeTile(test,8,8);
    
    std::cout << board->printBoard();
    std::cout << "Your hand is\n" << currentPlayer->getHand()->printHand();
    std::string input = "";
    bool check = false;

    //get user input

    std::vector<std::string> placedTiles;
    Hand* tempCopyHand = new Hand(*currentPlayer->getHand());

    std::vector<Tile*> tiles; //tile to store all the tile object
    std::vector<int> rows; //to store all rows
    std::vector<int> cols; //to store all cols
    // bool legal = true; //assume the placement is legal
    while (!check){
        bool legal = true;
        std::cin.clear();
        std::vector<char> tokens;
        std::cout << "> ";
        std::getline(std::cin, input);
        if(input.find("replace") != std::string::npos){
            input.erase(0,7);
            for(char c : input){
                if(c != ' '){
                    tokens.push_back(c);
                }
            }
            if(tokens.size() == 1){
                if(isupper(tokens[0])){
                    Tile* tile = new Tile();
                    tile->letter = tokens[0];
                    tile->value = tile->getValue(tokens[0]);
                    if(replaceTile(tile)){
                        currentPlayer->setPassTime(0);
                        check = true;
                    }
                }
            }
        }else if(input.find("place") != std::string::npos){
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
                                if(isupper(board->getSquare(row+1,col))|| isupper(board->getSquare(row-1,col)) || isupper(board->getSquare(row,col+1)) || isupper(board->getSquare(row,col-1))){
                                    std::cout<<"tile(s) around that spot, legal spot to place!";
                                    board->placeTile(tile,row,col);
                                    tempCopyHand->delTile(tile);
                                    rows.push_back(row);
                                    cols.push_back(col);
                                    tiles.push_back(tile);
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
                        std::cout<<"check if on the same row or col\n";
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
                        std::cout << "finish checking\n";
                        if(sameRow || sameCol){
                            std::cout<<"all legal! place tiles\n";
                            for(Tile* tile : tiles){
                                currentPlayer->placeTile(tile);
                                currentPlayer->drawTile(new Tile(*tileBag->getTile(0)));
                            }
                        }
                        check = true;
                        int add = 0;
                        if(sameRow){
                            add = calculateScore(rows, cols, 0);
                        }else if(sameCol){
                            add = calculateScore(rows, cols, 1);
                        }
                        if(tiles.size() == MAX_HAND_SIZE){
                            std::cout << "BINGO!" << std::endl;
                            add += 50;
                        }
                        int finalScore = add + currentPlayer->getScore();
                        currentPlayer->setScore(finalScore);
                        // switchPlayer();
                    }else{
                        std::cout << "illegal, cannot place tiles\n";

                        int index = 0;
                        placedTiles.clear();
                        for(int row: rows){
                            board->placeTile(nullptr,row,cols[0]);
                            index++;
                        }
                        rows.clear();
                        cols.clear();
                        for(Tile* tile : tiles){
                            delete tile;
                            tiles.pop_back();
                        }
                    }
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
        }else if(input.find("pass") != std::string::npos){
            currentPlayer->pass();
            check = true;
            // switchPlayer();
        }else if(input.find("save") != std::string::npos){
            input.erase(0,4);
            std::string fileName = "";
            std::vector<char> tokens;
            for(char c : input){
                if(c != ' '){
                    tokens.push_back(c);
                }
            }
            if(tokens.size() != 0){
                for(char c : tokens){
                    fileName += c;
                }
                saveGame(fileName);
            }else{
                std::cout << "Enter file name!\n"; 
            }

        }else{
            std::cout << "Invalid Input!" << std::endl;
        }
    }
    //check if game ends;
    gameover = gameOver();
    switchPlayer();
    }
    endGame();
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
void GameEngine::switchPlayer(){
    if(currentPlayerIndex < (int)players.size()){
        currentPlayerIndex++;
    }
    if(currentPlayerIndex == (int)players.size()){
        currentPlayerIndex = 0;
    }
}
void GameEngine::setPlayerScore(Player* player, int score){
    player->setScore(score);
}
void GameEngine::setPlayerName(Player* player, std::string name){
    player->setName(name);
}

void GameEngine::placeTile(Tile* tile, int row, int col){

}
int GameEngine::calculateScore(std::vector<int> rows,std::vector<int> cols, int direction){
    int score = 0;
    Tile* temp = new Tile();
    int row = rows[0];
    int col = cols[0];
    //horizontal
    if(direction == 0){
        bool check = true;
        while(check){
            if(isupper(board->getSquare(row,col))){
                score += temp->getValue(board->getSquare(row,col));
                row--;
            }else{
                check = false;
            }
        }
        row = rows[0];
        col = cols[0];
        check = true;
        while(check){
            if(isupper(board->getSquare(row,col))){
                score += temp->getValue(board->getSquare(row,col));
                row++;
            }else{
                check = false;
            }
        }
        row = rows[0];
        col = cols[0];
        //check vertical direction
        for(int row : rows){
            check = true;
            while(check){
                if(isupper(board->getSquare(row,col))){
                score += temp->getValue(board->getSquare(row,col));
                col++;
                }else{
                    check = false;
                }
            }
            row = rows[0];
            col = cols[0];
            check = true;
            while(check){
                if(isupper(board->getSquare(row,col))){
                score += temp->getValue(board->getSquare(row,col));
                col--;
                }else{
                    check = false;
                }
            }
        }
    } //vertical
    else if(direction == 1){
        
        bool check = true;
        while(check){
            if(isupper(board->getSquare(row,col))){
                score += temp->getValue(board->getSquare(row,col));
                col--;
            }else{
                check = false;
            }
        }
        row = rows[0];
        col = cols[0];
        check = true;
        while(check){
            if(isupper(board->getSquare(row,col))){
                score += temp->getValue(board->getSquare(row,col));
                col++;
            }else{
                check = false;
            }
        }
        row = rows[0];
        col = cols[0];
        //check horizontal direction
        for(int row : rows){
            check = true;
            while(check){
                if(isupper(board->getSquare(row,col))){
                score += temp->getValue(board->getSquare(row,col));
                row++;
                }else{
                    check = false;
                }
            }
            row = rows[0];
            col = cols[0];
            check = true;
            while(check){
                if(isupper(board->getSquare(row,col))){
                score += temp->getValue(board->getSquare(row,col));
                row--;
                }else{
                    check = false;
                }
            }
        }
    }
    delete temp;
    return score;
}
bool GameEngine::replaceTile(Tile* tile){
    bool check = false;
    if(tileBag->getNumOfTiles() > 0){
        tileBag->addTile(tile);
        if(!players[currentPlayerIndex]->replaceTile(tile, tileBag->getTile(0))){
            std::cout << "That tile is not in player's hand!" << std::endl;
        }else{
            check = true;
        }
    }else{
        std::cout << "No tile in the bag, cannot replace!"<< std::endl;
    }
    return check;
}
Tile* GameEngine::drawTile(){
    Tile* tile = nullptr;
    if(tileBag->getNumOfTiles() > 0){
        tile = tileBag->getTile(0);
    }
    return tile;
}

std::string GameEngine::displayBoard(){
    //todo
    return "";
}

void GameEngine::saveGame(std::string fileName){
    std::ofstream file(fileName);
    if(file.is_open()){
        for(Player* player : players){
            file << player->getName() << std::endl << player->getScore() << std::endl;
            file << player->getHand()->printHand();
        }
        
        file<< board->printBoard();
        file << tileBag->printTileBag();
        file << players[currentPlayerIndex]->getName() << std::endl;
        std::cout << "Game saved successfully!" << std::endl;
        file.close();
    }
}
bool GameEngine::loadGame(std::string fileName){
    bool check = false;
    // if file not exist
    std::ifstream file(fileName);
    if (!file.good()) {
        std::cout << "File does not exist!" << std::endl;
        check = false;
    }
    
    for(Player* player : players){
        if(player != nullptr){
            delete player;
        }
    }
    try {
        if (file.is_open()) {
            Player* player1 = new Player();
            Player* player2 = new Player();
            board = new Board();
            tileBag = new TileBag();

            std::string line;
            getline(file, line);
            player1->setName(line);
            getline(file, line);
            player1->setScore(std::stoi(line));
            getline(file, line);
            //load hand
            //split by ,
            //use add Tile
            player1->loadHand(line);
            
            getline(file, line);
            player2->setName(line);
            getline(file, line);
            player2->setScore(std::stoi(line));
            getline(file, line);
            player2->loadHand(line);

            players.push_back(player1);
            players.push_back(player2);
            //load board
            std::cout << "load board\n";
            //skip first two lines
            //erase first 4 characters, split by '|'
            //compare with '   ' three spaces
            file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            file.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            std::vector<Tile*> boardStatus;
            std::string temp = "";
            for(int i = 0; i < DEFAULT_DIMENSION; ++i){
                getline(file, line);
                line.erase(0,4);
                for(char c : line){
                    if (c == '|') {
                        if(temp.compare("   ") == 0){
                            boardStatus.push_back(nullptr);
                        }else{
                            Tile* tile = new Tile();
                            tile->letter = temp.at(1);
                            tile->value = tile->getValue(tile->letter);
                            boardStatus.push_back(tile);
                        }
                        temp = "";
                    }else {
                        temp.push_back(c);
                    }
                }
            }
            int row = 0;
            int col = 0;
            for(Tile* tile : boardStatus){
                board->placeTile(tile,row,col);
                col++;
                if(col == 15){
                    row++;
                    col=0;
                }
            }

            //load tilebag
            getline(file,line);
            temp = "";
            for(char c : line){
                if(c == ','){
                    Tile* tile = new Tile();
                    tile->letter = temp.at(0);
                    tile->value = temp.at(2) - '0';
                    tileBag->addTile(tile);
                    temp = "";
                }else{
                    temp.push_back(c);
                }
            }


            //get current player
            getline(file, line);
            if(player1->getName().compare(line) != 0){
                currentPlayerIndex++;
            }
            file.close();
            check = true;
        }
    } catch (const std::exception &e) {
        std::cout << "Incorrect file format!" << std::endl;
    }
    return check;
}
bool GameEngine::gameOver(){
    bool check = false;
    if(tileBag->getNumOfTiles() == 0){
        for(Player* player : players){
            if(player->getHand()->getNumOfTiles() == 0){
                check = true;
            }else if(player->getpassTime() >= 2){
                check = true;
            }
        }
    }
    return check;
}
void GameEngine::endGame(){
    std::cout << "Game over\n";
    int max = 0;
    Player* winner = nullptr;
    for(Player * player : players){
        int score = player->getScore();
        std::cout << "Score for " << player->getName() << ": " << score;
        if(score > max){
            max = score;
            winner = player;
        }
    }
    //a tied game?
    std::cout << "Player " << winner->getName() << " won!";
    quit();
}
void GameEngine::quit(){
    std::cout << "Goodbye\n";
    exit(EXIT_SUCCESS);
}
int GameEngine::convertLetterToNum(char letter){
    int n = letter;
    return n - 'A';
}
bool GameEngine::checkPlayerNameValidity(std::string name){
    bool check = true;
    if(name == ""){
        check = false;
    }
    for(char c : name){
        if(!isupper(c)){
            check = false;
        }
    }
    return check;
}
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
    bool centre = false;
    while(!gameover){
    //check if centre is occupied
    if(isupper(board->getSquare(7,7))){
        centre = true;
    }else{
        centre = false;
    }
    Player* currentPlayer = players[currentPlayerIndex];
    std::cout<<currentPlayer->getName()<<", it's your turn" << std::endl;
    for(Player* player : players){
        std::cout<<"Score for " << player->getName() << ": " << player->getScore() << std::endl;
    }
    std::cout << board->printBoard();
    std::cout << "Your hand is\n" << currentPlayer->getHand()->printHand();
    std::string input = "";
    //used to check if the input is correct
    bool check = false;

    //to store all the placed tiles in this round
    std::vector<std::string> placedTiles;
    //a temporary copy of hand to modify, instead of modyfiing the actual hand
    Hand* tempCopyHand = new Hand(*currentPlayer->getHand());

    //tile to store all the tile object
    std::vector<Tile*> tiles; 
    //to store all rows
    std::vector<int> rows;
    //to store all cols 
    std::vector<int> cols; 
    /* When input place, the user should ALWAY input in this format:
     * "place <single upper case letter> at <single upper case letter><number>"
     * which means place <a tile> at <row><col>
     * for example: place A at J8
     * bad examples: place A at 1, place A, place A at J
     */
    while (!check){
        //bool for checking if player's placing is legal or not
        bool legal = true;
        std::cin.clear();
        std::vector<char> tokens;
        std::cout << "> ";
        std::getline(std::cin, input);
        if(input == "quit"){
            quit();
        }
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
                //check if place DONE is correctly formatted (size of DONE is 4) 
                if(tokens.size() == 4){
                    //check and make sure there is something to place!!
                    if(placedTiles.size() > 0){
                        for(std::string s : placedTiles){
                            std::cout << s<<"\n";
                            if(legal){
                                Tile* tile = new Tile();
                                tile->letter = s.at(0);
                                tile->value = tile->getValue(tile->letter);
                                int row = convertLetterToNum(s[1]);
                                int col = 0;
                                //if col is one digit e.g LA1
                                if(s.size() == 3){
                                    col = s.at(2) - '0';
                                }
                                //if col is two digits e.g LA10
                                else if(s.size() == 4){
                                    col = 10*(s.at(2)-'0') + (s.at(3) - '0');
                                }
                                std::cout << row << "," << col<<"\n";
                                //check if the current tile exists, and if that location is empty and
                                if(!centre && tempCopyHand->hasTile(tile)){
                                    std::cout << "centre not occupied\n";
                                    if(row == 7 && col == 7){
                                        board->placeTile(tile,row,col);
                                        tempCopyHand->delTile(tile);
                                        rows.push_back(row);
                                        cols.push_back(col);
                                        tiles.push_back(tile);
                                        centre = true;
                                    }else{
                                        std::cout<<"Place at the centre square H7!\n";
                                        legal = false;
                                    }
                                }
                                else if(tempCopyHand->hasTile(tile) && board->getSquare(row,col)==' '){
                                    //if the centre is occupied, check if the tile has other tiles around it
                                    if(isupper(board->getSquare(row+1,col))|| isupper(board->getSquare(row-1,col)) || isupper(board->getSquare(row,col+1)) || isupper(board->getSquare(row,col-1))){
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
                                    std::cout <<"wrong!shabi!\n";                  
                                }
                            }
                        }
                        //check if tiles are on the same row
                        if(legal){
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
                                for(Tile* tile : tiles){
                                    currentPlayer->placeTile(tile);
                                    //check if there is still tiles left in tilebag, if no, do not draw tile
                                    if(tileBag->getNumOfTiles() != 0){
                                        currentPlayer->drawTile(new Tile(*tileBag->getTile(0)));
                                        tileBag->removeFront();
                                    }
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
                        }else{
                            std::cout << "Illegal, cannot place tiles\n";
                            //reverse placed square onboard
                            int index = 0;
                            placedTiles.clear();
                            for(int row: rows){
                                board->placeTile(nullptr,row,cols[index]);
                                std::cout<<"reverse: " << row <<"," <<cols[index]<<"\n";
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
                }else{
                    std::cout<<"Invalid Command!" << std::endl;  
                }
            }else if(input.find("at") != std::string::npos){
                for(char c : input){
                    if(c != ' '){
                        tokens.push_back(c);
                    }
                }
                bool atSuccess = true;
                //check if the input is XatXX or XatX00
                if((tokens.size() == 5 || tokens.size() == 6) && isupper(tokens[0]) && isupper(tokens[3]) && isdigit(tokens[4])){
                    if(tokens.size() == 6 && !isdigit(tokens[5])){
                        atSuccess = false;
                    }
                }else{
                    atSuccess = false;
                }
                if(atSuccess){
                    std::string tileString = "";
                    //add tile letter X
                    tileString+=tokens[0];
                    //add tile row letter
                    tileString+=tokens[3];
                    //add tile col
                    tileString+=tokens[4];
                    if(tokens.size() ==6){
                        tileString+=tokens[5];
                    }
                    placedTiles.push_back(tileString);    
                }else{
                    placedTiles.clear();
                    std::cout << "Wrong format!\n";
                }
            }else{
                placedTiles.clear();
                std::cout << "Wrong format!\n";
            }
        }else if(input.find("pass") != std::string::npos){
            currentPlayer->pass();
            check = true;
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
    //switch to next player's round
    switchPlayer();
    delete tempCopyHand;
    }
    //game ends
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
    //go back to the first player
    if(currentPlayerIndex == (int)players.size()){
        currentPlayerIndex = 0;
    }
}

int GameEngine::calculateScore(std::vector<int> rows,std::vector<int> cols, int direction){
    int score = 0;
    Tile* temp = new Tile();
    int row = rows[0];
    int col = cols[0];
    //if the word is horizontal,0 = horizontal!!
    if(direction == 0){
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
        //do not calculate the original spot twice!
        col++;
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
    }
    else if(direction == 1){
        //if the word is vertical
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
    Tile* tileToBag = new Tile(*tile);
    Tile* replacement = new Tile(*tileBag->getTile(0));
    if(tileBag->getNumOfTiles() > 0){
        if(!players[currentPlayerIndex]->replaceTile(tile, replacement)){
            std::cout << "That tile is not in player's hand!" << std::endl;
            delete tileToBag;
            delete replacement;
        }else{
            check = true;
            tileBag->addTile(tileToBag);
            tileBag->removeFront();
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

void GameEngine::saveGame(std::string fileName){
    std::ofstream file(fileName);
    if(file.is_open()){
        for(Player* player : players){
            file << player->getName() << std::endl << player->getScore() << std::endl;
            file << player->getHand()->printHand();
        }
        
        file << board->printBoard();
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
    //if player is not empty, delete it
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
            //load hand, split by, call addTile()
            player1->loadHand(line);
            
            getline(file, line);
            player2->setName(line);
            getline(file, line);
            player2->setScore(std::stoi(line));
            getline(file, line);
            player2->loadHand(line);

            players.push_back(player1);
            players.push_back(player2);

            /* load board, skip first two lines.
             * I don't want to pass the file to a function therefore I didn't create a loadBoard() function in Board.h
             * erase first 4 characters, split by '|'
             * compare with '   ' three spaces */
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
            //assign tiles to the board
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
                    //convert char to int
                    if(temp.length() == 3){
                        tile->value = temp.at(2) - '0';
                    }else if(temp.length() == 4){
                        tile->value = 10*(temp.at(2) - '0') + (temp.at(3) - '0');
                    }
                    tileBag->addTile(tile);
                    temp = "";
                }else{
                    temp.push_back(c);
                }
            }
            if(temp != ""){
                Tile* tile = new Tile();
                tile->letter = temp.at(0);
                if(temp.length() == 3){
                    tile->value = temp.at(2) - '0';
                }else if(temp.length() == 4){
                    tile->value = 10*(temp.at(2) - '0') + (temp.at(3) - '0');
                }
                tileBag->addTile(tile);
                temp = "";
            }


            //get current player
            getline(file, line);
            if(player1->getName().compare(line) != 0){
                currentPlayerIndex++;
            }
            file.close();
            check = true;
            std::cout << "Scrabble Game loaded successfully!" << std::endl;
        }
    } catch (const std::exception &e) {
        std::cout << "Incorrect file format!" << std::endl;
    }
    return check;
}
bool GameEngine::gameOver(){
    //check if the bag is empty
    bool check = false;
    if(tileBag->getNumOfTiles() == 0){
        for(Player* player : players){
            //check if a player's hand is empty or a player has passed his turn twice
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
        std::cout << "Score for " << player->getName() << ": " << score << std::endl;
        if(score > max){
            max = score;
            winner = player;
        }
    }
    //only if the score is higher than max score will it be kept, therefore if the two players achieve the same score, the first one is the winner
    std::cout << "Player " << winner->getName() << " won!" << std::endl;
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
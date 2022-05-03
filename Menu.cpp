#include "Menu.h"

Menu::Menu(){
    gameEngine = new GameEngine();
}
Menu::~Menu(){
    delete gameEngine;
}
void Menu::run(){
    std::cout << "Welcome to Scrabble!\n-------------------" << std::endl;
    int input = 0;
    do{
        printMenu();
        std::cout << "> ";
        std::cin >> input;
        if(!std::cin.good()){
            std::cout<<"Invalid Input!"<<std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } 
        else if(input == NEW_GAME){
            gameEngine->newGame();
            std::cout<< "Starting a New Name" << std::endl;
            //add 2 players
            //player name should only be letters
            std::string playerName = "";
            std::cout<< "Enter name for player 1:\n> ";
            std::cin >> playerName;
            //check name
            bool check = gameEngine->addPlayer(playerName);
            while(!check){
                std::cout<< "Enter a Valid Name!\n> ";
                std::cin >> playerName;
                check = gameEngine->addPlayer(playerName);
            }
            std::cout<< "Enter name for player 2:\n> ";
            gameEngine->addPlayer(playerName);
            //play
            std::cout << "Let's Play!" << std::endl;
            gameEngine->setupGame();
            // gameEngine->startGame();
        }
        else if(input == LOAD_GAME){
            std::cout<< "Enter the filename from which load a game" << std::endl;
            std::cout << "> ";
            std::string fileName = "";
            std::cin >> fileName;
            gameEngine->loadGame(fileName);
            //check file exists
            //check format
            //load game
            std::cout << "Scrabble game successfully loaded" << std::endl;
            
            //file does not exist
            std::cout << "File does not exist!" << std::endl;
        }
        else if(input == CREDITS){
            //display credits
            std::cout << "Name: Yuchen Wu" << std::endl;
            std::cout << "Student ID: S3776244" << std::endl;
            std::cout << "Email: s3776244@student.rmit.edu.au" << std::endl;
        }
        else if(input == QUIT){
            std::cout << "Goodbye" << std::endl;
        }
        else{
            //invalid input
            std::cout<<"Invalid Input!"<<std::endl;
        }
    }while(input != QUIT);
    
}

void Menu::printMenu(){
    std::cout << "Menu" << std::endl;
    std::cout << "----" << std::endl;
    std::cout << "1. New Game" << std::endl;
    std::cout << "2. Load Game" << std::endl;
    std::cout << "3. Credits (Show student information)" << std::endl;
    std::cout << "4. Quit" << std::endl;


}
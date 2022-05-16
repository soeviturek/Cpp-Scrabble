#include "Menu.h"

Menu::Menu(){
    gameEngine = new GameEngine();
}
Menu::~Menu(){
    delete gameEngine;
}
const std::string Menu::newGame = "1";
const std::string Menu::loadGame = "2";
const std::string Menu::credit = "3";
const std::string Menu::quit = "4";

void Menu::run(){
    std::cout << "Welcome to Scrabble!\n-------------------" << std::endl;
    std::string input = "";
    do{
        printMenu();
        std::cout << "> ";
        std::getline(std::cin,input);
        if(!std::cin.good()){
            std::cout<<"Invalid Input!"<<std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } 
        else if(input == newGame){
            std::cout<< "Starting a New Name" << std::endl;
            //enter loop and get names for 2 players
            for(int i = 0; i < 2;++i){
                std::cout<< "Enter name for player "<< i+1<<":\n";
                bool check = false;
                while(!check){
                    std::cout << "> ";
                    std::string name = "";
                    getline(std::cin, name);
                    if(gameEngine->addPlayer(name)){
                        check = true;
                    }else{
                        std::cout << "Please Enter a Valid Name!\n";
                        check =false;
                    }
                }
                
            }
            //play
            std::cout << "Let's Play!" << std::endl;
            gameEngine->setupGame();
            gameEngine->newGame();
        }
        else if(input == loadGame){
            std::cout<< "Enter the filename from which load a game" << std::endl;
            std::cout << "> ";
            std::string fileName = "";
            std::cin >> fileName;
            if(gameEngine->loadGame(fileName)){
                gameEngine->newGame();
            }
        }
        else if(input == credit){
            //display credits
            std::cout << "Name: Yuchen Wu" << std::endl;
            std::cout << "Student ID: S3776244" << std::endl;
            std::cout << "Email: s3776244@student.rmit.edu.au" << std::endl;
        }
        else if(input == quit){
            //quit
            gameEngine->quit();
        }
        else{
            //invalid input
            std::cout<<"Invalid Input!"<<std::endl;
        }
    }while(input != quit);
    
}

void Menu::printMenu(){
    std::cout << "Menu" << std::endl;
    std::cout << "----" << std::endl;
    std::cout << "1. New Game" << std::endl;
    std::cout << "2. Load Game" << std::endl;
    std::cout << "3. Credits (Show student information)" << std::endl;
    std::cout << "4. Quit" << std::endl;


}
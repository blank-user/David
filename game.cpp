#include "game.hpp"

#include <iostream>
#include <random>

const int ENDSTATE = -1;
const int SINGLEPLAYER = 1;
const int MULTIPLAYER = 2;

void Game::menu(){
    initialize();
    while(_terminate == false){
        int mode = -1;
        int options = -1;
        
        while(1){
            std::cout << "Connect 4" << std::endl;
            std::cout << "-----------" << std::endl;
            std::cout << "1. Start Game" << std::endl;
            std::cout << "2. ..." << std::endl; // additional option -----------------------------------------
            std::cout << "3. Exit" << std::endl;
            std::cout << "Please select an option: ";
            
            std::cin >> options;
            
            if(!(options == 1 || options == 2 || options == 3)){
                std::cout << "Invalid option." << std::endl;
            }else{
                break;
            }
        }
        
        switch(options){
            case 1:
                while(1){
                    std::cout << "Please select a game mode:" << std::endl;
                    std::cout << "1. Single Player" << std::endl;
                    std::cout << "2. Multiplayer" << std::endl;
                    
                    std::cin >> mode;
                    
                    if(!(mode == SINGLEPLAYER || mode == MULTIPLAYER)){
                        std::cout << "Invalid option." << std::endl;
                    }else{
                        break;
                    }
                }
                
                Game::run(mode);
                
                break;
            case 2:
                // additional option -----------------------------------------------------------
                break;
            case 3:
                return;
        }
    }
}

void Game::run(int mode){
    _currentPlayer = rand()%2;
    
    board.initializeBoard();
    
    board.printBoard();
    
    while(_state != ENDSTATE){
        // terminate game when turn count reaches a certain number ----------------- make a turn count...
        
        std::pair<int, int> move;
        
        if(mode == SINGLEPLAYER){
            
            if(_currentPlayer == FIRSTPLAYER){
                move = getPlayerMove(_currentPlayer);
                
            }else{
                getAIMove();
                
            }
            
            
        }else{
            move = getPlayerMove(_currentPlayer);
            
        }
        
        board.printBoard();
        
        if(board.checkCounter(move.first, move.second)){
            std::cout << "Player " << _currentPlayer << " wins." << std::endl;
            break;
        }
        
        changePlayer();
    }
}

void Game::initialize(){
    _terminate = false;
}

std::pair<int, int> Game::getPlayerMove(int counter){
    int place;
    
    std::pair<int, int> ret = std::make_pair(-1, -1);
    while(ret.first == -1){
        std::cout << "Place a counter (0 - 6): " << std::endl;
        std::cin >> place;
        ret = board.placeCounter(place, counter);
        if(ret.first == -1){
            std::cout << "Invalid move." << std::endl;
        }
    }
    
    return ret;
}

void Game::getAIMove(){
    
}

void Game::changePlayer(){
    _currentPlayer = !_currentPlayer;
}
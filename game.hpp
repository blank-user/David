#ifndef game_hpp
#define game_hpp

#include <iostream>

#include "board.hpp"
#include "minimax.hpp"

const int FIRSTPLAYER = 0;
const int SECONDPLAYER = 1;

class Game{
public:
    void menu();
    
private:
    Board board;
    
    bool _currentPlayer;
    bool _terminate;
    int _state;
    
    void run(int mode);
    void initialize();
    void changePlayer();
    std::pair<int, int> getPlayerMove(int counter);
    void getAIMove();
};

#endif

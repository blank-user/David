#ifndef board_hpp
#define board_hpp

#include <iostream>

const int CONNECT = 4;
const int PAD = CONNECT*2;
const int HEIGHT = 6;
const int WIDTH = 7;

class Board{
public:
    void debug();
    
    void initializeBoard();
    void printBoard();
    bool checkCounter(int y, int x);
    int getValue(int h, int w){
        return _grid[h+PAD/2][w+PAD/2];
    }
    void setValue(int h, int w, int value){
        _grid[h][w] = value;
    }
    std::pair<int, int> placeCounter(int w, int value);

private:
    int _grid[HEIGHT+PAD][WIDTH+PAD];
    int directionY[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
    int directionX[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
};


#endif
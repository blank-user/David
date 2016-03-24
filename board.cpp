#include "board.hpp"

const int EMPTY = -1;
const int CROSS = 0;
const int CIRC = 1;

void Board::initializeBoard(){
    for(int i = 0; i < HEIGHT+PAD; i++){
        for(int j = 0; j < WIDTH+PAD; j++){
            _grid[i][j] = EMPTY;
        }
    }
}

std::pair<int, int> Board::placeCounter(int w, int value){
    if(w < 0 || w > WIDTH-1){
        goto end;
    }
    w+=PAD/2;
    for(int i = HEIGHT+PAD/2-1; i >= PAD/2; i--){
        if (_grid[i][w] == EMPTY){
            setValue(i, w, value);
            
            std::cout << i << " " << w << std::endl;
            
            return std::make_pair(i, w);
        }
    }
end:
    return std::make_pair(-1, -1);
}

bool Board::checkCounter(int y, int x){
    std::cout << "check " << y << " " << x << std::endl;
    int current = _grid[y][x];
    bool check = false;
    int tempY = y;
    int tempX = x;
    for(int i = 0; i < 8; i++){
        y = tempY;
        x = tempX;
        for(int j = 1; j < CONNECT; j++){
            y+=directionY[i];
            x+=directionX[i];
            if(current != _grid[y][x]){
                break;
            }
            if(j == CONNECT-1){
                check = true;
            }
        }
    }
    
    return check;
}

void Board::printBoard(){
    for(int i = PAD/2; i < HEIGHT+PAD/2; i++){
        for(int j = PAD/2; j < WIDTH+PAD/2; j++){
            switch(_grid[i][j]){
                case EMPTY:
                    std::cout << " - ";
                    break;
                case CROSS:
                    std::cout << " X ";
                    break;
                case CIRC:
                    std::cout << " O ";
                    break;
            }
        }
        std::cout << std::endl;
    }
}

void Board::debug(){
    for(int i = 0; i < HEIGHT + PAD; i++){
        for(int j = 0; j < WIDTH + PAD; j++){
            std::cout << _grid[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
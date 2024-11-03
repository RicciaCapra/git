#include "TrisGrid.h"

TrisGrid::TrisGrid(){
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            grid[i][j] = ' ';
        }
    }
}

bool TrisGrid::insertMove(int row, int column, char player){
    if (grid[row][column] == ' '){
        grid[row][column] = player;
        moves += 1;
        return true;
    }else{
        return false;
    }
};

int TrisGrid::trisCheck(int row, int column){
    bool winner = false;
    int const victory = 0;
    int const notTheEndOfTheGame = 1;
    int const gameEnd = 2; 

    if(moves >= 9){
        return gameEnd;
    }else if (moves >= 5){
        if(row%2 == 0 && column%2 == 0){
            winner = this -> rowCheck(row);
            winner = winner || this -> columnCheck(column);
            winner = winner || this -> diagonalCheck(row, column);
        }else if(row%2 == column%2){
            winner = this -> rowCheck(row);
            winner = winner || this -> columnCheck(column);
            winner = winner || this -> diagonalCheck(row - 1, column - 1);
            winner = winner || this -> diagonalCheck(row - 1, column + 1);
        }else{
            winner = this -> rowCheck(row);
            winner = winner || this -> columnCheck(column);
        }

        if(winner){
            return victory;
        }
    }

    return notTheEndOfTheGame;
};

bool TrisGrid::rowCheck(int row){
    if(grid[row][0] == grid[row][1] && grid[row][1] == grid[row][2]){
        return true;
    }

    return false;
};

bool TrisGrid::columnCheck(int column){
    if(grid[0][column] == grid[1][column] && grid[1][column] == grid[2][column]){
        return true;
    }

    return false;
};

bool TrisGrid::diagonalCheck(int row, int column){
    if(row == column){
        if(grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2]){
            return true;
        }
    }else{
        if(grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0]){
            return true;
        }
    }

    return false;
};
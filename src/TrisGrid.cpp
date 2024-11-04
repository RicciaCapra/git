#include "TrisGrid.h"

namespace TRIS {

    bool TrisGrid::rowsCheck(){
        bool check = false;

        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 2; j++){
                if(grid[j][i] == grid[j + 1][i]) check = check || true;
            }
            if(check) return true;
            check = false;
        }

        return false;
    };

    bool TrisGrid::columnsCheck(){
        bool check = false;

        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 2; j++){
                if(grid[i][j] == grid[i][j + 1]) check = check || true;
            }
            if(check) return true;
            check = false;
        }

        return false;
    };

    bool TrisGrid::diagonalsCheck(){
        
        if(grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2]){
            return true;
        }

        if(grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0]){
            return true;
        }
    
        return false;
    };

    GridState TrisGrid::playerSwitch(){
        if(moves % 2 == 1){
            return PLAYER_1;
        } else{
            return PLAYER_2;
        }
    }

    TrisGrid::TrisGrid(){
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                grid[i][j] = ' ';
            }
        }
    }

    void TrisGrid::getGrid(char get[3][3]){
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                get[i][j] = grid[i][j];
            }
        }
    }

    bool TrisGrid::insertMove(int row, int column){
        if (grid[row][column] == ' '){
            moves += 1;
            
            if(this->playerSwitch() == PLAYER_1){
                grid[row][column] = 'X';
            } else {
                grid[row][column] = 'O';
            }

            return true;
        }else{
            return false;
        }
    };

    GridState TrisGrid::trisCheck(){
        bool winner = false;
        int const victory = 0;
        int const notTheEndOfTheGame = 1;
        int const gameEnd = 2; 

        if(moves >= 9){
            return END;
        }else if (moves >= 5){
            winner = this -> rowsCheck();
            winner = winner || this -> columnsCheck();
            winner = winner || this -> diagonalsCheck();

            if(winner){
                return this -> playerSwitch();
            }
        }

        return PLAYING;
    };
}
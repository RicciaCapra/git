#include <iostream>
#include <cstdlib>

using namespace std;

class Tris{
    public:
    char grid[3][3];
    int moves = 0;

    Tris(){
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                grid[i][j] = '-';
            }
        }
    }

    void Info(){
        cout << "---- The Tris Game ----" << endl
             << "Player 1 will be X, while Player 2 will be O." << endl
             << "In each turn you'll be asked to insert row and column of the position where you wnat to place your mark, so let's start!" << endl << endl;
    }

    void gridStamp(){
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                cout << grid[i][j] << "\t";
            }
            cout << endl; 
        }
    };

    bool insertMove(int row, int column, char player){
        if (grid[row][column] == '-'){
            grid[row][column] = player;
            moves += 1;
            cout << moves;
            return true;
        }else{
            return false;
        }
    };

    int trisCheck(int row, int column){
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

    bool rowCheck(int row){
        if(grid[row][0] == grid[row][1] && grid[row][1] == grid[row][2]){
            return true;
        }

        return false;
    };

    bool columnCheck(int column){
        if(grid[0][column] == grid[1][column] && grid[1][column] == grid[2][column]){
            return true;
        }

        return false;
    };

    bool diagonalCheck(int row, int column){
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

};

int main(){
    Tris Grid;
    int row, column;
    const char player1 = 'X';
    const char player2 = 'O';
    bool check = false;

    Grid.Info();

    while(Grid.trisCheck(row, column) != 2){
        
        while(!check){    
            cout << endl;
            Grid.gridStamp();
            cout << "Player " << player1 << ", please insert row and column:\nrow\t";
            cin >> row;
            cout << "column\t";
            cin >> column;
            
            row -= 1;
            column -= 1;

            check = Grid.insertMove(row, column, player1);
        }
        check = false;

        if(Grid.trisCheck(row, column) == 0){
            cout << "Player 1 has won!" << endl;
            Grid.gridStamp();
            break;
        }else if(Grid.trisCheck(row, column) == 2){
            cout << "No one has won!" << endl;
            Grid.gridStamp();
            break;
        }

        while(!check){
            cout << endl;
            Grid.gridStamp();
            cout << "Player " << player2 << ", please insert row and column:\nrow\t";
            cin >> row;
            cout << "column\t";
            cin >> column;
            
            row -= 1;
            column -= 1;

            check = Grid.insertMove(row, column, player2);
        }
        check = false;

        if(Grid.trisCheck(row, column) == 0){
            cout << "Player 2 has won!" << endl;
            Grid.gridStamp();
            break;
        }

    }

    return 0;
}

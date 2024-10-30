#include <iostream>
#include <cstdlib>
#include "TrisGrid.h"

using namespace std;

int main(){
    TrisGrid Grid;
    int row, column;
    const char player1 = 'X';
    const char player2 = 'O';
    bool check = false;

/* 
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
*/
    return 0;
}

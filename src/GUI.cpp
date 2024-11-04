#include "raylib.h"

#include <vector>

#include <cstdlib>

#include <iostream>

#include "TrisGrid.h"

using namespace std;

using namespace TRIS;







int main() {
    TrisGrid Grid;
    int row, column;
    const char player1 = 'X';
    const char player2 = 'O';
    bool check = false;
    
    const int grid_size_x = 3;
    const int grid_size_y = 3;

    const int screen_width = 300;
    const int screen_height = 300;
    
    const int square_width = screen_width/grid_size_x;
    const int square_height = screen_height/grid_size_y;

    InitWindow(screen_width, screen_height, "Snake");

    SetTargetFPS(60);


    int mouse_x;
    int mouse_y;

    char current_player;


    while (!WindowShouldClose()) {

        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            mouse_x = GetMouseX();
            mouse_y = GetMouseY();

            int row = mouse_x/square_width;
            int column = mouse_y/square_height;

            /*
            cout << row << " " << column << " " << Grid.moves << endl;

            cout << Grid.grid[0][0] << Grid.grid[0][1] << Grid.grid[0][2] << endl <<
                    Grid.grid[1][0] << Grid.grid[1][1] << Grid.grid[1][2] << endl <<
                    Grid.grid[2][0] << Grid.grid[2][1] << Grid.grid[2][2] << endl;

            */

            switch (Grid.playerSwitch()) {
                case PLAYER_1: current_player = player1;
                break;

                case PLAYER_2: current_player = player2;
                break;
            }
            
            char current_player = (Grid.playerSwitch() == 1) ? player1 : player2;

            Grid.insertMove(row, column);

            switch (Grid.trisCheck()) {
                case PLAYER_1:
                    cout << current_player << " wins! (O Green, X Blue)";
                    exit(1);
                case PLAYER_2:
                    cout << current_player << " wins! (O Green, X Blue)";
                    exit(1);
                case END:
                    cout << "Draw!";
                    exit(1);
            }

        }


        BeginDrawing();

        ClearBackground(RAYWHITE);

        char grid[3][3];

        Grid.getGrid(grid);

        for (int i = 0; i < grid_size_x; i++) {
            for (int j = 0; j < grid_size_y; j++) {
                Color col = grid[i][j] == player2 ? GREEN : (grid[i][j] == player1 ? BLUE : GRAY);
                DrawRectangle (i*square_width, j*square_height, square_width, square_height, col);
                DrawRectangleLines(i * square_width, j * square_height, square_width, square_height, BLACK);
            }
        }

        EndDrawing();
    }
    return 0;
}
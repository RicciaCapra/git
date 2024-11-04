#ifndef TRISGRID_H
#define TRISGRID_H

namespace TRIS {

    enum GridState {
        PLAYING,
        WIN_PL
    };

    class TrisGrid{
        public:
        char grid[3][3];
        int moves = 0;

        TrisGrid();

        bool insertMove(int row, int column, char player);

        int trisCheck(int row, int column);

        bool rowCheck(int row);

        bool columnCheck(int column);

        bool diagonalCheck(int row, int column);

    };

}


#endif
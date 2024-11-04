#ifndef TRISGRID_H
#define TRISGRID_H

namespace TRIS {

    typedef enum {
        PLAYING,
        PLAYER_1,
        PLAYER_2,
        END
    } GridState;

    class TrisGrid{
        private:
        char grid[3][3];
        int moves = 0;

        bool rowsCheck();

        bool columnsCheck();

        bool diagonalsCheck();


        public:
        TrisGrid();

        GridState playerSwitch();
        
        void getGrid(char get[3][3]);

        bool insertMove(int row, int column);

        GridState trisCheck();

    };

}


#endif
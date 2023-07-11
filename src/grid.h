#pragma once
#include<vector>
#include<raylib.h>

class Grid
{
    public:
        Grid();
        void Initialize();
        void Print();
        bool IsCellOutside(int row, int cloumn);
        bool IsCellEmpty(int row, int cloumn);
        int ClearFullRows();
        int grid[20][10];
        void Draw();

    private:
        bool IsRowFull(int row);
        void ClearRow(int row);
        void MoveRowDown(int row, int numRows);
        int numRows;
        int numCols;
        int cellSize;
        std::vector<Color> colors;
};
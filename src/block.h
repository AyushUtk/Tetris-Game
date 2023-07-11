#pragma once
#include <vector>
#include <map>
#include "position.h"
#include "colors.h"

class Block
{
    public:
        Block();
        void Draw(int offSetX, int offSetY);
        void Move(int rows, int columns);
        void Rotate();
        void UndoRotate();
        std::vector<Position> GetCellPosition();
        std::map<int,std::vector<Position>> cells;
        int id;
    private:
        int cellSize;
        int rotationState;
        std::vector<Color> colors;
        int rowOffset;
        int columnOffset;
};

#include "block.h"

Block::Block()
{
    cellSize=30;
    rotationState=0;
    colors=GetCellColors();
    rowOffset=0;
    columnOffset=0;
}

void Block::Draw(int offSetX, int offSetY)
{
    std::vector<Position> tiles = GetCellPosition();
    for(Position item: tiles)
    {
        DrawRectangle(item.column*cellSize+offSetX, item.row*cellSize+offSetY, cellSize-1, cellSize-1, colors[id]);
    }
}

void Block::Move(int rows, int columns)
{
    rowOffset+=rows;
    columnOffset+=columns;
}

void Block::Rotate()
{
    rotationState++;
    if(rotationState==(int)cells.size())
    {
        rotationState=0;
    }
}

void Block::UndoRotate()
{
    rotationState--;
    if(rotationState==-1)
    {
        rotationState+=(int)cells.size();
    }
}

std::vector<Position> Block::GetCellPosition()
{
    std::vector<Position> tiles =  cells[rotationState];
    std::vector<Position> movedTiles;
    for(Position item: tiles)
    {
        Position newPos= Position(item.row+rowOffset,item.column+columnOffset);
        movedTiles.push_back(newPos);
    }
    return movedTiles;
}

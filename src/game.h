#pragma once
#include "grid.h"
#include "Blocks.cpp"

class Game
{
    public:
        Game();
        ~Game();
        void Draw();
        void HandleInput();
        void MoveBlockDown();
        bool gameOver;
        int score;
        Music music;
    private:
        void LockBlock();
        std::vector<Block> GetAllBlocks();
        Block GetRandomBlock();
        void MoveBlockLeft();
        void MoveBlockRight();
        bool IsBlockOutside();
        void RotateBlock();
        bool BlockFits();
        void Reset();
        void UpdateScore(int linesCleared, int moveDownPoints);
        std::vector<Block> blocks;
        Block currentBlock;
        Block nextBlock;
        Grid grid;
        Sound rotateSound;
        Sound clearSound;
};
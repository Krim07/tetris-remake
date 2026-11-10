#pragma once
#include "blocks.cpp"
#include "grid.h"

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
	Grid grid;
	Block GetRandomBlock();
	std::vector<Block> GetAllBlocks();
	
	void MoveBlockLeft();
	void MoveBlockRight();
	
	void UpdateScore(int linesCleared, int moveDownPoints);
	void Reset();
	void LockBlock();
	void RotateBlock();
	bool IsBlockOutside();
	Block currentBlock;
	Block nextBlock;
	std::vector<Block> blocks;
	bool BlockFits();
	Sound rotateSound;
	Sound clearSound;

	
};
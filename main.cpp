#include "raylib.h"
#include "game.h"
#include <iostream>


double lastUpdateTime = 0;
bool eventTriggered(double interval)
{
	double currentTime = GetTime();
	if (currentTime - lastUpdateTime >= interval)
	{
		lastUpdateTime = currentTime;
		return true;
	}
	return false;
}


int main()
{
	const int screenWidth = 500;
	const int screenHeight = 620;
	InitWindow(screenWidth, screenHeight, "Tetris Game");
	SetTargetFPS(60);
	Game game = Game();
	while (!WindowShouldClose()) {
		UpdateMusicStream(game.music);
		game.HandleInput();
		if (eventTriggered(0.2))
		{
			game.MoveBlockDown();
		}		
		BeginDrawing();
		ClearBackground(DARKBLUE);
		DrawText("Score", 365, 15, 38, WHITE);
		DrawText("Next", 370, 175, 38, WHITE);
		if (game.gameOver) 
		{
			DrawText("GAME OVER", 320, 450, 28, WHITE);
		}
		DrawRectangleRounded({ 320, 55, 170, 60 }, 0.3, 6, SKYBLUE);

		char scoreText[10];
		sprintf_s(scoreText, " % d", game.score);
		int textSize = MeasureText(scoreText, 38);

		DrawText(scoreText, 320 + (170 - textSize)/2, 65, 38, WHITE);
		DrawRectangleRounded({ 320, 215, 170, 180 }, 0.3, 6, SKYBLUE);
		game.Draw();

		EndDrawing();
	}
	CloseWindow();
}
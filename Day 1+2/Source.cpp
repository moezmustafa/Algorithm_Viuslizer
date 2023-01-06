
#include "raylib.h"
#include "./Globals.h"
#include "./Menu.h"



int main()
{
	Global global;
	Menu menu;

	


	InitWindow(global.ScreenWidth, global.ScreenHeight, "Hello World");
	SetTargetFPS(global.ScreenFPS);
	while (!WindowShouldClose())
	{
		BeginDrawing();
	
		// load ./assets/Background.png
		Texture2D background = LoadTexture("./assets/Background.png");
		// draw the background
		
		//display the background at the center of the screen
		DrawTexture(background, global.ScreenWidth / 2 - background.width / 2, global.ScreenHeight / 2 - background.height / 2, WHITE);

		menu.CloseButton(global);
		
		menu.AlgorithmButton(global);
		menu.DataStructureButton(global);

		

		//get position of the mouse and print the coordinates in pixels
		Vector2 mousePosition = GetMousePosition();
		DrawText(TextFormat("Mouse Position: (%i, %i)", (int)mousePosition.x, (int)mousePosition.y), 30, 30, 20, BLACK);
		

		
		





		DrawFPS(10, 10);

		EndDrawing();
	}
}
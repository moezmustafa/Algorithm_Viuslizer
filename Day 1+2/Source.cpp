
#include "raylib.h"
#include "./Globals.h"
#include "./Menu.h"



int main()
{
	Global global;
	Menu menu;

	


	InitWindow(global.ScreenWidth, global.ScreenHeight, "Algorithm and DataStructure Visualizer");
	SetTargetFPS(global.ScreenFPS);
	while (!WindowShouldClose())
	{
		BeginDrawing();
	
		ClearBackground(RAYWHITE);
		
	

		menu.CloseButton(global);
		
		menu.CenterButtons(global);
		//menu.DataStructureButton(global);

		

		//get position of the mouse and print the coordinates in pixels
		Vector2 mousePosition = GetMousePosition();
		DrawText(TextFormat("Mouse Position: (%i, %i)", (int)mousePosition.x, (int)mousePosition.y), 30, 30, 20, BLACK);
		

		
		
		
	//void DrawText("String text here ", int posX, int posY, int fontSize, Color color);
	DrawText("Hello World", 100, 100, 20, BLACK);





		DrawFPS(10, 10);

		EndDrawing();
	}
}
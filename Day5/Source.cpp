//


#include <iostream>
#include "raylib.h"

class Rectang
{
public:
	
	float x=0, y=0;
	int speed_x = 0, speed_y = 0;
	int width=0, height=0;

	void Draw()
	{
		DrawRectangle(x, y, width, height, RED);
	}

	void Move_reverse()
	{
		x -= speed_x;
		y -= speed_y;
	}

	void Move()
	{
		x += speed_x;
		y += speed_y;
		
		
	}

};

Rectang rectangle;

const int screenWidth = 800;
const int screenHeight = 450;


int main()
{
	// Initialization
	//--------------------------------------------------------------------------------------
	int screenWidth = 800;
	int screenHeight = 450;

	InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
	
	rectangle.width = 50;
	rectangle.height = 50;
	
	rectangle.x = screenWidth /3 ;
	rectangle.y = screenHeight/3;

	rectangle.speed_x = 2;
	rectangle.speed_y = 2;


	SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
	
	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		// Update
		//----------------------------------------------------------------------------------
		
		
		// implement the rectangle.Move() and rectangle.movereverse()
		// functions to make the rectangle move around the screen
		// and bounce off the edges.
		rectangle.Move();
		
		
		//----------------------------------------------------------------------------------
		// Draw
		//----------------------------------------------------------------------------------
		BeginDrawing();

		ClearBackground(RAYWHITE);

		rectangle.Draw();

		
			rectangle.Move_reverse();
		

		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	

	
}
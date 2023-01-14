//#include <iostream>
//#include "raylib.h"
//
//
//int ScreenWidth = 800;
//int ScreenHeight = 450;
//
//int x = 0;
//int y = 0;
//
//class Line
//{
//	
//public:
//	
//	Color color = BLACK;
//	Vector2 start;
//	Vector2 end;
//	
//	//Line();
//	
//	void linez(Vector2 start, Vector2 end, Color color)
//	{
//		this->start = start;
//		this->end = end;
//		this->color = color;
//	}
//	
//	void Draw_Line()
//	{
//		DrawLineEx(start, end, 2, color);
//	}
//	
//	int speed_x = 1;
//	int speed_y = 1;
//	
//	void Move_Line()
//	{
//		start.x += speed_x;
//		start.y += speed_y;
//		end.x += speed_x;
//		end.y += speed_y;
//	}
//	
//	void Check_Collision()
//	{
//		if (start.x >= ScreenWidth || start.x <= 0)
//		{
//			speed_x *= -1;
//		}
//		if (start.y >= ScreenHeight || start.y <= 0)
//		{
//			speed_y *= -1;
//		}
//	}
//	
//	
//	
//	
//};
//
//
//
//class Block
//{
//public:
//	Color color = RED;
//	int width = 50;
//	int height = 50;
//
//	int speed_x = 0;
//	int speed_y = 0;
//
//
//	
//	void Blocks(int x ,int y, Color color)
//	{
//		x = x;
//		y = y;
//		this->color = color;
//	}
//	
//	
//	void Draw_Block()
//	{
//		DrawRectangle(x, y, width, height, color);
//	}
//	
//	void Move_Block_y()
//	{
//		y += speed_y;
//
//		if (y == ScreenHeight - height)
//		{
//			speed_y = 0;
//			for (int i = 0; i < 10; i++)
//			{
//				if (x == i * 50 && x != ScreenHeight - width)
//				{
//					x += 50;
//				}
//				else if (x == ScreenHeight - width)
//				{
//					x = 0;
//				}
//				{
//					speed_x = 1;
//				}
//			}
//		}
//	}
//	
//	// move the block by incrementing the x and y values
//	void Move_Block()
//	{
//		x += speed_x;
//		//y += speed_y;
//
//		if(x == 400)
//		{
//			speed_x = 0;
//			Move_Block_y();
//		}
//	}
//	
//	
//	
//
//	
//
//
//};
//
//// array of 5 lines and 5 blocks
////Line lines[5];
//
//
//
//
//
//int main()
//{
//	InitWindow(ScreenWidth, ScreenHeight, "raylib [core] example - basic window");
//	
//
//	SetTargetFPS(60);
//
//	Block blocks[5];
//	
//	//an array of 5 lines
//	Line lines[5];
//
//	blocks[0].speed_x = 2;
//	blocks[0].speed_y = 2;
//
//	blocks[0].Blocks(100, 100, RED);
//	blocks[1].Blocks(200, 200, BLUE);
//	blocks[2].Blocks(300, 300, GREEN);
//	
//	// line to follow the block
//	lines[0].linez({ x + 25.0f, y + 25.0f }, { x + 25.0f, y + 25.0f }, BLACK);
//	
//
//	while (!WindowShouldClose())
//	{
//
//		blocks[0].Move_Block();
//
//		
//
//		
//	
//		
//		
//		
//		BeginDrawing();
//		ClearBackground(RAYWHITE);
//		
//		blocks[0].Draw_Block();
//		
//		lines[0].Draw_Line();
//		lines[1].Draw_Line();
//		lines[2].Draw_Line();
//		lines[3].Draw_Line();
//		lines[4].Draw_Line();
//		
//		
//		
//		
//		
//
//		
//		
//		
//
//		
//
//		
//		
//
//		
//		
//
//		EndDrawing();
//	}
//
//	CloseWindow();
//
//	return 0;
//}

#include "raylib.h"


int ScreenWidth = 800;
int ScreenHeight = 450;

class ball
{
public:
	float radius = 30.0f;
	
	int speed_x = 1;
	int speed_y = 1;

	float x = 0;
	float y = 0;

	Color color = BLACK;

	void Ball(float x, float y, Color color)
	{
		this->x = x;
		this->y = y;
		this->color = color;
	}

	void Draw_Ball()
	{
		DrawCircle(x, y, radius, color);
	}

	void Move_Ball()
	{
		x += speed_x;
		y += speed_y;
	}
	
	void Check_Collision()
	{
		if (x >= ScreenWidth || x <= 0)
		{
			speed_x *= -1;
		}
		if (y >= ScreenHeight || y <= 0)
		{
			speed_y *= -1;
		}
	}
};

int main()
{
	InitWindow(ScreenWidth, ScreenHeight, "Bouncing Balls Animation Test");

	//SetTargetFPS(60);

	ball balls[10];

	balls[0].Ball(100, 100, BLACK);
	balls[1].Ball(240, 200, BLACK);
	balls[2].Ball(320, 300, BLACK);
	balls[3].Ball(450, 400, BLACK);
	balls[4].Ball(510, 500, BLACK);
	balls[5].Ball(600, 600, BLACK);
	balls[6].Ball(770, 700, BLACK);
	balls[7].Ball(810, 800, BLACK);
	balls[8].Ball(900, 900, BLACK);
	balls[9].Ball(10, 100, BLACK);
	

	while (!WindowShouldClose())
	{
		balls[0].Move_Ball();
		balls[1].Move_Ball();
		balls[2].Move_Ball();
		balls[3].Move_Ball();
		balls[4].Move_Ball();
		balls[5].Move_Ball();
		balls[6].Move_Ball();
		balls[7].Move_Ball();
		balls[8].Move_Ball();
		balls[9].Move_Ball();
		
		for (int i = 0; i < 10; i++)
		{
			balls[i].Check_Collision();
		}

		/*balls[0].Check_Collision();
		balls[1].Check_Collision();
		balls[2].Check_Collision();
		balls[3].Check_Collision();
		balls[4].Check_Collision();
		balls[5].Check_Collision();
		balls[6].Check_Collision();
		balls[7].Check_Collision();
		balls[8].Check_Collision();
		balls[9].Check_Collision();*/
		

		BeginDrawing();
		ClearBackground(RAYWHITE);

		balls[0].Draw_Ball();
		balls[1].Draw_Ball();
		balls[2].Draw_Ball();
		balls[3].Draw_Ball();
		balls[4].Draw_Ball();
		balls[5].Draw_Ball();
		balls[6].Draw_Ball();
		balls[7].Draw_Ball();
		balls[8].Draw_Ball();
		balls[9].Draw_Ball();
		

		EndDrawing();
	}

	CloseWindow();

	return 0;
}
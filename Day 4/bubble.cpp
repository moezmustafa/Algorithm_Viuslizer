
#include "raylib.h"
#include <iostream>





class bars
{
public:
	int height; // also the value
	int width;
	int x;
	int y;
	bool isSorted;
	Color color = RED;
};

//array of size 10 of bars
bars arr[15];



int main()
{
	// Initialization
	//--------------------------------------------------------------------------------------
	int screenWidth = 800;
	int screenHeight = 450;


	//fill array with random numbers
	for (int i = 0; i < 15; i++)
	{
		arr[i].height = (rand() % 100) + 50;
	}


	bool done = false;
	int counter = 0;

	// the arr now have random vlaues for heights


	InitWindow(screenWidth, screenHeight, "Test case 15 for selection sort");

	//SetTargetFPS(60);
	//--------------------------------------------------------------------------------------

	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		// Update
		//----------------------------------------------------------------------------------

		//----------------------------------------------------------------------------------
		// Draw
		//----------------------------------------------------------------------------------
		BeginDrawing();

		ClearBackground(RAYWHITE);

		//print the array
		for (int i = 0; i < 15; i++)
		{
			DrawText(TextFormat("%i", arr[i]), 10 + (i * 50), 10, 20, BLACK);
			DrawRectangle(10 + (i * 50), 40, 40, arr[i].height, arr[i].color);
		}


		SetTargetFPS(3);


		bool sorted = false;
		while (!sorted)
		{
			sorted = true;
			for (int i = 0; i < 15 - 1; i++)
			{
				//print on rectangle then pause then print again
				//for (int i = 0; i < 15; i++)
				//{
					//for (int j = i + 1; j < 15; j++)
					//{
				if (arr[i].height > arr[i + 1].height)
				{
					// Swap the elements
					int temp = arr[i].height;
					arr[i] = arr[i + 1];
					arr[i + 1].height = temp;

					// Set sorted to false to indicate that more passes are needed
					sorted = false;
					/*
				if (arr[j].height < arr[i].height)
				{
					int temp = arr[j].height;
					arr[j].height = arr[i].height;
					arr[i].height = temp;
					*/
					if (counter == 15)
					{
						arr[14].color = GREEN;
					}

					counter++;
					//logic for isSorted
					if (arr[i].isSorted == false)
					{
						arr[i].isSorted = true;

						if (arr[i].isSorted == true)
						{
							arr[i].color = GREEN;
						}

					}
					else
					{
						arr[i].isSorted = false;
					}

					//change color



					//print the array
					for (int k = 0; k < 15; k++)
					{
						DrawText(TextFormat("%i", arr[k].height), 10 + (k * 50), 10, 20, BLACK);
						DrawRectangle(10 + (k * 50), 40, 40, arr[k].height, arr[k].color);
					}
					EndDrawing();
					BeginDrawing();
					ClearBackground(RAYWHITE);
				}
			}


			// if last index of array is sorted then done is true
			if (arr[13].isSorted == true)
			{
				done = true;
			}
			else
			{
				done = false;
			}

			if (done == true)
			{
				//void DrawText(const char *text, int posX, int posY, int fontSize, Color color);
				DrawText("Sorted", 10, 150, 20, BLACK);
			}
			else
			{
				DrawText("Not Sorted", 10, 150, 20, BLACK);
			}



		}


		//print message if sorted


		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------
	CloseWindow();        // Close window and OpenGL context
	//--------------------------------------------------------------------------------------

	return 0;
}
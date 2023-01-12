#include <iostream>
#include "raylib.h"

using namespace std;

class Block_Node_Of_linked_list
{
    //attributes :
    /*
    1- data in the form of int , this will be displayed via DrawRectangle( ) and DrawText( )
    2- pointer to the next node , this will be linking to the next node .
    3- DrawLine( ) , takes the x and y of the current node and the next node . so each node must have a x and y value
    4- speed_x and speed_y , this will be used to move the node .
    5- x and y , this will be used to draw the node .
    6- color , this will be used to draw the node .
    7- 
    */

	//methods :
	/*
	1- constructor , takes the data and the next node .
	
	*/

public:

    //1 - Data value 
	int data;
	//2 - pointer to the next node
	Block_Node_Of_linked_list* next_node;
	//3 - DrawLine( ) , takes the x and y of the current node and the next node . so each node must have a x and y value
	Vector2 current_node;
	//4 - speed_x and speed_y , this will be used to move the node .
	int speed_x;
	int speed_y;
	//5 - width and height , this will be used to draw the node .
	int width = 40 ;
	int height = 40;
	//6 - color , this will be used to draw the node .
	Color color = RED;

	//other data points that are not that necessary but are yet required 
	int line_Thickness = 3;
	



};

// head_pointer of the linked list
Block_Node_Of_linked_list* head = NULL;

//values for resolution of the screen , these will be initialized in the Globals.h files 
int screen_width = 800;
int screen_height = 600;

//Target Fps vlaue , will also be in the globals.h file
int fps_value = 60;


int main()
{
 
	InitWindow(screen_width, screen_height, "Linked Lists");
	
	SetTargetFPS(fps_value);

	// draw the window 
	while (!WindowShouldClose)
	{
        BeginDrawing();
        ClearBackground(WHITE);
        EndDrawing();
		
	}
	
	
}
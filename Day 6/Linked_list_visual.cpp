

#include <iostream>
#include "raylib.h"

using namespace std;

int initial_pos_x = 100;
int initial_pos_y = 100;

bool stopper = false;

int value_for_new_node = 0;

class Linked_List_Node {
public:
	//basic stuff for the linked list 
	int data;
	Linked_List_Node* next;


	//stuff for the visuals
	int width = 50;
	int height = 50;
	Color self_color = RED;

	// position and the coordinates , the to_be_passed will be given to the DrawRectangle( ) 
	// The self_position will be used to draw the line between the nodes , and to align the coming new nodes 
	int to_be_passed_X = initial_pos_x;
	int to_be_passed_Y = initial_pos_y;

	int self_position_X;
	int self_position_Y;

	// speed and animation variables
	int speed_X = 0;
	int speed_Y = 0;



	// status indicators  , using these as the flags that will alow to keep the stauts of nodes in check
	bool is_selected = NULL;
	bool is_moving = NULL;
	bool is_placed_under = NULL;
	bool is_placed = NULL;

	// - - - - Functions - - - - 

	//constructor
	Linked_List_Node()
	{
		// the node will be created with the default values 

	}

	// insert a new nnod at the beginning of the list




	void Move_Node()
	{
		// the speed will be added to the position of the node , and the node will be moved 
		self_position_X += speed_X;
		self_position_Y += speed_Y;
	}




};

// Global HEAD of the Linked List 

Linked_List_Node* HEAD = NULL;


void Insert_New_Node(int data)
{
	Linked_List_Node* temp = new Linked_List_Node();
	temp->data = data;
	temp->next = HEAD;
	HEAD = temp;

	initial_pos_x += 100;

}

void Draw()
{
	Linked_List_Node* temp = HEAD;
	while (temp != NULL)
	{


		DrawRectangle(temp->to_be_passed_X, temp->to_be_passed_Y, temp->width, temp->height, temp->self_color);
		DrawText(TextFormat("%i", temp->data), temp->to_be_passed_X + 20, temp->to_be_passed_Y + 20, 20, BLACK);

		// if end of the list is reached , break the loop
		if (temp != NULL)
		{
			stopper = false;
		}

		temp = temp->next;



	}
}

int main()
{

	// Initialization
	//--------------------------------------------------------------------------------------
	int screenWidth = 1920;
	int screenHeight = 450;

	InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

	SetTargetFPS(60);
	//--------------------------------------------------------------------------------------
	/*Insert_New_Node(41);
	Insert_New_Node(22);
	Insert_New_Node(43);
	Insert_New_Node(4);*/
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

		DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);




		// insert 5 nodes in the linked 





		// display the value of Value_for_new_node with text "value_for_new_node :"
		DrawText(TextFormat("Value_for_new_node : %i", value_for_new_node), 100, 200, 20, BLACK);

		// if the stopper is true , revoke the Draw() function
		if (stopper == false)
		{
			Draw();
		}
		else {
			DrawText("The stopper is true", 100, 100, 20, BLACK);
		}


		// draw the lines between the nodes
		// DrawLine(node1->self_position_X + node1->width / 2, node1->self_position_Y + node1->height / 2, node2->self_position_X + node2->width / 2, node2->self_position_Y + node2->height / 2, BLACK);
		// DrawLine(node2->self_position_X + node2->width / 2, node2->self_position_Y + node2->height / 2, node3->self_position_X + node3->width / 2, node3->self_position_Y + node3->height / 2, BLACK);
		// DrawLine(node3->self_position_X + node3->width / 2, node3->self_position_Y + node3->height / 2, node4->self_position_X + node4->width / 2, node4->self_position_Y + node4->height / 2, BLACK);
		// DrawLine(node4->self_position_X + node4->width / 2, node4->self_position_Y + node4->height / 2, node5->self_position_X + node5->width / 2, node5->self_position_Y + node5->height / 2, BLACK);
		// DrawLine(node5->self_position_X + node4->width / 2, node5->self_position_Y + node5->height / 2, node5->self_position_X + node5->width / 2, node5->self_position_Y + node5->height / 2, BLACK);

		// draw the data of the nodes
		// DrawText(TextFormat("%i", node1->data), node1->self_position_X + node1->width / 2 - 5, node1->self_position_Y + node1->height / 2 - 10, 20, BLACK);
		// DrawText(TextFormat("%i", node2->data), node2->self_position_X + node2->width / 2 - 5, node2->self_position_Y + node2->height / 2 - 10, 20, BLACK);
		// DrawText(TextFormat("%i", node3->data), node3->self_position_X + node3->width / 2 - 5, node3->self_position_Y + node3->height / 2 - 10, 20, BLACK);
		// DrawText(TextFormat("%i", node4->data), node4->self_position_X + node4->width / 2 - 5, node4->self_position_Y + node4->height / 2 - 10, 20, BLACK);
		// DrawText(TextFormat("%i", node4->data), node5->self_position_X + node5->width / 2 - 5, node5->self_position_Y + node5->height / 2 - 10, 20, BLACK);

		//Create a button with the text "Add Node" at the bottom left corner of the screen
		Rectangle button = { 0, 400, 100, 50 };
		DrawRectangleRec(button, BLACK);
		DrawText("Add Node", 10, 410, 20, WHITE);

		// 5 rectangles , with 5 values if the button is clicked , set value of value_for_new_node to the value of the button
		Rectangle button1 = { 0, 0, 100, 50 };
		DrawRectangleRec(button1, BLACK);
		DrawText("1", 10, 10, 20, WHITE);

		Rectangle button2 = { 100, 0, 100, 50 };
		DrawRectangleRec(button2, BLACK);
		DrawText("2", 110, 10, 20, WHITE);

		Rectangle button3 = { 200, 0, 100, 50 };
		DrawRectangleRec(button3, BLACK);
		DrawText("3", 210, 10, 20, WHITE);

		Rectangle button4 = { 300, 0, 100, 50 };
		DrawRectangleRec(button4, BLACK);
		DrawText("4", 310, 10, 20, WHITE);

		Rectangle button5 = { 400, 0, 100, 50 };
		DrawRectangleRec(button5, BLACK);
		DrawText("5", 410, 10, 20, WHITE);

		// if the mouse is over the button , change the color of the button to red
		if (CheckCollisionPointRec(GetMousePosition(), button1))
		{
			DrawRectangleRec(button1, RED);
			DrawText("1", 10, 10, 20, WHITE);
			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
			{
				value_for_new_node = 1;
			}
		}
		if (CheckCollisionPointRec(GetMousePosition(), button2))
		{
			DrawRectangleRec(button2, RED);
			DrawText("2", 110, 10, 20, WHITE);
			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
			{
				value_for_new_node = 2;
			}
		}
		if (CheckCollisionPointRec(GetMousePosition(), button3))
		{
			DrawRectangleRec(button3, RED);
			DrawText("3", 210, 10, 20, WHITE);
			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
			{
				value_for_new_node = 3;
			}
		}
		if (CheckCollisionPointRec(GetMousePosition(), button4))
		{
			DrawRectangleRec(button4, RED);
			DrawText("4", 310, 10, 20, WHITE);
			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
			{
				value_for_new_node = 4;
			}
		}
		if (CheckCollisionPointRec(GetMousePosition(), button5))
		{
			DrawRectangleRec(button5, RED);
			DrawText("5", 410, 10, 20, WHITE);
			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
			{
				value_for_new_node = 5;
			}
		}


		if (CheckCollisionPointRec(GetMousePosition(), button))
		{
			DrawRectangleRec(button, RED);
			DrawText("Add Node", 10, 410, 20, WHITE);
			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
			{
				Insert_New_Node(value_for_new_node);
			}
		}

		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------
	CloseWindow();        // Close window and OpenGL context
	//--------------------------------------------------------------------------------------

	return 0;


}
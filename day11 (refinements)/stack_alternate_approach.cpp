
#include <iostream>
#include <string>
#include "raylib.h"


int screen_width = 800;
int screen_height = 450;



// initital x and y coordinated to draw the stack at the center of the screen
int x = screen_width / 2;
int y = 20;

// bools 
bool top_button_state = false;
bool push_button_state = false;

using namespace std;

class Node_stack {

public:
    int Data;

    Node_stack* next;


    int width = 100;
    int height = 50;


    int value_of_y = y;



};

Node_stack* head = NULL;  // root node headers


// insert a new node at the beginning of the list
void push(int new_data)
{
    // allocate node
    Node_stack* new_node = new Node_stack();

    // put in the data
    new_node->Data = new_data;

    // link the old list off the new node
    new_node->next = head;

    new_node->value_of_y += y;
    // move the head to point to the new node
    head = new_node;
}


// delete the first node
void pop()
{
    // check for empty list
    if (head == NULL)
        return;

    // store head node
    Node_stack* temp = head;

    // move the head to the next node
    head = head->next;

    // free the old head
    free(temp);
}


int top()
{
	if (head == NULL)
		return -1;
	return head->Data;
}
    

// print the list with DrawRectangle and DrawText
void print()
{
    Node_stack* temp = head;
    while (temp != NULL) {


        DrawRectangle(x, temp->value_of_y, temp->width, temp->height, RED);
        DrawText(std::to_string(temp->Data).c_str(), x + 30, temp->value_of_y + 10, 20, WHITE);
        temp = temp->next;

        // increment the y coordinate of the next node to draw it below the previous node
        //y += 60;
    }
}


int random_number_gen()
{
	int random_number = rand() % 100 + 1;
	return random_number;
}

int main()
{

   /* push(1);
    y += 40;
    push(2);
    y += 40;
    push(3);
    y += 40;
    push(4);*/
    // Initialization
    //--------------------------------------------------------------------------------------


    InitWindow(screen_width, screen_height, "raylib [core] example - basic window");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        
        cout << "the values of the Y " << y << endl;

        // Update
        //----------------------------------------------------------------------------------
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------

        BeginDrawing();

        ClearBackground(RAYWHITE);

        print();

		// print the cursor position
		DrawText(std::to_string(GetMouseX()).c_str(), 10, 10, 20, BLACK);
		DrawText(std::to_string(GetMouseY()).c_str(), 10, 30, 20, BLACK);
        
		// draw line x = 390 y = 35 to x = 502 y = 35
		DrawLine(390, 35, 510, 35, BLACK);
		// draw a line from x = 390 y = 35 to x = 390 y = screen_height - 50
		DrawLine(390, 35, 390, screen_height - 50, BLACK);
		//Draw a line from x = 502 y = 35 to x = 502 y = screen_height - 50
		DrawLine(510, 35, 510, screen_height - 50, BLACK);
        //draw a rectangle on the bottom left corner with text "pop"
		DrawRectangle(0, screen_height - 50, 100, 50, BLUE);
		DrawText("pop", 30, screen_height - 40, 20, WHITE);
        
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			if (GetMouseX() >= 0 && GetMouseX() <= 100 && GetMouseY() >= screen_height - 50 && GetMouseY() <= screen_height)
			{
				pop();
                y -= 40;
				push_button_state = false;

			}
		}
        
		// draw a rectangle on the bottom right corner with text "push"
		DrawRectangle(screen_width - 100, screen_height - 50, 100, 50, BLUE);
		DrawText("push", screen_width - 70, screen_height - 40, 20, WHITE);
        
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			if (GetMouseX() >= screen_width - 100 && GetMouseX() <= screen_width && GetMouseY() >= screen_height - 50 && GetMouseY() <= screen_height)
			{
				if (push_button_state == false)
				{
					push(random_number_gen());
					y += 40;
	
				}
				
			}
		}

		// Draw a rectangle at the bottom center of the screen with text "top"
		DrawRectangle(screen_width / 2 - 50, screen_height - 50, 100, 50, BLUE);
		DrawText("top", screen_width / 2 - 20, screen_height - 40, 20, WHITE);
        
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            if (GetMouseX() >= screen_width / 2 - 50 && GetMouseX() <= screen_width / 2 + 50 && GetMouseY() >= screen_height - 50 && GetMouseY() <= screen_height)
            {
                
				top_button_state = true;

            }
        }

		if (top_button_state)
		{
			DrawRectangle(40 , screen_height - 200, 100, 50, BLUE);
			DrawText(std::to_string(top()).c_str(), 70 , screen_height - 190, 20, WHITE);
		}
        
		// if the vlaue of y is greater than screen height , display "stack overflow"
		if (y > 220)
		{
			DrawText("stack overflow", screen_width / 2 - 200, screen_height / 2 - 20, 20, BLACK);
            
            push_button_state = true;
		}
        

        EndDrawing();

        //----------------------------------------------------------------------------------


    }
}
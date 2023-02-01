
#include <iostream>
#include "raylib.h"

using namespace std;


int screen_width = 800;
int screen_height = 450;

int value_to_push = 0;
bool push_button_state = false;


//Headers for the funtions declared below the main 
void Ui_Number_Buttons();
void Ui_Push_Pop_Top_Buttons();
//Headers for the funtions declared below the main 

// stack class 
// stack class 
// stack class 


class Stack_Node {
public:
    int data;
    Stack_Node* next;

    int x;
    int y;

    Color color = RED;
};

Stack_Node* top = NULL;  // root node headers

class Stack {
public:
    Stack_Node* top;

    Stack() {
        top = NULL;
    }

    void push(int data) {
        Stack_Node* new_node = new Stack_Node();
        new_node->data = data;
        new_node->next = top;
        top = new_node;

        // update the values of the x and y coordinates of the new node
        new_node->x = screen_width / 2;
        new_node->y = screen_height / 2 - 70;

    }

    void pop() {
        if (top == NULL) {
            cout << "Stack is empty" << endl;
            return;
        }
        Stack_Node* temp = top;
        top = top->next;
        delete temp;
    }

    int top_value() {
        if (top == NULL) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return top->data;
    }

    bool is_empty() {
        return top == NULL;
    }

 

};


void Draw_Stack_Blocks()
{
    // draw the stack blocks inside the line segments

    while (top != NULL) {
   


    }
}

// stack class 
// stack class 
// stack class 




void Draw_Stack()
{

    // draw 3 line segments to form a upside down rectangle at the center of the screen
    
    //left line segment
    DrawLine(screen_width / 2 - 100, screen_height / 2 + 100, screen_width / 2 - 100, screen_height / 2 - 100, BLACK);
    
	
    
	// Right line segment
    DrawLine(screen_width / 2 + 100, screen_height / 2 - 100, screen_width / 2 + 100, screen_height / 2 + 100, BLACK);

	// Bottom line segment
	DrawLine(screen_width / 2 - 100, screen_height / 2 + 100, screen_width / 2 + 100, screen_height / 2 + 100, BLACK);

}


void value_to_push_block()
{
	
	// draw a rectangle at the right side of the screen to display the value to push
	DrawRectangle(screen_width / 2 + 200, screen_height / 2 - 50, 100, 50, RED);
    
	//draw a text at the center of the rectangle to display the value to push
	DrawText(TextFormat("%i", value_to_push), screen_width / 2 + 250, screen_height / 2 - 25, 20, WHITE);
}




int main()
{
    InitWindow(screen_width, screen_height, "Stack");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        
        //test code :::

        Stack stack_class_object;

        stack_class_object.push(1);
        stack_class_object.push(2);
        stack_class_object.push(3);

        Draw_Stack_Blocks();
        
        //test code :::

        Draw_Stack();
        
		value_to_push_block();

        Ui_Number_Buttons();
        Ui_Push_Pop_Top_Buttons();

        //display the value of value_to_push 
        DrawText(TextFormat("value_to_push: %i", value_to_push), 20, 100, 20, BLACK);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}


// Functions for the Ui 
// Functions for the Ui 
// Functions for the Ui 


void Ui_Number_Buttons()
{
    // dislpay 5 rectangles at the top of the screen
    // each rectangle will have a number on it
    // when the user clicks on a rectangle, the number will be added to the stack
    // the number will be displayed on the stack


    DrawRectangle(0, 0, 100, 50, BLACK);

    DrawText("1", 20, 20, 20, WHITE);

    // if the mouse is over the rectangle, change the color to red
    if (CheckCollisionPointRec(GetMousePosition(), { 0, 0, 100 , 50 }))
    {
        DrawRectangle(0, 0, 100, 50, RED);
        DrawText("1", 20, 20, 20, WHITE);
        // if the mouse is clicked, update the value_to_push variable
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            DrawRectangle(0, 0, 100, 50, GREEN);
            DrawText("1", 20, 20, 20, WHITE);
            value_to_push = 1;
        }
    }


    DrawRectangle(100, 0, 100, 50, BLACK);
    DrawText("2", 120, 20, 20, WHITE);

    if (CheckCollisionPointRec(GetMousePosition(), { 100, 0, 100 , 50 }))
    {
        DrawRectangle(100, 0, 100, 50, RED);
        DrawText("2", 120, 20, 20, WHITE);
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            DrawRectangle(100, 0, 100, 50, GREEN);
            DrawText("2", 120, 20, 20, WHITE);

            value_to_push = 2;
        }
    }

    DrawRectangle(200, 0, 100, 50, BLACK);
    DrawText("3", 220, 20, 20, WHITE);

    if (CheckCollisionPointRec(GetMousePosition(), { 200, 0, 100 , 50 }))
    {
        DrawRectangle(200, 0, 100, 50, RED);
        DrawText("3", 220, 20, 20, WHITE);
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            DrawRectangle(200, 0, 100, 50, GREEN);
            DrawText("3", 220, 20, 20, WHITE);

            value_to_push = 3;
        }
    }

    DrawRectangle(300, 0, 100, 50, BLACK);
    DrawText("4", 320, 20, 20, WHITE);

    if (CheckCollisionPointRec(GetMousePosition(), { 300, 0, 100 , 50 }))
    {
        DrawRectangle(300, 0, 100, 50, RED);
        DrawText("4", 320, 20, 20, WHITE);
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {

            DrawRectangle(300, 0, 100, 50, GREEN);
            DrawText("4", 320, 20, 20, WHITE);

            value_to_push = 4;
        }
    }

    DrawRectangle(400, 0, 100, 50, BLACK);
    DrawText("5", 420, 20, 20, WHITE);

    if (CheckCollisionPointRec(GetMousePosition(), { 400, 0, 100 , 50 }))
    {
        DrawRectangle(400, 0, 100, 50, RED);
        DrawText("5", 420, 20, 20, WHITE);
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            DrawRectangle(400, 0, 100, 50, GREEN);
            DrawText("5", 420, 20, 20, WHITE);

            value_to_push = 5;
        }
    }

}



void Ui_Push_Pop_Top_Buttons()
{


    // display 3 buttons at the bottom of the screen with space in between them
     // the first button will say "Push" and when clicked, the value_to_push variable will be added to the stack
     // the second button will say "Pop" and when clicked, the top value will be removed from the stack
     // the third button will say "Top" and when clicked, the top value will be displayed in the console

    DrawRectangle(0, 400, 100, 50, BLACK);
    DrawText("Push", 20, 420, 20, WHITE);

    if (CheckCollisionPointRec(GetMousePosition(), { 0, 400, 100 , 50 }))
    {
        DrawRectangle(0, 400, 100, 50, RED);
        DrawText("Push", 20, 420, 20, WHITE);
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            DrawRectangle(0, 400, 100, 50, GREEN);
            DrawText("Push", 20, 420, 20, WHITE);

			// set the value of push_button_state
            push_button_state = true;
            cout << "Push" << endl;
        }
    }

    DrawRectangle(200, 400, 100, 50, BLACK);
    DrawText("Pop", 220, 420, 20, WHITE);

    if (CheckCollisionPointRec(GetMousePosition(), { 200, 400, 100 , 50 }))
    {
        DrawRectangle(200, 400, 100, 50, RED);
        DrawText("Pop", 220, 420, 20, WHITE);
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {

            DrawRectangle(200, 400, 100, 50, GREEN);
            DrawText("Pop", 220, 420, 20, WHITE);

            cout << "Pop" << endl;
        }
    }

    DrawRectangle(400, 400, 100, 50, BLACK);
    DrawText("Top", 420, 420, 20, WHITE);

    if (CheckCollisionPointRec(GetMousePosition(), { 400, 400, 100 , 50 }))
    {
        DrawRectangle(400, 400, 100, 50, RED);
        DrawText("Top", 420, 420, 20, WHITE);
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            DrawRectangle(400, 400, 100, 50, GREEN);
            DrawText("Top", 420, 420, 20, WHITE);
            cout << "Top" << endl;
        }
    }



}
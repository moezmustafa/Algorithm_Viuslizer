#include<iostream>
#include "raylib.h"

using namespace std;


int ScreenWidth = 800;
int ScreenHeight = 450;

int node_value = 0;

// Functions headers for the UI elements 
void mouse_hove_on_buttons_state_color();
void mouse_click_state_value_setter();
void Drawing_the_buttons_at_top();




class Node {
public:
    int data;
    Node* left;
    Node* right;

    int x;
    int y;

    Color color = RED;
};







int main()
{
    InitWindow(ScreenWidth, ScreenHeight, "Binary Tree");
    SetTargetFPS(60);

    Node* root = NULL;

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);


        // 5 Buttons , with 5 DrawText Values , if hover over button , change color to green , if click node_value = button value
        //void DrawRectangle(int x, int y, int width, int height, Color color);

        Drawing_the_buttons_at_top();
        //if mouse is over button any button , change color to green

        mouse_hove_on_buttons_state_color();

        //if mouse is clicked , node_value = button value

        mouse_click_state_value_setter();


        // display the value of node_value
		DrawText(TextFormat("node_value = %i", node_value), 400, 200, 30, BLACK);



        EndDrawing();
    }

    CloseWindow();
    return 0;
}




/// all the ui related elements are at the bottom 


void Drawing_the_buttons_at_top()
{
    DrawRectangle(0, 0, 100, 50, BLACK);
    DrawText("1", 20, 20, 20, WHITE);
    DrawRectangle(100, 0, 100, 50, BLACK);
    DrawText("2", 100, 20, 20, WHITE);
    DrawRectangle(200, 0, 100, 50, BLACK);
    DrawText("3", 200, 20, 20, WHITE);
    DrawRectangle(300, 0, 100, 50, BLACK);
    DrawText("4", 300, 20, 20, WHITE);
    DrawRectangle(400, 0, 100, 50, BLACK);
    DrawText("5", 400, 20, 20, WHITE);
}




void mouse_hove_on_buttons_state_color()
{
    if (CheckCollisionPointRec(GetMousePosition(), { 0, 0, 100, 50 }))
    {
        DrawRectangle(0, 0, 100, 50, RED);
        DrawText("1", 20, 20, 20, WHITE);
    }
    if (CheckCollisionPointRec(GetMousePosition(), { 100, 0, 100, 50 }))
    {
        DrawRectangle(100, 0, 100, 50, RED);
        DrawText("2", 100, 20, 20, WHITE);
    }
    if (CheckCollisionPointRec(GetMousePosition(), { 200, 0, 100, 50 }))
    {
        DrawRectangle(200, 0, 100, 50, RED);
        DrawText("3", 200, 20, 20, WHITE);
    }
    if (CheckCollisionPointRec(GetMousePosition(), { 300, 0, 100, 50 }))
    {
        DrawRectangle(300, 0, 100, 50, RED);
        DrawText("4", 300, 20, 20, WHITE);
    }
    if (CheckCollisionPointRec(GetMousePosition(), { 400, 0, 100, 50 }))
    {
        DrawRectangle(400, 0, 100, 50, RED);
        DrawText("5", 400, 20, 20, WHITE);
    }
}


void mouse_click_state_value_setter()
{
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
    {
        if (CheckCollisionPointRec(GetMousePosition(), { 0, 0, 100, 50 }))
        {
            node_value = 1;
        }
        if (CheckCollisionPointRec(GetMousePosition(), { 100, 0, 100, 50 }))
        {
            node_value = 2;
        }
        if (CheckCollisionPointRec(GetMousePosition(), { 200, 0, 100, 50 }))
        {
            node_value = 3;
        }
        if (CheckCollisionPointRec(GetMousePosition(), { 300, 0, 100, 50 }))
        {
            node_value = 4;
        }
        if (CheckCollisionPointRec(GetMousePosition(), { 400, 0, 100, 50 }))
        {
            node_value = 5;
        }
    }
}
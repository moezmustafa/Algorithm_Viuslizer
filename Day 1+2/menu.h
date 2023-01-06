#pragma once 


#include "raylib.h"




class Menu
{
    public:

 
    // use the global.screenWidth and global.screenHeight to draw a circle on the top right corner of the screen
    void CloseButton(Global global)
    {
        // drawing the circle
        DrawCircle(global.ScreenWidth - 50,global.ScreenHeight/4 - 150 , 30, RED);

        //drawing the text inside the circle
        DrawText("Close[X]", global.ScreenWidth - 80, global.ScreenHeight / 4 - 160, 20, BLACK);

        //if the mouse is inside the circle, change the color of the circle to green
        if (CheckCollisionPointCircle(GetMousePosition(), { global.ScreenWidth - 50,global.ScreenHeight / 4 - 150 }, 30))
        {
            DrawCircle(global.ScreenWidth - 50, global.ScreenHeight / 4 - 150, 30, GREEN);
            //drawing text after it turns green
            DrawText("Close[X]", global.ScreenWidth - 80, global.ScreenHeight / 4 - 160, 20, BLACK);
        }
    }

    // use the global.screenWidth and global.screenHeight to draw a two rectangles parallel to each other in the middle of the screen with a gap in between
    void CenterButtons(Global global)
    {
        //drawing the first rectangle
        DrawRectangle(global.ScreenWidth / 2 - 200, global.ScreenHeight / 2 - 50, 200, 100, BLUE);
        // drawing text inside the rectangle
        DrawText("Algorithm", global.ScreenWidth / 2 - 110, global.ScreenHeight / 2 - 10, 20, BLACK);
        //if the mouse is inside the rectangle, change the color of the rectangle to green
        if (CheckCollisionPointRec(GetMousePosition(), { global.ScreenWidth / 2 - 200, global.ScreenHeight / 2 - 50, 200, 100 }))
        {
            DrawRectangle(global.ScreenWidth / 2 - 200, global.ScreenHeight / 2 - 50, 200, 100, GREEN);
            //drawing text after it turns green
            DrawText("Algorithm", global.ScreenWidth / 2 - 110, global.ScreenHeight / 2 - 10, 20, BLACK);

            //if the mouse is clicked, close the window
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                CloseWindow();
            }

        }


        // drawing the second rectangle
        DrawRectangle(global.ScreenWidth / 2 + 100, global.ScreenHeight / 2 - 50, 200, 100, BLUE);
        // drawing text inside the rectangle
        DrawText("Data Structure", global.ScreenWidth / 2 + 120, global.ScreenHeight / 2 - 10, 20, BLACK);
        //if the mouse is inside the rectangle, change the color of the rectangle to green
        if (CheckCollisionPointRec(GetMousePosition(), { global.ScreenWidth / 2 + 100, global.ScreenHeight / 2 - 50, 200, 100 }))
        {
            DrawRectangle(global.ScreenWidth / 2 + 100, global.ScreenHeight / 2 - 50, 200, 100, GREEN);
            //drawing text after it turns green
            DrawText("Data Structure", global.ScreenWidth / 2 + 120, global.ScreenHeight / 2 - 10, 20, BLACK);

            //if the mouse is clicked, close the window
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                CloseWindow();
            }
        }
    }




};
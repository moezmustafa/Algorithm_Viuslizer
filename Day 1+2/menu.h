#pragma once 


#include "raylib.h"




class Menu
{
    public:

    // function to draw a circle button to close the window
    void CloseButton(Global global)
    {
        
        // draw a circle button at the top right corner of the screen
        //--- Structure of ==> drawscircle(x, y, radius, color)
        DrawCircle(global.ScreenWidth - 60, 60, 30, RED);
        //underline text "Close[x]"
        DrawText("Close[x]", global.ScreenWidth - 100, 50, 20, BLACK);

        // if the cursor is on the circle, change its color to green and if clicked, close the window
        if (CheckCollisionPointCircle(GetMousePosition(), { global.ScreenWidth - 60, 60 }, 30))
        {
            DrawCircle(global.ScreenWidth - 60, 60, 30, GREEN);
            DrawText("Close[x]", global.ScreenWidth - 100, 50, 20, BLACK);

            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                CloseWindow();
            }
        }

    }

//    int div_algo_val_1 = 2; // x coordinate of the button
//    int div_algo_val_2 = 2.2;
//    //two buttons side by side with space at the center of the screen 
//     void AlgorithmButton(Global global)
//     {
//         // draw a rectangle button at the center of the screen
//         //--- Structure of ==> drawrectangle(x, y, width, height, color)
//         DrawRectangle(global.ScreenWidth / div_algo_val_1 - 100, global.ScreenHeight / div_algo_val_2 - 50, 200, 100, BLUE);
//         //underline text "Algorithms"
//         DrawText("Algorithms", global.ScreenWidth / div_algo_val_1 - 100, global.ScreenHeight / div_algo_val_2 - 50, 20, BLACK);

//         // if the cursor is on the rectangle, change its color to green and if clicked, close the window
//         if (CheckCollisionPointRec(GetMousePosition(), { global.ScreenWidth / div_algo_val_1 - 100, global.ScreenHeight / div_algo_val_2 - 50, 200, 100 }))
//         {
//             DrawRectangle(global.ScreenWidth / div_algo_val_1 - 100, global.ScreenHeight / div_algo_val_2 - 50, 200, 100, GREEN);
//             DrawText("Algorithms", global.ScreenWidth / div_algo_val_1 - 100, global.ScreenHeight / div_algo_val_2 - 50, 20, BLACK);

//             if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
//             {
//                 CloseWindow();
//             }
//         }
//     }

// draw the AlgorithmButton(Global global) function at x = 1200 and y = 500 
    void AlgorithmButton(Global global)
    {
        // draw a rectangle button at the center of the screen
        //--- Structure of ==> drawrectangle(x, y, width, height, color)
        DrawRectangle(1100, 500, 200, 100, BLUE);
        //underline text "Algorithms"
        DrawText("Algorithms", 1140, 540, 20, BLACK);

        // if the cursor is on the rectangle, change its color to green and if clicked, close the window
        if (CheckCollisionPointRec(GetMousePosition(), { 1100, 500, 200, 100 }))
        {
            DrawRectangle(1100, 500, 200, 100, GREEN);
            DrawText("Algorithms", 1140, 540, 20, BLACK);

            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                CloseWindow();
            }
        }
    }

    // int div_data_struct_val_1 = 4; // x coordinate of the button
    // int div_data_struct_val_2 = 3; // y coordinate of the button
    // void DataStructureButton(Global global)
    // {
    //     // draw a rectangle button at the center of the screen
    //     //--- Structure of ==> drawrectangle(x, y, width, height, color)
    //     DrawRectangle(global.ScreenWidth / div_data_struct_val_1 - 100, global.ScreenHeight / div_data_struct_val_2 + 50, 200, 100, BLUE);
    //     //underline text "Data Structures"
    //     DrawText("Data Structures", global.ScreenWidth / div_data_struct_val_1 - 100, global.ScreenHeight / div_data_struct_val_2 + 50, 20, BLACK);

    //     // if the cursor is on the rectangle, change its color to green and if clicked, close the window
    //     if (CheckCollisionPointRec(GetMousePosition(), { global.ScreenWidth / div_data_struct_val_1 - 100, global.ScreenHeight / div_data_struct_val_2 + 50, 200, 100 }))
    //     {
    //         DrawRectangle(global.ScreenWidth / div_data_struct_val_1 - 100, global.ScreenHeight / div_data_struct_val_2 + 50, 200, 100, GREEN);
    //         DrawText("Data Structures", global.ScreenWidth / div_data_struct_val_1 - 100, global.ScreenHeight / div_data_struct_val_2 + 50, 20, BLACK);

    //         if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
    //         {
    //             CloseWindow();
    //         }

    //     }
    // }

    // draw the DataStructureButton(Global global) function at x = 400 and y = 500
    void DataStructureButton(Global global)
    {
        // draw a rectangle button at the center of the screen
        //--- Structure of ==> drawrectangle(x, y, width, height, color)
        DrawRectangle(400, 500, 200, 100, BLUE);
        //underline text "Data Structures"
        DrawText("Data Structures", 410, 540, 20, BLACK);

        // if the cursor is on the rectangle, change its color to green and if clicked, close the window
        if (CheckCollisionPointRec(GetMousePosition(), { 400, 500, 200, 100 }))
        {
            DrawRectangle(400, 500, 200, 100, GREEN);
            DrawText("Data Structures", 410, 540, 20, BLACK);

            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                CloseWindow();
            }

        }
    }


};
#include <iostream>

#include "raylib.h"

using namespace std;


class bars 
{

public :
    int height ; // also the values from array
    int width = 40 ;

    Color color ;  // color of the bars

    int x ; // x position of the bars
    int y ; // y position of the bars 

    //half sorted color 
    Color halfSortedColor = PURPLE ;

    //sorted 
    Color sortedColor = GREEN ;


   



};


#define screenWidth 800
#define screenHeight 600

int array[8] = { 2 , 4 , 1 , 6 , 8 , 5 , 3 , 7   } ;


int main()
{
 // display window


    InitWindow(screenWidth, screenHeight, "Merge Sort");
    SetTargetFPS(60);

    

    //create an array of bars and fill the heights with random variables
    bars arr[10];

   //fill the array arr[10] with random numbers

    for (int i = 0 ; i < 10 ; i++)
    {
        arr[i].height = (rand() % 100) + 50;
    }

    // the arr now have random vlaues for heights

    //set the x and y positions of the bars
    for (int i = 0 ; i < 10 ; i++)
    {
        arr[i].x = 50 + (i * 80);
        arr[i].y = 500 - arr[i].height;
    }

    //set the color of the bars
    for (int i = 0 ; i < 10 ; i++)
    {
        arr[i].color = RED;
    }

    //set the color of the bars
    for (int i = 0 ; i < 10 ; i++)
    {
        arr[i].color = RED;
    }

    //set the color of the bars
    for (int i = 0 ; i < 10 ; i++)
    {
        arr[i].color = RED;
    }

    //set the color of the bars
    for (int i = 0 ; i < 10 ; i++)
    {
        arr[i].color = RED;
    }

    //set the color of the bars
    for (int i = 0 ; i < 10 ; i++)
    {
        arr[i].color = RED;
    }

    //set the color of the bars
    for (int i = 0 ; i < 10 ; i++)
    {
        arr[i].color = RED;
    }

    //set the color of the bars
    for (int i = 0 ; i < 10 ; i++)
    {
        arr[i].color = RED;
    }

    //set the color of the bars
    for (int i = 0 ; i < 10 ; i++)
    {
        arr[i].color = RED;
    }

    //set the color of the bars
    for (int i = 0 ; i < 10 ; i++)
    {
        arr[i].color = RED;
    }

    //set the color of the bars
    for (int i = 0 ; i < 10 ; i++)
    {
        arr[i].color = RED;
    }

    //set the color of the bars
    for (int i = 0 ; i < 10 ; i++)
    {
        arr[i].color = RED;
    }


    //display the bars
    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(WHITE);

        for (int i = 0 ; i < 10 ; i++)
        {
            DrawRectangle(arr[i].x, arr[i].y, arr[i].width, arr[i].height, arr[i].color);
        }

        //sort the bars and at each step display the bars using merge sort
    
        //merge sort code to sort array arr[8] and display the bars




        

        EndDrawing();
    }










}
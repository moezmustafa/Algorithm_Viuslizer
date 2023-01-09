#include <raylib.h>

int main()
{
    // Initialize the window
    int screenWidth = 800;
    int screenHeight = 450;
    InitWindow(screenWidth, screenHeight, "Animate Lines");
    SetTargetFPS(60);

    // Set the initial position and color of the lines
    Vector2 points[100];
    Color colors[100];
    for (int i = 0; i < 100; i++)
    {
        points[i] = {(float)GetRandomValue(0, screenWidth), (float)GetRandomValue(0, screenHeight)};
        colors[i] = (Color){(unsigned char)GetRandomValue(0, 255), (unsigned char)GetRandomValue(0, 255), (unsigned char)GetRandomValue(0, 255), 255};
    }

    // Set the speed of the lines
    Vector2 speed[100];
    for (int i = 0; i < 100; i++)
    {
        speed[i] = {(float)GetRandomValue(-5, 5), (float)GetRandomValue(-5, 5)};
    }

    // Main game loop
    while (!WindowShouldClose())
    {
        // Update the position of the lines
        for (int i = 0; i < 100; i++)
        {
            points[i].x += speed[i].x;
            points[i].y += speed[i].y;

            // Change the direction of the lines if they go off the screen
            if ((points[i].x > screenWidth) || (points[i].x < 0)) speed[i].x *= -1;
            if ((points[i].y > screenHeight) || (points[i].y < 0)) speed[i].y *= -1;
        }

        // Draw the lines
        BeginDrawing();
        ClearBackground(RAYWHITE);
        for (int i = 0; i < 100; i++)
        {
            DrawLine(points[i].x, points[i].y, points[i].x + 50, points[i].y + 50, colors[i]);
        }
        EndDrawing();
    }

    // Close the window
    CloseWindow();
    return 0;
}

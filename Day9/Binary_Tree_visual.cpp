#include <iostream>
#include "raylib.h"

using namespace std; 

int BT_int_value = 0;

class _Binary_Tree_Node
{
public:
    int data;
    _Binary_Tree_Node *left;
    _Binary_Tree_Node *right;

    int x;
    int y;

    Color color = RED;
};

void _Binary_Tree_visual(_Binary_Tree_Node *root, int x, int y, int level)
{
    if (root == NULL)
        return;

    root->x = x;
    root->y = y;

    _Binary_Tree_visual(root->left, x - 100 / level, y + 100, level + 1);
    _Binary_Tree_visual(root->right, x + 100 / level, y + 100, level + 1);
}

void _Binary_Tree_visual_draw(_Binary_Tree_Node *root)
{
    if (root == NULL)
        return;

    DrawCircle(root->x, root->y, 20, root->color);

    if (root->left != NULL)
    {
        DrawLine(root->x, root->y, root->left->x, root->left->y, root->color);
        _Binary_Tree_visual_draw(root->left);
    }

    if (root->right != NULL)
    {
        DrawLine(root->x, root->y, root->right->x, root->right->y, root->color);
        _Binary_Tree_visual_draw(root->right);
    }
}


void insert(_Binary_Tree_Node *root, int data)
{
    if (root == NULL)
    {
        root = new _Binary_Tree_Node();
        root->data = data;
        return;
    }

    if (data < root->data)
    {
        if (root->left == NULL)
        {
            root->left = new _Binary_Tree_Node();
            root->left->data = data;
            return;
        }
        else
        {
            insert(root->left, data);
        }
    }
    else
    {
        if (root->right == NULL)
        {
            root->right = new _Binary_Tree_Node();
            root->right->data = data;
            return;
        }
        else
        {
            insert(root->right, data);
        }
    }
}


int ScreenWidth = 800;
int ScreenHeight = 600;

 _Binary_Tree_Node *root = new _Binary_Tree_Node();


int main()
{
    InitWindow(ScreenWidth , ScreenHeight , "Binary Tree Visual");

   

    




    _Binary_Tree_visual(root, 400, 50, 1);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

   		
        //Use DrawRectangle to Draw 5 buttons at the top of the screen with use DrawText() text "1", "2", "3", "4", "5"
        // width of the button is 50 and height is 50
        DrawRectangle(1, 0, 50, 50, BLACK);
        DrawText("1", 20, 20, 20, WHITE);
        // draw second button after 50 pixels
        DrawRectangle(51, 0, 50, 50, BLACK);
        DrawText("2", 70, 20, 20, WHITE);
        // draw third button after 100 pixels
        DrawRectangle(101, 0, 50, 50, BLACK);
        DrawText("3", 120, 20, 20, WHITE);
        // draw fourth button after 150 pixels
        DrawRectangle(151, 0, 50, 50, BLACK);
        DrawText("4", 170, 20, 20, WHITE);
        // draw fifth button after 200 pixels
        DrawRectangle(201, 0, 50, 50, BLACK);
        DrawText("5", 220, 20, 20, WHITE);

        //if the button is clicked set the value of BT_int_value to the number of the button

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            if (GetMouseX() > 1 && GetMouseX() < 50 && GetMouseY() > 0 && GetMouseY() < 50)
            {
                BT_int_value = 1;
            }
            if (GetMouseX() > 51 && GetMouseX() < 100 && GetMouseY() > 0 && GetMouseY() < 50)
            {
                BT_int_value = 2;
            }
            if (GetMouseX() > 101 && GetMouseX() < 150 && GetMouseY() > 0 && GetMouseY() < 50)
            {
                BT_int_value = 3;
            }
            if (GetMouseX() > 151 && GetMouseX() < 200 && GetMouseY() > 0 && GetMouseY() < 50)
            {
                BT_int_value = 4;
            }
            if (GetMouseX() > 201 && GetMouseX() < 250 && GetMouseY() > 0 && GetMouseY() < 50)
            {
                BT_int_value = 5;
            }
        }
        




        //add a button at the bottom of the screen to add with text "Add"
        DrawRectangle(1, 550, 800, 50, BLACK);
        DrawText("Add", 400, 550, 20, WHITE);
        //if the button is clicked add the value of BT_int_value to the tree
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            if (GetMouseX() > 1 && GetMouseX() < 800 && GetMouseY() > 550 && GetMouseY() < 600)
            {
                insert(root, BT_int_value);
            }
        }
        

        _Binary_Tree_visual_draw(root);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}

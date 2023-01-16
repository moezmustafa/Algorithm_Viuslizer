

// creating a simple binary tree to store data 
// and traverse it in different ways

#include <iostream>
#include <queue>
#include <stack>

using namespace std;

// creating a node class to store data and pointers to left and right child
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

// creating a binary tree class to store root node and methods to traverse the tree
class BinaryTree
{
public:
    Node *root;

    BinaryTree()
    {
        root = NULL;
    }

    // method to insert data into the tree
    void insert(int data)
    {
        // creating a new node
        Node *newNode = new Node(data);

        // if root is null, then the new node is the root
        if (root == NULL)
        {
            root = newNode;
            return;
        }

        // else, we will use a queue to traverse the tree
        queue<Node *> q;
        q.push(root);

        while (!q.empty())
        {
            // storing the front node in a temp node
            Node *temp = q.front();
            q.pop();

            // if the left child of the temp node is null, then we will insert the new node there
            if (temp->left == NULL)
            {
                temp->left = newNode;
                return;
            }
            // else, we will push the left child into the queue
            else
            {
                q.push(temp->left);
            }

            // if the right child of the temp node is null, then we will insert the new node there
            if (temp->right == NULL)
            {
                temp->right = newNode;
                return;
            }
            // else, we will push the right child into the queue
            else
            {
                q.push(temp->right);
            }
        }
    }

    // method to print the tree in preorder
    void preorder(Node *root)
    {
        // if root is null, then we will return
        if (root == NULL)
        {
            return;
        }

        // else, we will print the data of the root node
        cout << root->data << " ";

        // then we will call the preorder method for the left child
        preorder(root->left);

        // then we will call the preorder method for the right child
        preorder(root->right);
    }

    // method to print the tree in inorder
    void inorder(Node *root)
    {
        // if root is null, then we will return
        if (root == NULL)
        {
            return;
        }

        // else, we will call the inorder method for the left child
        inorder(root->left);

        // then we will print the data of the root node
        cout << root->data << " ";

        // then we will call the
        inorder(root->right);
    }

    // method to print the tree in postorder
    void postorder(Node *root)
    {
        // if root is null, then we will return
        if (root == NULL)
        {
            return;
        }

        // else, we will call the postorder method for the left child
        postorder(root->left);

        // then we will call the postorder method for the right child
        postorder(root->right);

        // then we will print the data of the root node
        cout << root->data << " ";
    }

    // method to print the tree in level order

    void levelorder(Node *root)
    {
        // if root is null, then we will return
        if (root == NULL)
        {
            return;
        }

        // else, we will use a queue to traverse the tree
        queue<Node *> q;
        q.push(root);

        while (!q.empty())
        {
            // storing the front node in a temp node
            Node *temp = q.front();
            q.pop();

            // printing the data of the temp node
            cout << temp->data << " ";

            // if the left child of the temp node is not null, then we will push it into the queue
            if (temp->left != NULL)
            {
                q.push(temp->left);
            }

            // if the right child of the temp node is not null, then we will push it into the queue
            if (temp->right != NULL)
            {
                q.push(temp->right);
            }
        }
    }

    // method to print the tree in reverse level order

    void reverselevelorder(Node *root)
    {
        // if root is null, then we will return
        if (root == NULL)
        {
            return;
        }

        // else, we will use a queue to traverse the tree
        queue<Node *> q;
        q.push(root);

        // we will use a stack to store the data of the nodes
        stack<int> s;

        while (!q.empty())
        {
            // storing the front node in a temp node
            Node *temp = q.front();
            q.pop();

            // pushing the data of the temp node into the stack
            s.push(temp->data);

            // if the right child of the temp node is not null, then we will push it into the queue
            if (temp->right != NULL)
            {
                q.push(temp->right);
            }

            // if the left child of the temp node is not null, then we will push it into the queue
            if (temp->left != NULL)
            {
                q.push(temp->left);
            }
        }

        // now, we will print the data of the nodes in the stack
        while (!s.empty())
        {
            cout << s.top() << " ";
            s.pop();
        }
    }

    // method to print the tree in spiral order
    
};


int main()
{
    // creating a binary tree object
    BinaryTree bt;

    // inserting data into the tree
    bt.insert(1);
    bt.insert(2);
    bt.insert(3);
    bt.insert(4);
    bt.insert(5);
    bt.insert(6);
    bt.insert(7);

    // printing the tree in preorder
    cout << "Preorder: ";
    bt.preorder(bt.root);
    cout << endl;

    // printing the tree in inorder
    cout << "Inorder: ";
    bt.inorder(bt.root);
    cout << endl;

    // printing the tree in postorder
    cout << "Postorder: ";
    bt.postorder(bt.root);
    cout << endl;

    // printing the tree in level order
    cout << "Levelorder: ";
    bt.levelorder(bt.root);
    cout << endl;

    // printing the tree in reverse level order
    cout << "Reverse Levelorder: ";
    bt.reverselevelorder(bt.root);
    cout << endl;

    return 0;
}
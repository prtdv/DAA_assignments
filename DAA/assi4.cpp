//Write a program to implement AVL Tree
#include <iostream>
#include <algorithm>  // for max()
using namespace std;

class avl_node
{
public:
    int value;
    avl_node *left, *right;
    avl_node()
    {
        value = 0;
        left = right = nullptr;
    }
};

class avlTree
{
    avl_node *root;
public:
    avlTree()
    {
        root = nullptr;
    }
    int height(avl_node *);
    int diff(avl_node *);
    avl_node *RR_rotation(avl_node *);
    avl_node *LL_rotation(avl_node *);
    avl_node *LR_rotation(avl_node *);
    avl_node *RL_rotation(avl_node *);
    avl_node* balance(avl_node *);
    void insert();
    avl_node* insert(avl_node *, avl_node *);
    void display(avl_node *, int);
    void inorder(avl_node *);
    void preorder(avl_node *);
    void postorder(avl_node *);
    avl_node* getRoot() { return root; }
};

// LL rotation
avl_node* avlTree::LL_rotation(avl_node *parent)
{
    avl_node *temp = parent->left;
    parent->left = temp->right;
    temp->right = parent;
    return temp;
}

// RR rotation 
avl_node* avlTree::RR_rotation(avl_node *parent)
{
    avl_node *temp = parent->right;
    parent->right = temp->left;
    temp->left = parent;
    return temp;
}

// LR rotation 
avl_node* avlTree::LR_rotation(avl_node *parent)
{
    avl_node *temp = parent->left;
    parent->left = RR_rotation(temp); // calling RR rotation
    return LL_rotation(parent);         // return root after LL rotation
}

// RL rotation
avl_node* avlTree::RL_rotation(avl_node *parent)
{
    avl_node *temp = parent->right;
    parent->right = LL_rotation(temp); // calling LL rotation
    return RR_rotation(parent);          // return root after RR rotation
}

int avlTree::diff(avl_node *temp)
{
    int l_height = height(temp->left);
    int r_height = height(temp->right);
    int b_factor = l_height - r_height;
    return b_factor;
}

int avlTree::height(avl_node *temp)
{
    int h = 0;
    if (temp != nullptr)
    {
        int l_height = height(temp->left);
        int r_height = height(temp->right);
        int max_height = max(l_height, r_height);
        h = max_height + 1;
    }
    return h;
}

avl_node* avlTree::balance(avl_node *temp)
{
    int bal_factor = diff(temp);
    if (bal_factor > 1)
    {
        if (diff(temp->left) > 0)
            temp = LL_rotation(temp);
        else
            temp = LR_rotation(temp);
    }
    else if (bal_factor < -1)
    {
        if (diff(temp->right) > 0)
            temp = RL_rotation(temp);
        else
            temp = RR_rotation(temp);
    }
    return temp;
}

void avlTree::insert()
{
    char ch;
    do
    {
        avl_node *temp = new avl_node;
        cout << "Enter value: ";
        cin >> temp->value;
        root = insert(root, temp);
        cout << "Do you want to continue (Y/N)? ";
        cin >> ch;
    } while(ch == 'Y' || ch == 'y');
}

avl_node* avlTree::insert(avl_node *root, avl_node *temp)
{
    if (root == nullptr)
    {
        root = new avl_node;
        root->value = temp->value;
        root->left = nullptr;
        root->right = nullptr;
        return root;
    }
    else if (temp->value < root->value)
    {
        root->left = insert(root->left, temp);
        root = balance(root);
    }
    else if (temp->value >= root->value)
    {
        root->right = insert(root->right, temp);
        root = balance(root);
    }
    return root;
}

void avlTree::display(avl_node *ptr, int level) // consider level = 1
{
    if (ptr != nullptr)
    { 
        display(ptr->right, level + 1);
        cout << "\n";
        if (ptr == root)
            cout << "Root -> ";
        for (int i = 0; i < level && ptr != root; i++)
            cout << "    ";
        cout << ptr->value;
        display(ptr->left, level + 1);
    }
}

void avlTree::inorder(avl_node *ptr)
{
    if(ptr)
    {
        inorder(ptr->left);
        cout << ptr->value << " ";
        inorder(ptr->right);
    }
}

void avlTree::preorder(avl_node *ptr)
{
    if(ptr)
    {
        cout << ptr->value << " ";
        preorder(ptr->left);
        preorder(ptr->right);
    }
}

void avlTree::postorder(avl_node *ptr)
{
    if(ptr)
    {
        postorder(ptr->left);
        postorder(ptr->right);
        cout << ptr->value << " ";
    }
}

int main()
{
    avlTree tree;
    int choice;
    while (true)
    {
        cout << "\n1. Insert" << endl;
        cout << "2. Display" << endl;
        cout << "3. Inorder Traversal" << endl;
        cout << "4. Preorder Traversal" << endl;
        cout << "5. Postorder Traversal" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice)
        {
            case 1: 
                tree.insert();
                break;
            case 2:
                cout << "\nDisplaying AVL Tree:" << endl;
                tree.display(tree.getRoot(), 1);
                cout << "\n";
                break;
            case 3:
                cout << "\nInorder Traversal: ";
                tree.inorder(tree.getRoot());
                cout << "\n";
                break;
            case 4:
                cout << "\nPreorder Traversal: ";
                tree.preorder(tree.getRoot());
                cout << "\n";
                break;
            case 5:
                cout << "\nPostorder Traversal: ";
                tree.postorder(tree.getRoot());
                cout << "\n";
                break;
            case 6:
                exit(0);
            default:
                cout << "Wrong Choice" << endl;
        }
    }
    return 0;
}

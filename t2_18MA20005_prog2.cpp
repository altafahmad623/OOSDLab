/*
By: Altaf Ahmad
Roll no: 18MA20005
*/
#include <iostream>
using namespace std;

struct leaf
{
    int data;
    leaf *left;
    leaf *right;
    leaf *parent;
    int height;
};

class minHeap
{
public:
    leaf *Root;

    leaf *addNewNode(int da, leaf *parent)
    {
        leaf *Tree = new leaf;
        Tree->data = da;
        Tree->left = NULL;
        Tree->right = NULL;
        Tree->parent = parent;
        Tree->height = 1;
    }

    int height(leaf *node)
    {
        if (node == NULL)
        {
            return 0;
        }
        return node->height;
    }
    int change_ht(leaf *node)
    {
        if (node == NULL)
        {
            return 0;
        }
        else
        {
            node->height = min(height(node->left), height(node->right)) + 1;
        }
    }
    leaf *insert_helper(int data, leaf *root)
    {
        if (height(root->left) < height(root->right))
        {
            if (root->left == NULL)
            {
                root->left = addNewNode(data, root);
                change_ht(root);
                return root->left;
            }
            else
            {
                leaf *tmp = insert_helper(data, root->left);
                change_ht(tmp);
                return tmp;
            }
        }
        else
        {
            if (root->right == NULL)
            {
                root->right = addNewNode(data, root);
                change_ht(root);
                return root->right;
            }
            else
            {
                leaf *tmp = insert_helper(data, root->right);
                change_ht(tmp);
                return tmp;
            }
        }
    }

    void balance(leaf *node)
    {
        if (node == Root)
        {
            return;
        }
        if (node->parent->data < node->data)
        {
            return;
        }

        int tmp = node->parent->data;
        node->parent->data = node->data;
        node->data = tmp;

        balance(node->parent);
    }

public:
    minHeap()
    {
        Root = NULL;
    }

    void insert(int data)
    {
        cout << "Putting " << data  << endl;

        if (Root == NULL)
        {
            Root = addNewNode(data, NULL);
        }
        else
        {
            leaf *insertedleaf = insert_helper(data, Root);
            balance(insertedleaf);
        }
    }
};

int main()
{
    minHeap heap;
    heap.insert(5);
    cout<<"The heap is :\n";
    cout << heap.Root->data << endl;
    heap.insert(9);
    cout<<"The heap is :\n";
    cout << heap.Root->data << endl;
    cout<<" \\ \n";
    cout <<" "<< heap.Root->right->data << endl;
    heap.insert(1);
    cout<<"The heap is :\n";
    cout <<" "<< heap.Root->data << endl;
    cout <<"/ \\ \n";
    cout << heap.Root->right->data <<" ";
    cout << heap.Root->left->data << endl;
}
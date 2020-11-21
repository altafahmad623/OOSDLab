/*
Name - Varun Gupta
Roll Number - 18MA20050
Logic - Implementation of AVL Trees
*/

#include <iostream>  // Including the I/O library

using namespace std;  // Using the required namespace for the functions
                      // We can also use std::cout if we don't particularly use the namespace

struct Node           // The strcuture for each respective node of the AVL Tree
{
    int key;            // key that the node would hold as data
    int height;         // height of that particular node from the leaves
    Node* Left;         // pointer to left child of that node
    Node* Right;        // pointer to right child of that node
    Node* Parent;       // pointer to parent of that node
};


class AVLTree           // defining the class for the AVL Tree which consists of it's constructor, memeber functions and respective private and public data values
{
private:
    Node* Root;         // defining the pointer to root node of the tree as private

public:
    AVLTree(): Root(NULL)   // a constrctor for the tree of not instantiated by the user and gives NULL to the Root Node
    { }

    void InsertRoot(int data);      // function to insert a Root node to the Tree
    void InsertNode(int data);      // function to insert a new node to the Tree
    void DeleteNode(int data);      // fucntion to delete a particular node from the tree
    void Rotation(Node* PreviousParent, Node* Previous, Node* Child, int rotation);
    void PrintAVLTree();            // Function to pring the AVL Tree in the Sorted Manner
    void Print(Node* node);         // Helper Function to Print the AVL Tree
};

void AVLTree::InsertRoot(int data)      //defining the Insertion function for the Tree to Insert a Root Node
{
    Node *NewRoot = new Node;           // declaring a new node

    NewRoot->key = data;                // giving the new node with the respective data value
    NewRoot->height = 1;                // giving the root node initial height of 1 and would get altered depending upon the children nodes
    NewRoot->Left = NULL;               // Left child would be initially NULL
    NewRoot->Right = NULL;              // Right Child would be initially NULL
    NewRoot->Parent = NULL;             // Parent of an initial Root Node would be NULL initially
    Root = NewRoot;                     // giving the Root node with all the respective values of this node
    return;                             // returing the function after the particular task is over
}

void AVLTree::InsertNode(int data)      // Function to insert a new node in the TREE
{
    if(Root == NULL)                    // if initially the Root is already NULL then we would add the new node as ROOT node
    {
        InsertRoot(data);               // calling that respective function
    }
    else                                // if root node is present
    {
        Node* NewNode = new Node;       // declaring a new node for inserting that node
        Node* Current = Root;           // getting a pointer initially to root node to find the respective place to add the new node
        Node* Child;                    // pointer to remember the Child pointer value while traversing through the Tree
        Node* Previous = NULL;                 // another pointer to remember the parent pointer value while traversing through the Tree
        Node* PreviousParent = NULL;           // another pointer to remember the grandparent pointer value while traversing through the Tree
        NewNode->key = data;            // giving the data value
        NewNode->Left = NULL;           // Left child would be NULL
        NewNode->Right = NULL;          // Right Child would be NULL
        NewNode->height = 1;            // giving it a height of 1 as it would join at a leaf and hence change the respective height of it's ancestors

        while(Current!=NULL)            // while we don't find a empty node or leaf
        {
            PreviousParent = Previous;  // saving the garndparent node
            Previous = Current;         // saving the pointer to the Parent node
            if((Current->key) >= data)      // going left if parent data > new node data
                Current = Current->Left;
            else                            // going right in other case
                Current = Current->Right;
        }
        if((Previous->key) >= data)         // now allocating the new node it's respective position on the left or right of previous node
            Previous->Left = NewNode;           // if left child
        else
            Previous->Right = NewNode;          // if right child

        NewNode->Parent = Previous;        // the newnode's parent would be the previous node
        Child = NewNode;                    // saving the child to traverse throught the tree bottom up
        if(Previous->Left == NULL || Previous->Right==NULL)    // if child added to a leaf
            Previous->height = Child->height + 1;
        else if(Previous->Left->height > Previous->Right->height)       // if child added to a node having a node already and then the case which subtree has higher heighr
                Previous->height = Previous->Left->height + 1;
        else
            Previous->height = Previous->Right->height + 1;

        while(PreviousParent != NULL)               // changing the height respectively until we reach the root's parent i.e. NULL
        {
            if (PreviousParent->Left == NULL)
            {
                Previous->Left = PreviousParent;
                if(PreviousParent->Parent != NULL)
                    Previous->Parent = PreviousParent->Parent;
                else
                    Previous->Parent = NULL;
                PreviousParent->Parent = Previous;
                PreviousParent->Right = NULL;
                PreviousParent = NULL;
            }
            else if (PreviousParent->Right == NULL)
            {
                Previous->Right = PreviousParent;
                if(PreviousParent->Parent != NULL)
                    Previous->Parent = PreviousParent->Parent;
                else
                    Previous->Parent = NULL;
                PreviousParent->Parent = Previous;
                PreviousParent->Left = NULL;
                PreviousParent = NULL;
            }
            else if(PreviousParent->Left->height - PreviousParent->Right->height > 1 || PreviousParent->Right->height - PreviousParent->Left->height > 1)        // condition of unbalanced node and hence would be required to rotate the nodes respectively
            {
                cout << "no\n";
                int rotation;                           // a number which caries the case of which type of rotation would be carried out.
                if(PreviousParent->Left == Previous && Previous->Left == Child)
                    rotation = 1;                                               // Left-Left Case
                else if (PreviousParent->Left == Previous && Previous->Right == Child)
                    rotation = 2;                                               // Left - Right Case
                else if (PreviousParent->Right == Previous && Previous->Right == Child)
                    rotation = 3;                                               // Right - Right Case
                else
                    rotation = 4;                                               // Right Left Case
                cout << "beioanio\n";
                switch ( rotation )
                {
                    case 1:
                    {
                        Rotation(PreviousParent,Previous,Child,rotation);                         //Left- Left Case
                        break;
                    }
                    case 2:
                    {
                        Rotation(PreviousParent,Previous,Child,rotation);                         //Left- Right Case
                        break;
                    }
                    case 3:
                    {
                        Rotation(PreviousParent,Previous,Child,rotation);                         //Right - Right Case
                        break;
                    }
                    case 4:
                    {
                        Rotation(PreviousParent,Previous,Child,rotation);                         //Right Left Case
                        break;
                    }
                }
            }
            else                    /// not unbalanced node and hence would just continue up the tree and change the height of this node respectively
            {
                cout << "else\n";
                if(PreviousParent->Left->height > PreviousParent->Right->height)
                    PreviousParent->height = PreviousParent->Left->height + 1;
                else
                    PreviousParent->height = PreviousParent->Right->height + 1;
                PreviousParent = PreviousParent->Parent;
                Previous = Previous->Parent;
                Child = Child->Parent;
            }
        }
    }
    return;
}

void AVLTree::Rotation(Node* PreviousParent, Node* Previous, Node* Child, int rotation)
{
    int rotation_type = rotation;
    switch ( rotation_type )
    {
        case 1:                             //Left Left Case
        {
            Previous->Right->Parent = PreviousParent;                       // changing  the respective pointers to carry out the rotation respectively
            PreviousParent->Left = Previous->Right;
            Previous->Parent = PreviousParent->Parent;
            Previous->Right = PreviousParent;
            PreviousParent->Parent = Previous;
            if(Previous->Parent->Left == PreviousParent)                    // making the previous node as the respective child PreviousParent-> parent child
                Previous->Parent->Left = Previous;
            else
                Previous->Parent->Right = Previous;
            if(PreviousParent->Left->height > PreviousParent->Right->height)            // after the rotation being done, changing the respective height of changed nodes
                PreviousParent->height = PreviousParent->Left->height + 1;
            else
                PreviousParent->height = PreviousParent->Right->height + 1;
            if(Child->height > PreviousParent->height)                                  // changing height of rotated nodes
                Previous->height = Child->height + 1;
            else
                Previous->height = PreviousParent->height + 1;
            PreviousParent = Previous->Parent;                                          // making parent of the top rotated node as the new grandparent and continuing the bootom up search till we reach node
            break;
        }
        case 2:                                         // Left Right Case
        {
            Child->Left->Parent = Previous;                         // changing  the respective pointers to carry out the rotation respectively
            Previous->Right = Child->Left;
            Child->Right->Parent = PreviousParent;
            PreviousParent->Left = Child->Right;
            Child->Parent = PreviousParent->Parent;
            if(PreviousParent->Parent->Left == PreviousParent)
                PreviousParent->Parent->Left = Child;
            else
                PreviousParent->Parent->Right = Child;
            PreviousParent->Parent = Child;
            Previous->Parent = Child;
            Child->Left = Previous;
            Child->Right = PreviousParent;
            if(Previous->Left->height > Previous->Right->height)             // changing height of rotated nodes
                Previous->height = Previous->Left->height + 1;
            else
                Previous->height = Previous->Right->height + 1;
            if(PreviousParent->Left->height > PreviousParent->Right->height)
                PreviousParent->height = PreviousParent->Left->height + 1;
            else
                PreviousParent->height = PreviousParent->Right->height + 1;
            if(Previous->height > PreviousParent->height)
                Child->height = Previous->height + 1;
            else
                Child->height = PreviousParent->height + 1;
            PreviousParent = Child->Parent;                                     // changing the pointers to the new nodes that would come up after these subtrees
            Previous = Child;
            Child = Previous->Left;
            break;
        }
        case 3:                                                             //Right Right Case
        {
            Previous->Left->Parent = PreviousParent;                       // changing  the respective pointers to carry out the rotation respectively
            PreviousParent->Right = Previous->Left;
            Previous->Parent = PreviousParent->Parent;
            Previous->Left = PreviousParent;
            PreviousParent->Parent = Previous;
            if(Previous->Parent->Left == PreviousParent)                    // making the previous node as the respective child PreviousParent-> parent child
                Previous->Parent->Left = Previous;
            else
                Previous->Parent->Right = Previous;
            if(PreviousParent->Left->height > PreviousParent->Right->height)            // after the rotation being done, changing the respective height of changed nodes
                PreviousParent->height = PreviousParent->Left->height + 1;
            else
                PreviousParent->height = PreviousParent->Right->height + 1;
            if(Child->height > PreviousParent->height)                                  // changing height of rotated nodes
                Previous->height = Child->height + 1;
            else
                Previous->height = PreviousParent->height + 1;
            PreviousParent = Previous->Parent;                                          // making parent of the top rotated node as the new grandparent and continuing the bootom up search till we reach node
            break;
        }
        case 4:                                                                 //Right Left Case
        {
            Child->Right->Parent = Previous;                         // changing  the respective pointers to carry out the rotation respectively
            Previous->Left = Child->Right;
            Child->Left->Parent = PreviousParent;
            PreviousParent->Right = Child->Left;
            Child->Parent = PreviousParent->Parent;
            if(PreviousParent->Parent->Left == PreviousParent)
                PreviousParent->Parent->Left = Child;
            else
                PreviousParent->Parent->Right = Child;
            PreviousParent->Parent = Child;
            Previous->Parent = Child;
            Child->Right = Previous;
            Child->Left = PreviousParent;
            if(Previous->Left->height > Previous->Right->height)             // changing height of rotated nodes
                Previous->height = Previous->Left->height + 1;
            else
                Previous->height = Previous->Right->height + 1;
            if(PreviousParent->Left->height > PreviousParent->Right->height)
                PreviousParent->height = PreviousParent->Left->height + 1;
            else
                PreviousParent->height = PreviousParent->Right->height + 1;
            if(Previous->height > PreviousParent->height)
                Child->height = Previous->height + 1;
            else
                Child->height = PreviousParent->height + 1;
            PreviousParent = Child->Parent;                                     // changing the pointers to the new nodes that would come up after these subtrees
            Previous = Child;
            Child = Previous->Right;
            break;
        }
    }
    return;
}


void AVLTree::DeleteNode(int data)                                                          // Function to delete a particular node
{
    Node* Current = Root;                                                                     // taking the root node as Current
    Node* Child;
    Node* Previous = NULL;
    Node* PreviousParent = NULL;
    if(Current == NULL)                                                                       // if tree is empty
        cout << "The Tree is empty, Nothing to delete.\n";
    else if(Root->key == data && Root->Left == NULL && Root->Right == NULL)                 // if only root present and that is the data value
        {
            Root = NULL;
            delete (Current);
        }
    else                                                                                    // else traversing through the tree to find that node
    {
        while(Current!=NULL)                                                                  // until we reach a particular leaf
        {
            PreviousParent = Previous;
            Previous = Current;
            if(Current->key>data)                                                             // moving to left
                Current = Current->Left;
            else if(Current->key < data)                                                     // moving to right
                Current = Current->Right;
            else                                                                            // if node is found
                break;
        }
        if(Current == NULL)                                                                  // if that node valus is not present in the tree
        {
            cout << "The given data point is not present in the AVL Tree.\n";
            return;
        }
        else if(Current->Left == NULL && Current->Right == NULL)
        {
            if(Previous->Left == Child)
            {
                if(Previous->Right != NULL)
                {
                    Previous->Left = NULL;
                    delete(Current);
                }
                else
                {
                    Previous->Left = NULL;
                    delete(Current);
                    Previous->height -= 1;
                    if(PreviousParent==NULL)
                    {}
                    else
                    {
                        Child = Previous;
                        Previous = PreviousParent;
                        PreviousParent = PreviousParent->Parent;
                        while(PreviousParent != NULL)
                        {
                            if(PreviousParent->Left->height - PreviousParent->Right->height > 1 || PreviousParent->Right->height - PreviousParent->Left->height > 1)        // condition of unbalanced node and hence would be required to rotate the nodes respectively
                            {
                                if(PreviousParent->Left->height > PreviousParent->Right->height)
                                    Previous = PreviousParent->Left;
                                else
                                    Previous = PreviousParent->Right;
                                if(Previous->Left->height  > Previous->Right->height)
                                    Child = Previous->Left;
                                else
                                    Child = Previous->Right;
                                int rotation;                           // a number which caries the case of which type of rotation would be carried out.
                                if(PreviousParent->Left == Previous && Previous->Left == Child)
                                    rotation = 1;                                               // Left-Left Case
                                else if (PreviousParent->Left == Previous && Previous->Right == Child)
                                    rotation = 2;                                               // Left - Right Case
                                else if (PreviousParent->Right == Previous && Previous->Right == Child)
                                    rotation = 3;                                               // Right - Right Case
                                else
                                    rotation = 4;                                               // Right Left Case
                                switch ( rotation )
                                {
                                    case 1:
                                    {
                                        Rotation(PreviousParent,Previous,Child,rotation);                         //Left- Left Case
                                        break;
                                    }
                                    case 2:
                                    {
                                        Rotation(PreviousParent,Previous,Child,rotation);                         //Left- Right Case
                                        break;
                                    }
                                    case 3:
                                    {
                                        Rotation(PreviousParent,Previous,Child,rotation);                         //Right - Right Case
                                        break;
                                    }
                                    case 4:
                                    {
                                        Rotation(PreviousParent,Previous,Child,rotation);                         //Right Left Case
                                        break;
                                    }
                                }
                            }
                            else                    /// not unbalanced node and hence would just continue up the tree and change the height of this node respectively
                            {
                                if(PreviousParent->Left->height > PreviousParent->Right->height)
                                    PreviousParent->height = PreviousParent->Left->height + 1;
                                else
                                    PreviousParent->height = PreviousParent->Right->height + 1;

                                PreviousParent = PreviousParent->Parent;
                                Previous = Previous->Parent;
                                Child = Child->Parent;
                            }
                        }
                    }
                }
            }
            else
            {
                if(Previous->Left != NULL)
                {
                    Previous->Right = NULL;
                    delete(Current);
                }
                else
                {
                    Previous->Left = NULL;
                    delete(Current);
                    Previous->height -= 1;
                    if(PreviousParent==NULL)
                    {}
                    else
                    {
                        Child = Previous;
                        Previous = PreviousParent;
                        PreviousParent = PreviousParent->Parent;
                        while(PreviousParent != NULL)
                        {
                            if(PreviousParent->Left->height - PreviousParent->Right->height > 1 || PreviousParent->Right->height - PreviousParent->Left->height > 1)        // condition of unbalanced node and hence would be required to rotate the nodes respectively
                            {
                                if(PreviousParent->Left->height > PreviousParent->Right->height)
                                    Previous = PreviousParent->Left;
                                else
                                    Previous = PreviousParent->Right;
                                if(Previous->Left->height  > Previous->Right->height)
                                    Child = Previous->Left;
                                else
                                    Child = Previous->Right;
                                int rotation;                           // a number which caries the case of which type of rotation would be carried out.
                                if(PreviousParent->Left == Previous && Previous->Left == Child)
                                    rotation = 1;                                               // Left-Left Case
                                else if (PreviousParent->Left == Previous && Previous->Right == Child)
                                    rotation = 2;                                               // Left - Right Case
                                else if (PreviousParent->Right == Previous && Previous->Right == Child)
                                    rotation = 3;                                               // Right - Right Case
                                else
                                    rotation = 4;                                               // Right Left Case
                                switch ( rotation )
                                {
                                    case 1:
                                    {
                                        Rotation(PreviousParent,Previous,Child,rotation);                         //Left- Left Case
                                        break;
                                    }
                                    case 2:
                                    {
                                        Rotation(PreviousParent,Previous,Child,rotation);                         //Left- Right Case
                                        break;
                                    }
                                    case 3:
                                    {
                                        Rotation(PreviousParent,Previous,Child,rotation);                         //Right - Right Case
                                        break;
                                    }
                                    case 4:
                                    {
                                        Rotation(PreviousParent,Previous,Child,rotation);                         //Right Left Case
                                        break;
                                    }
                                }
                            }
                            else                    /// not unbalanced node and hence would just continue up the tree and change the height of this node respectively
                            {
                                if(PreviousParent->Left->height > PreviousParent->Right->height)
                                    PreviousParent->height = PreviousParent->Left->height + 1;
                                else
                                    PreviousParent->height = PreviousParent->Right->height + 1;

                                PreviousParent = PreviousParent->Parent;
                                Previous = Previous->Parent;
                                Child = Child->Parent;
                            }
                        }
                    }
                }
            }
        }
        else if (Current->Left == NULL || Current->Right == NULL)
        {
            if(Previous->Left == Current)                                        // if node present on parents left
            {
                if(Current->Left!=NULL)                                               // non empty node on left
                {
                    Previous->Left = Current->Left;
                    Current->Left->Parent = Previous;
                    delete (Current);                                                 // deleting the node
                }
                else if(Current->Right!=NULL)                                        // non empty node on right
                {
                    Previous->Left = Current->Right;
                    Current->Right->Parent = Previous;
                    delete (Current);
                }
            }
            else
            {
                {
                    if(Current->Left!=NULL)                                               // non empty node on left
                    {
                        Previous->Right = Current->Left;
                        Current->Left->Parent = Previous;
                        delete (Current);                                                 // deleting the node
                    }
                    else if(Current->Right!=NULL)                                        // non empty node on right
                    {
                        Previous->Right = Current->Right;
                        Current->Right->Parent = Previous;
                        delete (Current);
                    }
                }
            }
                Previous->height -= 1;
                if(PreviousParent==NULL)
                {}
                else
                {
                    Child = Previous;
                    Previous = PreviousParent;
                    PreviousParent = PreviousParent->Parent;
                    while(PreviousParent != NULL)
                    {
                        if(PreviousParent->Left->height - PreviousParent->Right->height > 1 || PreviousParent->Right->height - PreviousParent->Left->height > 1)        // condition of unbalanced node and hence would be required to rotate the nodes respectively
                        {
                            if(PreviousParent->Left->height > PreviousParent->Right->height)
                                Previous = PreviousParent->Left;
                            else
                                Previous = PreviousParent->Right;
                            if(Previous->Left->height  > Previous->Right->height)
                                Child = Previous->Left;
                            else
                                Child = Previous->Right;
                            int rotation;                           // a number which caries the case of which type of rotation would be carried out.
                            if(PreviousParent->Left == Previous && Previous->Left == Child)
                                rotation = 1;                                               // Left-Left Case
                            else if (PreviousParent->Left == Previous && Previous->Right == Child)
                                rotation = 2;                                               // Left - Right Case
                            else if (PreviousParent->Right == Previous && Previous->Right == Child)
                                rotation = 3;                                               // Right - Right Case
                            else
                                rotation = 4;                                               // Right Left Case
                            switch ( rotation )
                            {
                                case 1:
                                {
                                    Rotation(PreviousParent,Previous,Child,rotation);                         //Left- Left Case
                                    break;
                                }
                                case 2:
                                {
                                    Rotation(PreviousParent,Previous,Child,rotation);                         //Left- Right Case
                                    break;
                                }
                                case 3:
                                {
                                    Rotation(PreviousParent,Previous,Child,rotation);                         //Right - Right Case
                                    break;
                                }
                                case 4:
                                {
                                    Rotation(PreviousParent,Previous,Child,rotation);                         //Right Left Case
                                    break;
                                }
                            }
                        }
                        else                    /// not unbalanced node and hence would just continue up the tree and change the height of this node respectively
                        {
                            if(PreviousParent->Left->height > PreviousParent->Right->height)
                                PreviousParent->height = PreviousParent->Left->height + 1;
                            else
                                PreviousParent->height = PreviousParent->Right->height + 1;

                            PreviousParent = PreviousParent->Parent;
                            Previous = Previous->Parent;
                            Child = Child->Parent;
                        }
                    }
                }
        }
        else                                                                        // if both children present
        {
            PreviousParent = NULL;
            Previous = NULL;
            Child = Current;
            Current = Current->Right;
            while(Current->Left != NULL)
            {
                PreviousParent = Previous;
                Previous = Current;
                Current = Current->Left;
            }
            Child->key = Current->key;
            if(Current->Right==NULL && Previous->Right != NULL)
                delete(Current);
            else if (Current->Right==NULL && Previous->Right == NULL)
            {
                delete(Current);
                Child = Previous;
                Previous = PreviousParent;
                PreviousParent = PreviousParent->Parent;
                Child->height -= 1;
                if(PreviousParent == NULL)
                {}
                else
                {
                    while(PreviousParent != NULL)
                    {
                        if(PreviousParent->Left->height - PreviousParent->Right->height > 1 || PreviousParent->Right->height - PreviousParent->Left->height > 1)        // condition of unbalanced node and hence would be required to rotate the nodes respectively
                        {
                            if(PreviousParent->Left->height > PreviousParent->Right->height)
                                Previous = PreviousParent->Left;
                            else
                                Previous = PreviousParent->Right;
                            if(Previous->Left->height  > Previous->Right->height)
                                Child = Previous->Left;
                            else
                                Child = Previous->Right;
                            int rotation;                           // a number which caries the case of which type of rotation would be carried out.
                            if(PreviousParent->Left == Previous && Previous->Left == Child)
                                rotation = 1;                                               // Left-Left Case
                            else if (PreviousParent->Left == Previous && Previous->Right == Child)
                                rotation = 2;                                               // Left - Right Case
                            else if (PreviousParent->Right == Previous && Previous->Right == Child)
                                rotation = 3;                                               // Right - Right Case
                            else
                                rotation = 4;                                               // Right Left Case
                            switch ( rotation )
                            {
                                case 1:
                                {
                                    Rotation(PreviousParent,Previous,Child,rotation);                         //Left- Left Case
                                    break;
                                }
                                case 2:
                                {
                                    Rotation(PreviousParent,Previous,Child,rotation);                         //Left- Right Case
                                    break;
                                }
                                case 3:
                                {
                                    Rotation(PreviousParent,Previous,Child,rotation);                         //Right - Right Case
                                    break;
                                }
                                case 4:
                                {
                                    Rotation(PreviousParent,Previous,Child,rotation);                         //Right Left Case
                                    break;
                                }
                            }
                        }
                        else                    /// not unbalanced node and hence would just continue up the tree and change the height of this node respectively
                        {
                            if(PreviousParent->Left->height > PreviousParent->Right->height)
                                PreviousParent->height = PreviousParent->Left->height + 1;
                            else
                                PreviousParent->height = PreviousParent->Right->height + 1;

                            PreviousParent = PreviousParent->Parent;
                            Previous = Previous->Parent;
                            Child = Child->Parent;
                        }
                    }
                }
            }
            else
            {
                Previous->Left = Current->Right;
                Current->Right->Parent = Previous;
                delete(Current);
                Previous->height -= 1;
                if(PreviousParent==NULL)
                {

                }
                else
                {
                    Child = Previous;
                    Previous = PreviousParent;
                    PreviousParent = PreviousParent->Parent;
                    while(PreviousParent != NULL)
                    {
                        if(PreviousParent->Left->height - PreviousParent->Right->height > 1 || PreviousParent->Right->height - PreviousParent->Left->height > 1)        // condition of unbalanced node and hence would be required to rotate the nodes respectively
                        {
                            if(PreviousParent->Left->height > PreviousParent->Right->height)
                                Previous = PreviousParent->Left;
                            else
                                Previous = PreviousParent->Right;
                            if(Previous->Left->height  > Previous->Right->height)
                                Child = Previous->Left;
                            else
                                Child = Previous->Right;
                            int rotation;                           // a number which caries the case of which type of rotation would be carried out.
                            if(PreviousParent->Left == Previous && Previous->Left == Child)
                                rotation = 1;                                               // Left-Left Case
                            else if (PreviousParent->Left == Previous && Previous->Right == Child)
                                rotation = 2;                                               // Left - Right Case
                            else if (PreviousParent->Right == Previous && Previous->Right == Child)
                                rotation = 3;                                               // Right - Right Case
                            else
                                rotation = 4;                                               // Right Left Case
                            switch ( rotation )
                            {
                                case 1:
                                {
                                    Rotation(PreviousParent,Previous,Child,rotation);                         //Left- Left Case
                                    break;
                                }
                                case 2:
                                {
                                    Rotation(PreviousParent,Previous,Child,rotation);                         //Left- Right Case
                                    break;
                                }
                                case 3:
                                {
                                    Rotation(PreviousParent,Previous,Child,rotation);                         //Right - Right Case
                                    break;
                                }
                                case 4:
                                {
                                    Rotation(PreviousParent,Previous,Child,rotation);                         //Right Left Case
                                    break;
                                }
                            }
                        }
                        else                    /// not unbalanced node and hence would just continue up the tree and change the height of this node respectively
                        {
                            if(PreviousParent->Left->height > PreviousParent->Right->height)
                                PreviousParent->height = PreviousParent->Left->height + 1;
                            else
                                PreviousParent->height = PreviousParent->Right->height + 1;

                            PreviousParent = PreviousParent->Parent;
                            Previous = Previous->Parent;
                            Child = Child->Parent;
                        }
                    }
                }
            }
        }
    }
}

void AVLTree::PrintAVLTree()                                                        // function to print the AVL TREE
{
    Node* start = Root;                                                             // taking the ROOT node

    if(start == NULL)                                                               // if tree is empty
        cout << "The Tree is empty\n";
    else
        Print(start);                                                               // else a recursive function to print the tree
    return;
}

void AVLTree::Print(Node* start)                                                    // the helper recursive function to print the tree
{
    if(start!=NULL)                                                                 // until we reach a NULL node through a leaf
    {                                                                               // printing in the sorted manner
        Print(start->Left);                                                         // calling for the left node
        cout << start->key << " ";                                                  // printing that node
        Print(start->Right);                                                        // calling for the right node
    }
    return;
}

int main()                              // The main function which contains all the required variables and algorithm
{
    AVLTree Tree;                       // declaring a new Tree from the AVLTREE class
    while(true)
    {
        cout << "\nChoose on of the following options:\n";      // giving the required options for the program run
        cout << "1)Insert a Node.\n";
        cout << "2)Delete a Node.\n";
        cout << "3)Print the AVL Tree in a Sorted Manner.\n";
        cout << "4)Exit.\n\n";
        int n;
        cin >> n;
        switch ( n )
        {
            case 1:                                                             // Inserting a Node
            {
                int value;
                cout << "\nEnter the value that needs to be inserted in the AVL Tree:\n";
                cin >> value;
                Tree.InsertNode(value);                                         // calling function to insert the node
                break;
            }
            case 2:                                                             // Deleting a particular node
            {
                int value;
                cout << "\nEnter the value that needs to be ddeleted from the AVL Tree:\n";
                cin >> value;
                Tree.DeleteNode(value);                                         // Calling function to delete that node if exists
                break;
            }
            case 3:
            {
                cout << "\nHence, The Sorted AVL Tree is as follows:\n";
                Tree.PrintAVLTree();                                            // Calling funtion to print the AVL Tree in a sorted manner
                cout << "\n";
                break;
            }
            case 4:                                                             // Exiting the program
            {
                return 0;                                               //returning an int as we defined main as an int function
            }
        }
    }
}

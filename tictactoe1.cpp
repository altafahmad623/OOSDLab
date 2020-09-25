/*
By: Altaf Ahmad
Roll no: 18MA20005

Implementation of an automatic Tic Tac Toe player that can never lose. Matches can be drawn but computer never loses.

I have mapped the moves that the computer will make into numbers that can be stored in arrays. Now, in order to apply those moves, I have created some helper functions,
which will follow that particular set of moves.
*/
#include <iostream>
using namespace std;
void showTic(int a[]) // displays the tic tac toe after each input
{
    cout << "-------------\n";
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << "|";
            if (a[i * 3 + j] == 0)
            {
                cout << " O ";
            }
            else if (a[i * 3 + j] == 1)
            {
                cout << " X ";
            }
            else
            {
                cout << "   ";
            }
        }
        cout << "|\n";
        cout << "-------------\n";
    }
}
void hel_comp1(int a[], int sy, int x, int y, int z, int p, int q, int k, int sc) // This helper function looks at the cases when the user doesn't enter in the middle row middle column
{
    a[k] = sy;  //This stores the move of the user
    a[x] = sc;  //This is the computer's move decided by the variable x that is entered according to the most efficient way to win
    showTic(a);     //This outputs the Board after each round
    cout << "Your Turn\n";  
    cin >> k;
    k--;
    while (a[k] != 5)
    {
        cout << "You have entered a place which has already been filled or it is out of range. Please Enter a number that hasn't been utilized\n";
        cin >> k;
        k--;
    }
    a[k] = sy;//This stores the move of the user
    if (k == y) //after the user gives his move, computer then plays the most efficient moves according to the input provided
    {
        a[z] = sc; // computer's move decided by the variable z that is entered according to the most efficient way to win
        showTic(a);
        cout << "Your Turn\n";
        cin >> k;
        k--;
        while (a[k] != 5)
        {
            cout << "You have entered a place which has already been filled or it is out of range. Please Enter a number that hasn't been utilized\n";
            cin >> k;
            k--;
        }
        a[k] = sy;
        if (k == p)
        {
            a[q] = sc;
            showTic(a);
            cout << "Computer Won\n";
        }
        else
        {
            a[p] = sc;
            showTic(a);
            cout << "Computer Won\n";
        }
    }
    else
    {
        a[y] = sc;
        showTic(a);
        cout << "Computer Won\n";
    }
}
void hel_comp2(int a[], int sy, int x, int y, int z, int p, int q, int k, int sc)
{
    a[x] = sc;
    showTic(a);
    cout << "Your Turn\n";
    cin >> k;
    k--;
    while (a[k] != 5)
    {
        cout << "You have entered a place which has already been filled or it is out of range. Please Enter a number that hasn't been utilized\n";
        cin >> k;
        k--;
    }
    a[k] = sy;
    if (k == y)
    {
        a[z] = sc;
        showTic(a);
        cout << "Your Turn\n";
        cin >> k;
        k--;
        while (a[k] != 5)
        {
            cout << "You have entered a place which has already been filled or it is out of range. Please Enter a number that hasn't been utilized\n";
            cin >> k;
            k--;
        }
        a[k] = sy;
        if (k == p)
        {
            a[q] = sc;
            showTic(a);
            cout << "It's a Draw!!\n";
        }
        else
        {
            a[p] = sc;
            showTic(a);
            cout << "Computer Won\n";
        }
    }
    else
    {
        a[y] = sc;
        showTic(a);
        cout << "Computer Won\n";
    }
}

void hel_comp3(int a[], int sy, int x, int y, int z, int k, int sc)
{
    a[x] = sc;
    showTic(a);
    cout << "Your Turn\n";
    cin >> k;
    k--;
    while (a[k] != 5)
    {
        cout << "You have entered a place which has already been filled or it is out of range. Please Enter a number that hasn't been utilized\n";
        cin >> k;
        k--;
    }
    a[k] = sy;
    if (k == y)
    {
        a[z] = sc;
        showTic(a);
        cout << "Computer Won\n";
    }
    else
    {
        a[y] = sc;
        showTic(a);
        cout << "Computer Won\n";
    }
}
void comp1(int a[], int sy) // this function operates when the user plays 2nd as Player 2. That means the computer makes the first move
{
    int sc = 1 - sy; // sc and sy stores the values to show X and O in the output
    int k;
    a[0] = sc; // This is the first move be the computer. It is the one in which there is maximum probability of winning. If the user doen't enter 5 after this, then the shall definitely lose
    showTic(a);
    cout << "Your Turn\n";
    cin >> k;
    k--;
    while (a[k] != 5)
    {
        cout << "You have entered a place which has already been filled or it is out of range. Please Enter a number that hasn't been utilized\n"; // checks if the input is not out of bounds
        cin >> k;
        k--;
    }
    switch (k) // Here, there are 8 ways in which the user can input the 
    {
    case 1:
        hel_comp1(a, sy, 6, 3, 4, 8, 2, k, sc); // Here, the numbers signify a particular set of steps this helper function hel_comp1() will perform
        break;
    case 2:
        hel_comp1(a, sy, 6, 3, 8, 7, 4, k, sc); //done
        break;
    case 3:
        hel_comp1(a, sy, 4, 8, 2, 1, 6, k, sc); //done
        break;
    case 4:
        //special case
        a[8] = sc;
        a[k] = sy;
        showTic(a);
        cout << "Your Turn\n";
        cin >> k;
        k--;
        while (a[k] != 5)
        {
            cout << "You have entered a place which has already been filled or it is out of range. Please Enter a number that hasn't been utilized\n";
            cin >> k;
            k--;
        }
        a[k] = sy;
        if (k == 6)
        {
            hel_comp3(a, sy, 2, 1, 5, k, sc);
        }
        else if (k == 2)
        {
            hel_comp3(a, sy, 6, 3, 7, k, sc);
        }
        else if (k == 1)
        {
            hel_comp2(a, sy, 7, 6, 2, 5, 3, k, sc);
        }
        else if (k == 3)
        {
            hel_comp2(a, sy, 5, 2, 6, 7, 1, k, sc);
        }
        else if (k == 5)
        {
            hel_comp2(a, sy, 3, 6, 2, 1, 7, k, sc);
        }
        else if (k == 7)
        {
            hel_comp2(a, sy, 1, 2, 6, 3, 5, k, sc);
        }
        break;
    case 5:
        hel_comp1(a, sy, 6, 3, 4, 8, 2, k, sc); //done
        break;
    case 6:
        hel_comp1(a, sy, 8, 4, 2, 1, 5, k, sc); //done
        break;
    case 7:
        hel_comp1(a, sy, 4, 8, 6, 3, 2, k, sc); //done
        break;
    case 8:
        hel_comp1(a, sy, 6, 3, 2, 4, 1, k, sc); //done
        break;
    default:
        cout << "You Entered a wrong key\n";
        break;
    }
}
void comp2_diag(int a[], int sy, int x, int y, int z, int p,int q,int k, int sc)
{
    a[x] = sc;
    showTic(a);
    cout << "Your Turn:\n";
    cin >> k;
    k--;
    while (a[k] != 5)
    {
        cout << "You have entered a place which has already been filled or it is out of range. Please Enter a number that hasn't been utilized\n";
        cin >> k;
        k--;
    }
    a[k] = sy;
    if (k == y)
    {
        a[z] = sc;
        showTic(a);
        cout << "Your Turn:\n";
        cin >> k;
        k--;
        while (a[k] != 5)
        {
            cout << "You have entered a place which has already been filled or it is out of range. Please Enter a number that hasn't been utilized\n";
            cin >> k;
            k--;
        }
        a[k] = sy;
        if(k==p)//1st number
        {
            a[q]=sc;
            showTic(a);
            cout << "It's a Draw:\n";
        }
        else if (k==q)
        {
            a[p]=sc;
            showTic(a);
            cout << "It's a Draw:\n";
        }
        else
        {
            a[q]=sc;
            showTic(a);
            cout << "It's a Draw:\n";
        }
    }
    else
    {
        a[y] = sc;
        showTic(a);
        cout << "Computer Won\n";
    }
}
void comp2_diag2(int a[], int sy, int dig[], int k, int sc, int col[])
{
    cout << "Your Turn:\n";
    cin >> k;
    k--;
    while (a[k] != 5)
    {
        cout << "You have entered a place which has already been filled or it is out of range. Please Enter a number that hasn't been utilized\n";
        cin >> k;
        k--;
    }
    a[k] = sy;
    if (k == col[0])
    {
        hel_comp2(a, sy, dig[0], dig[1], dig[2], dig[3], dig[4], k, sc);
    }
    else if (k == col[1])
    {
        hel_comp2(a, sy, dig[5], dig[6], dig[7], dig[8], dig[9], k, sc);
    }
    else if (k == col[2])
    {
        hel_comp2(a, sy, dig[10], dig[11], dig[12], dig[13], dig[14], k, sc);
    }
    else if (k == col[3]) //different
    {
        comp2_diag(a, sy, dig[15], dig[16], dig[17],dig[18], dig[19], k, sc);
    }
    else if (k == col[4])
    {
        hel_comp2(a, sy, dig[20], dig[21], dig[22], dig[23], dig[24], k, sc);
    }
    else if (k == col[5]) //different
    {
        comp2_diag(a, sy, dig[25], dig[26], dig[27],dig[28], dig[29], k, sc);
    }
    else if (k == col[6])
    {
        hel_comp2(a, sy, dig[30], dig[31], dig[32], dig[33], dig[34], k, sc);
    }
}
void comp_middle1(int a[], int sy, int b[], int k, int sc)
{
    a[b[0]] = sc; //0
    showTic(a);
    cout << "Your Turn:\n";
    cin >> k;
    k--;
    while (a[k] != 5)
    {
        cout << "You have entered a place which has already been filled or it is out of range. Please Enter a number that hasn't been utilized\n";
        cin >> k;
        k--;
    }
    a[k] = sy;
    if (k == b[1]) //2
    {
        a[b[2]] = sc; //2
        showTic(a);
        cout << "Your Turn:\n";
        cin >> k;
        k--;
        while (a[k] != 5)
        {
            cout << "You have entered a place which has already been filled or it is out of range. Please Enter a number that hasn't been utilized\n";
            cin >> k;
            k--;
        }
        a[k] = sy;
        if (k == b[3]) //3
        {
            a[b[4]] = sc; //4
            showTic(a);
            cout << "Computer Won\n";
        }
        else
        {
            a[b[3]] = sc; //3
            showTic(a);
            cout << "Computer Won\n";
        }
    }
    else if (k == b[7]) //5
    {
        a[b[8]] = sc; //8
        showTic(a);
        cout << "Your Turn:\n";
        cin >> k;
        k--;
        while (a[k] != 5)
        {
            cout << "You have entered a place which has already been filled or it is out of range. Please Enter a number that hasn't been utilized\n";
            cin >> k;
            k--;
        }
        a[k] = sy;
        if (k == b[9]) //9
        {
            a[b[10]] = sc; //10
            showTic(a);
            cout << "It's a Draw:\n";
        }
        else
        {
            a[b[9]] = sc; //9
            showTic(a);
            cout << "Computer Won\n";
        }
    }
    else if (k == b[4])//3
    {
        a[b[6]] = sc; //11
        showTic(a);
        cout << "Your Turn:\n";
        cin >> k;
        k--;
        while (a[k] != 5)
        {
            cout << "You have entered a place which has already been filled or it is out of range. Please Enter a number that hasn't been utilized\n";
            cin >> k;
            k--;
        }
        a[k] = sy;
        if(k == b[1] )
        {
            a[b[9]] = sc;
            showTic(a);
            cout << "It's a Draw:\n";            
        }
        else
        {
            a[b[1]] = sc;
            showTic(a);
            cout << "It's a Draw:\n";  
        }
    }
    else if (k == b[9]) // 6
    {
        a[b[11]] = sc; //11
        showTic(a);
        cout << "Your Turn:\n";
        cin >> k;
        k--;
        while (a[k] != 5)
        {
            cout << "You have entered a place which has already been filled or it is out of range. Please Enter a number that hasn't been utilized\n";
            cin >> k;
            k--;
        }
        a[k] = sy;
        if(k == b[4] )
        {
            a[b[6]] = sc;
            showTic(a);
            cout << "It's a Draw:\n";            
        }
        else
        {
            a[b[4]] = sc;
            showTic(a);
            cout << "It's a Draw:\n";  
        }   
    }
    else//8
    {
        a[b[4]] = sc; //11
        showTic(a);
        cout << "Your Turn:\n";
        cin >> k;
        k--;
        while (a[k] != 5)
        {
            cout << "You have entered a place which has already been filled or it is out of range. Please Enter a number that hasn't been utilized\n";
            cin >> k;
            k--;
        }
        a[k] = sy;
        if(k == b[2] )
        {
            a[b[1]] = sc;
            showTic(a);
            cout << "It's a Draw:\n";            
        }
        else
        {
            a[b[2]] = sc;
            showTic(a);
            cout << "Computer Won\n";  
        }
    }
    
}
void comp2_top(int a[], int sy, int dig[], int k, int sc, int col[])
{
    cout << "Your Turn:\n";
    cin >> k;
    k--;
    while (a[k] != 5)
    {
        cout << "You have entered a place which has already been filled or it is out of range. Please Enter a number that hasn't been utilized\n";
        cin >> k;
        k--;
    }
    a[k] = sy;
    if (k == col[0])
    {
        hel_comp2(a, sy, dig[0], dig[1], dig[2], dig[3], dig[4], k, sc);
    }
    else if (k == col[1])
    {
        hel_comp2(a, sy, dig[5], dig[6], dig[7], dig[8], dig[9], k, sc);
    }
    else if (k == col[2])
    {
        hel_comp2(a, sy, dig[10], dig[11], dig[12], dig[13], dig[14], k, sc);
    }
    else if (k == col[3])
    {
        hel_comp2(a, sy, dig[15], dig[16], dig[17], dig[18], dig[19], k, sc);
    }
    else if (k == col[4])
    {
        comp2_diag(a, sy, dig[20], dig[21], dig[22],dig[23], dig[24], k, sc);
    }
    else if (k == col[5])
    {
        hel_comp1(a, sy, dig[25], dig[26], dig[27], dig[28], dig[29], k, sc);
    }
    else
    {
        hel_comp2(a, sy, dig[30], dig[31], dig[32], dig[33], dig[34], k, sc);
    }
}
void comp2(int a[], int sy)
{
    int i, j, k, sc = 1 - sy;
    cout << "Your Turn:\n";
    cin >> k;
    k--;
    while (a[k] != 5)
    {
        cout << "You have entered a place which has already been filled or it is out of range. Please Enter a number that hasn't been utilized\n";
        cin >> k;
        k--;
    }
    a[k] = sy;
    if (k == 4) //middle
    {
        a[0] = sc;
        showTic(a);
        cout << "Your Turn:\n";
        cin >> k;
        k--;
        while (a[k] != 5)
        {
            cout << "You have entered a place which has already been filled or it is out of range. Please Enter a number that hasn't been utilized\n";
            cin >> k;
            k--;
        }
        a[k] = sy;
        if (k == 1)
        {
            int b[] = {7, 2, 6, 8, 3, 3, 5, 5, 3, 6, 2, 2};
            comp_middle1(a, sy, b, k, sc);
        }
        else if (k == 2)
        {
            comp2_diag(a, sy, 6, 3, 5,1,7, k, sc);
        }
        else if (k == 3)
        {
            int b[] = {5, 6, 2, 8, 1, 1, 7, 7, 1, 2, 6, 6};
            comp_middle1(a, sy, b, k, sc);
        }
        else if (k == 5)
        {
            hel_comp2(a, sy, 3, 6, 2, 1, 7, k, sc);
        }
        else if (k == 6)
        {
            comp2_diag(a, sy, 2, 1, 7,3,5, k, sc);
        }
        else if (k == 7)
        {
            hel_comp2(a, sy, 1, 2, 6, 3, 5, k, sc);
        }
        else
        {
            comp2_diag(a, sy, 6, 3, 5,7,1, k, sc);
        }
    }
    else if (k % 2) //top bottom
    {
        a[4] = sc;
        showTic(a);
        if (k == 1)
        {
            int dig[] = {2, 6, 3, 5, 8, 0, 8, 5, 3, 6, 0, 8, 6, 2, 5, 2, 6, 8, 0, 3, 0, 8, 7,2,5, 3, 5, 6, 2, 0, 3, 5, 2, 6, 7};
            int col[] = {0, 2, 3, 5, 6, 7, 8};
            comp2_top(a, sy, dig, k, sc, col);
        }
        else if (k == 5)
        {
            int dig[] = {8, 0, 1, 7, 6, 2, 6, 7, 1, 0, 2, 6, 0, 8, 7, 8, 0, 6, 2, 1, 2, 6, 3,8,7, 1, 7, 0, 8, 2, 1, 7, 8, 0, 3};
            int col[] = {2, 8, 1, 7, 0, 3, 6};
            comp2_top(a, sy, dig, k, sc, col);
        }
        else if (k == 7)
        {
            int dig[] = {6, 2, 5, 3, 0, 8, 0, 3, 5, 2, 8, 0, 2, 6, 3, 6, 2, 0, 8, 5, 8, 0, 1,6,3, 5, 3, 2, 6, 8, 5, 3, 6, 2, 1};
            int col[] = {8, 6, 5, 3, 2, 1, 0};
            comp2_top(a, sy, dig, k, sc, col);
        }
        else
        {
            int dig[] = {0, 8, 7, 1, 2, 6, 2, 1, 7, 8, 6, 2, 8, 0, 1, 0, 8, 2, 6, 7, 6, 2, 5,0,1, 7, 1, 8, 0, 6, 7, 1, 0, 8, 5};
            int col[] = {6, 0, 7, 1, 8, 5, 2};
            comp2_top(a, sy, dig, k, sc, col);
        }
    }
    else //diag
    {
        a[4] = sc;
        showTic(a);
        if (k == 0)
        {
            int dig[] = {2, 6, 3, 5, 8, 1, 7, 3, 5, 8, 6, 2, 1  , 7, 8, 2, 6, 3,8,7, 3, 5, 7, 1, 2, 6, 2, 1,8,5, 3, 5, 2, 6, 7};
            int col[] = {1, 2, 3, 5, 6, 7, 8};
            comp2_diag2(a, sy, dig, k, sc, col);
        }
        else if (k == 2)
        {
            int dig[] = {8, 0, 1, 7, 6, 5, 3, 1, 7, 6, 0, 8, 5, 3, 6, 8, 0, 1,6,3, 1, 7, 3, 5, 8, 0, 8, 5,6,7, 1, 7, 8, 0, 3};
            int col[] = {5, 8, 1, 7, 0, 3, 6};
            comp2_diag2(a, sy, dig, k, sc, col);
        }
        else if (k == 6)
        {
            int dig[] = {0, 8, 7, 1, 2, 3, 5, 7, 1, 2, 8, 0, 3, 5, 2, 0, 8, 7,2,5, 7, 1, 5, 3, 0, 8, 0, 3,2,1, 7, 1, 0, 8, 5};
            int col[] = {3, 0, 7, 1, 8, 5, 2};
            comp2_diag2(a, sy, dig, k, sc, col);
        }
        else if (k == 8)
        {
            int dig[] = {6, 2, 5, 3, 0, 7, 1, 5, 3, 0, 2, 6, 7, 1, 0, 6, 2, 5,0,1, 5, 3, 1, 7, 6, 2, 6, 7,0,3, 5, 3, 6, 2, 1};
            int col[] = {7, 6, 5, 3, 2, 1, 0};
            comp2_diag2(a, sy, dig, k, sc, col);
        }
    }
}
void playgame() // The main game is situated in this function. Both the cases where user plays as Player 1 and Player 2 are stated in this
{
    int a[9];
    int i, d, sy;
    for (i = 0; i < 9; i++)
    {
        a[i] = 5;
    }
    cout << "Instructions: Enter numbers from 1 to 9 to insert your symbols in the designated place. Like shown below: \n";
    cout << "-------------\n";
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << "|";
            cout << " " << i * 3 + j + 1 << " ";
        }
        cout << "|\n";
        cout << "-------------\n";
    }
    cout << "Which symbol do you want to choose\n? (0 for O and 1 for X)\n";
    cin >> sy;
    cout << "Do you want to play first or would you let computer play first: \n (1 to play first, 0 to play 2nd)\n";
    cin >> d;
    if (d)
    {
        comp2(a, sy); //User plays first move
    }
    else
    {
        comp1(a, sy); //Computer plays first move
    }
}
int main()
{
    int i = 1;
    while (i)
    {
        playgame(); //This is the main game function that runs the game
        cout << "Play Again - 1 , Exit - 0\n"; // After one game is over, this provides the user the chance whether he wants to play another game or not, and proceed accordingly.
        cin >> i;
    }
    return 0;
}
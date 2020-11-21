// To emulate a tic-tac-toe game where computer never loses, and wins whenever possible
#include <iostream>
using namespace std;
void initSquare(int ar[3][3])   //function to initialize all array elements representing the tic-tac-toe square by 2(unfilled state)
{
    int i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
            ar[i][j] = 2;
    }
}
void printSquare(int ar[3][3])  //function to print the tic-tac-toe square at current state of the game
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if(ar[i][j]==2)     //unfilled boxes are represented by 2 in the array
                cout << "   ";
            if (ar[i][j] == 0)  //O's are represented by 0 in the array
                cout << " O ";
            if (ar[i][j] == 1)  //X's are represented by 1 in the array
                cout << " X ";
            if (j != 2)
                cout << "|";
        }
        cout << endl;
        if (i != 2)
            cout << "-----------" << endl;
    }
    cout << "\n\n";
}
void fillArray(int ar[3][3],int pm,char p)     //function to fill the pm th box with X or O
{
    if (p == 'O')
        ar[(pm / 3)][(pm % 3)] = 0;
    else
        ar[(pm / 3)][(pm % 3)] = 1;
}
int userInput(char p,int ar[3][3])              //function to input user move
{
    int pm;
    cout << "Enter square no. where you want to put " << p << ":" << endl;
    cin >> pm;
    pm = pm - 1;
    while (ar[(pm / 3)][(pm % 3)] != 2)         //checking that user move is not invalid
    {
        cout << "That square is filled. Enter some unfilled square no.:" << endl;
        cin >> pm;
        pm = pm - 1;
    }
    fillArray(ar,pm,p);
    printSquare(ar);
    return pm;
}
int checkPossWin(int ar[3][3],char p)           //function to check for possible wins in next move i.e. 2 X's or 2 O's in one row or column or diagonal
{
    int a;
    if (p == 'X')
        a = 1;
    else
        a = 0;
    if ((ar[0][0]==a&&ar[0][1]==a&&ar[0][2]==2)|| (ar[0][0] == a && ar[0][1] == 2 && ar[0][2] == a)|| (ar[0][0] == 2 && ar[0][1] == a && ar[0][2] == a))
    {
        if (ar[0][0] == 2)
            return 0;
        if (ar[0][1] == 2)
            return 1;
        else
            return 2;
    }
    else if ((ar[1][0] ==a&& ar[1][1]==a && ar[1][2] == 2)||(ar[1][0] == a && ar[1][1] == 2 && ar[1][2] == a)|| (ar[1][0] == 2 && ar[1][1] == a && ar[1][2] == a))
    {
        if (ar[1][0] == 2)
            return 3;
        if (ar[1][1] == 2)
            return 4;
        else
            return 5;
    }
    else if ((ar[2][0] ==a&& ar[2][1] ==a&&ar[2][2] == 2)|| (ar[2][0] == a && ar[2][1] == 2 && ar[2][2] == a)|| (ar[2][0] == 2 && ar[2][1] == a && ar[2][2] == a))
    {
        if (ar[2][0] == 2)
            return 6;
        if (ar[2][1] == 2)
            return 7;
        else
            return 8;
    }
    else if ((ar[0][0]==a&&ar[1][0]==a&& ar[2][0] ==2)|| (ar[0][0] == a && ar[1][0] == 2 && ar[2][0] == a)||(ar[0][0] == 2 && ar[1][0] == a && ar[2][0] == a))
    {
        if (ar[0][0] == 2)
            return 0;
        if (ar[1][0] == 2)
            return 3;
        else
            return 6;
    }
    else if ((ar[0][1]==a&& ar[1][1] ==a&&ar[2][1] ==2)|| (ar[0][1] == a && ar[1][1] == 2 && ar[2][1] == a)|| (ar[0][1] == 2 && ar[1][1] == a && ar[2][1] == a))
    {
        if (ar[0][1] == 2)
            return 1;
        if (ar[1][1] == 2)
            return 4;
        else
            return 7;
    }
    else if ((ar[0][2]==a&&ar[1][2]==a&&ar[2][2] == 2)|| (ar[0][2] == a && ar[1][2] == 2 && ar[2][2] == a)|| (ar[0][2] == 2 && ar[1][2] == a && ar[2][2] == a))
    {
        if (ar[0][2] == 2)
            return 2;
        if (ar[1][2] == 2)
            return 5;
        else
            return 8;
    }
    else if ((ar[0][0]==a&& ar[1][1]==a&& ar[2][2] == 2)|| (ar[0][0] == a && ar[1][1] == 2 && ar[2][2] == a)|| (ar[0][0] == 2 && ar[1][1] == a && ar[2][2] == a))
    {
        if (ar[0][0] == 2)
            return 0;
        if (ar[1][1] == 2)
            return 4;
        else
            return 8;
    }
    else if ((ar[0][2]==a&&ar[1][1]==a&&ar[2][0]==2)|| (ar[0][2] == a && ar[1][1] == 2 && ar[2][0] == a)|| (ar[0][2] == 2 && ar[1][1] == a && ar[2][0] == a))
    {
        if (ar[0][2] == 2)
            return 2;
        if (ar[1][1] == 2)
            return 4;
        else
            return 6;
    }
    return -1;
}
int checkGameEnd(int ar[3][3])      //function to check if a draw has been reached, i.e. game has ended
{
    int i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (ar[i][j] == 2)
                return 0;
        }
    }
    cout << "It is a draw\n" << endl;
    return 1;
}
int main()                          //main function or driver function
{
    int pn, x, y, cn, i, j, pm, n; int ar[3][3]; char p, c; 
    do {
        initSquare(ar);
        cout << "Welcome to a game of tic-tac-toe!\n";
        cout << "Do you want to be Player 1 or Player 2?\nEnter 1 or 2:\n";
        cin >> pn;                  //inputting user preference to play first or second. Player 1 plays with X. Player 2 with O.
        cn = (pn == 1) ? 2 : 1;
        p = (pn == 1) ? 'X' : 'O';
        c = (cn == 1) ? 'X' : 'O';
        printSquare(ar);
        switch (pn)
        {
            case 1: pm = userInput(p, ar);          //user is Player 1
                    if (pm == 0 || pm == 2 || pm == 6 || pm == 8)       //if user plays a corner first
                    {
                        cout << "Computer has played with " << c << ":\n";
                        fillArray(ar, 4, c);                            //computer plays centre
                        printSquare(ar);
                        while (checkGameEnd(ar) != 1)
                        {
                            pm = userInput(p, ar);
                            if (checkGameEnd(ar) == 1)
                                break;
                            cout << "Computer has played with " << c << ":\n";
                            y = checkPossWin(ar, c);
                            if (y != -1)
                            {
                                fillArray(ar, y, c);
                                printSquare(ar);
                                cout << "Computer has won!" << endl;
                                break;
                            }
                            else
                            {
                                x = checkPossWin(ar, p);
                                if (x != -1)
                                fillArray(ar, x, c);
                                else
                                {
                                    if (ar[0][1] == 2)
                                        fillArray(ar, 1, c);
                                    else if (ar[1][0] == 2)
                                        fillArray(ar, 3, c);
                                    else if (ar[1][2] == 2)
                                        fillArray(ar, 5, c);
                                    else if (ar[2][1] == 2)
                                        fillArray(ar, 7, c);
                                    else
                                    {
                                        int temp = -1;
                                        for (i = 0; i < 3; i++)
                                        {
                                            for (j = 0; j < 3; j++)
                                            {
                                                if (ar[i][j] == 2)
                                                {
                                                    temp = (i * 3) + j;
                                                    break;
                                                }
                                            }
                                        }
                                        fillArray(ar, temp, c);
                                    }
                                }
                                printSquare(ar);
                            }
                            if (y!= - 1)
                                break;
                        }
                    }
                    else if (pm == 4)
                    {
                        cout << "Computer has played with " << c << ":\n";
                        fillArray(ar, 0, c);
                        printSquare(ar);
                        while (checkGameEnd(ar) != 1)
                        {
                            pm = userInput(p, ar);
                            if (checkGameEnd(ar) == 1)
                                break;
                            cout << "Computer has played with " << c << ":\n";
                            y = checkPossWin(ar, c);
                            if (y != -1)
                            {
                                fillArray(ar, y, c);
                                printSquare(ar);
                                cout << "Computer has won!" << endl;
                                break;
                            }
                            else
                            {
                                x = checkPossWin(ar, p);
                                if (x != -1)
                                    fillArray(ar, x, c);
                                else
                                {
                                    int temp = -1;
                                    for (i = 0; i < 3; i++)
                                    {
                                        for (j = 0; j < 3; j++)
                                        {
                                            if (ar[i][j] == 2)
                                            {
                                                temp = (i * 3) + j;
                                                break;
                                            }
                                        }
                                    }
                                    fillArray(ar, temp, c);
                                }
                                printSquare(ar);
                            }
                            if (y != -1)
                                break;
                        }
                    }
                    else if (pm == 1 || pm == 3 || pm == 5 || pm == 7)
                    {
                        cout << "Computer has played with " << c << ":\n";
                        fillArray(ar, 4, c);
                        printSquare(ar);
                        int pm1 = userInput(p, ar);
                        if (abs(4 - pm) == abs(4 - pm1))
                        {
                            cout << "Computer has played with " << c << ":\n";
                            fillArray(ar, 0, c);
                            printSquare(ar);
                            int pm1 = userInput(p, ar);
                            cout << "Computer has played with " << c << ":\n";
                            x = checkPossWin(ar, p);
                            if (x != -1)
                            {
                                fillArray(ar, x, c);
                                printSquare(ar);
                                int pm1 = userInput(p, ar);
                                cout << "Computer has played with " << c << ":\n";
                                y = checkPossWin(ar, c);
                                if (y != -1)
                                {
                                    fillArray(ar, y, c);
                                    printSquare(ar);
                                    cout << "Computer has won!" << endl;
                                    break;
                                }
                            }
                            else
                            {
                                while (checkGameEnd(ar) != 1)
                                {
                                    cout << "Computer has played with " << c << ":\n";
                                    y = checkPossWin(ar, c);
                                    if (y != -1)
                                    {
                                        fillArray(ar, y, c);
                                        printSquare(ar);
                                        cout << "Computer has won!" << endl;
                                        break;
                                    }
                                    else
                                    {
                                        x = checkPossWin(ar, p);
                                        if (x != -1)
                                            fillArray(ar, x, c);
                                        else
                                        {
                                            int temp = -1;
                                            for (i = 0; i < 3; i++)
                                            {
                                                for (j = 0; j < 3; j++)
                                                {
                                                    if (ar[i][j] == 2)
                                                    {
                                                        temp = (i * 3) + j;
                                                        break;
                                                    }
                                                }
                                            }
                                            fillArray(ar, temp, c);
                                        }
                                        printSquare(ar);
                                        if (checkGameEnd(ar) == 1)
                                            break;
                                        pm = userInput(p, ar);
                                    }
                                    if(y!=-1)
                                        break;
                                }
                            }
                        }
                        else
                        {
                            while (checkGameEnd(ar) != 1)
                            {
                                cout << "Computer has played with " << c << ":\n";
                                y = checkPossWin(ar, c);
                                if (y != -1)
                                {
                                    fillArray(ar, y, c);
                                    printSquare(ar);
                                    cout << "Computer has won!" << endl;
                                    break;
                                }
                                else
                                {
                                    x = checkPossWin(ar, p);
                                    if (x != -1)
                                        fillArray(ar, x, c);
                                    else
                                    {
                                        int temp = -1;
                                        for (i = 0; i < 3; i++)
                                        {
                                            for (j = 0; j < 3; j++)
                                            {
                                                if (ar[i][j] == 2)
                                                {
                                                    temp = (i * 3) + j;
                                                    break;
                                                }
                                            }
                                        }
                                        fillArray(ar, temp, c);
                                    }
                                    printSquare(ar);
                                    if (checkGameEnd(ar) == 1)
                                        break;
                                    pm = userInput(p, ar);
                                }
                                if(y!=-1)
                                    break;
                            }
                        }
                    }
                    break;
            //if computer is 1st player
            case 2: cout << "Computer has played with " << c << ":\n";
                    fillArray(ar, 0, c);
                    printSquare(ar);
                    pm = userInput(p, ar);
                    if (pm != 4)
                    {
                        cout << "Computer has played with " << c << ":\n";
                        if (pm != 1 && pm != 2)
                        {
                            fillArray(ar, 2, c);
                            printSquare(ar);
                        }
                        else
                        {
                            fillArray(ar, 6, c);
                            printSquare(ar);
                        }
                        pm = userInput(p, ar);
                        cout << "Computer has played with " << c << ":\n";
                        y = checkPossWin(ar, c);
                        if (y != -1)
                        {
                            fillArray(ar, y, c);
                            printSquare(ar);
                            cout << "Computer has won!" << endl;
                            break;
                        }
                        else
                        {
                            fillArray(ar, 4, c);
                            printSquare(ar);
                        }
                        pm = userInput(p, ar);
                        cout << "Computer has played with " << c << ":\n";
                        y = checkPossWin(ar, c);
                        if (y != -1)
                        {
                            fillArray(ar, y, c);
                            printSquare(ar);
                            cout << "Computer has won!" << endl;
                            break;
                        }
                    }
                    else
                    {
                        cout << "Computer has played with " << c << ":\n";
                        fillArray(ar, 8, c);
                        printSquare(ar);
                        pm = userInput(p, ar);
                        if (pm == 2 || pm == 6)
                        {
                            cout << "Computer has played with " << c << ":\n";
                            if (pm == 2)
                            {
                                fillArray(ar, 6, c);
                                printSquare(ar);
                            }
                            else
                            {
                                fillArray(ar, 2, c);
                                printSquare(ar);
                            }
                            pm = userInput(p, ar);
                            cout << "Computer has played with " << c << ":\n";
                            y = checkPossWin(ar, c);
                            if (y != -1)
                            {
                                fillArray(ar, y, c);
                                printSquare(ar);
                                cout << "Computer has won!" << endl;
                                break;
                            }
                        }
                        else
                        {
                            while (checkGameEnd(ar) != 1)
                            {
                                cout << "Computer has played with " << c << ":\n";
                                y = checkPossWin(ar, c);
                                if (y != -1)
                                {
                                    fillArray(ar, y, c);
                                    printSquare(ar);
                                    cout << "Computer has won!" << endl;
                                    break;
                                }
                                else
                                {
                                    x = checkPossWin(ar, p);
                                    if (x != -1)
                                        fillArray(ar, x, c);
                                    else
                                    {
                                        int temp = -1;
                                        for (i = 0; i < 3; i++)
                                        {
                                            for (j = 0; j < 3; j++)
                                            {
                                                if (ar[i][j] == 2)
                                                {
                                                    temp = (i * 3) + j;
                                                    break;
                                                }
                                            }
                                        }
                                        fillArray(ar, temp, c);
                                    }
                                    printSquare(ar);
                                    if (checkGameEnd(ar) == 1)
                                        break;
                                    pm = userInput(p, ar);
                                }
                                if(y!=-1)
                                    break;
                            }
                        }
                    }
                    break;
            default: cout << "Please enter 1 or 2 only:" << endl;
        }
        cout << "\n\nDo you wish to play again? Enter 1 for Yes or 0 for No:" << endl;
        cin >> n;
    }while (n==1);
    cout << "\nThank you for playing!\n";
}   


/*
Name - Varun Gupta
Roll Number - 18MA20050
Logic - The main logic used is that if computer plays first then it makes optimized moves hard coded into it to win and if plays second then if
        the user plays optimally then computer tries to draw or win if user plays bad moves.The moves have been hard coded and represent the cases when a particular
        move would be made by the user.
*/

#include <iostream>  // Including the I/O library

using namespace std;  // Using the required namespace for the functions
                      // We can also use std::cout if we don't particularly use the namespace

/*
Defination of all the functions that are used in this particular program
is provided here
*/

void printTictactoe(int tictactoe[]);    //function to print the whole tictactoe at the current state

void ExampleTictactoe();                 // function to print the example of tictactoe and cell positions

int ValidMove(int tictactoe[]);         //function to check that user's next move is valid or not

void Userplaysfirst(int tictactoe[]);   //function to play the game when starting player is User

void Computerplaysfirst(int tictactoe[]); // function to play the game when starting player is Computer

void UserplaysFirst_Edge(int tictactoe[],int final[],int intermediate[],int user,int computer);    //function that focuses on the consecutive moves if user's first move is on an edge cell

void UserplaysFirst_Middle_Second_Edge(int tictactoe[],int optimized[],int user,int computer);                //function that focuses on the consecutive moves if user's first move is on middle cell

void UserplaysFirst_Corner(int tictactoe[], int final[] , int intermediate[],int user,int computer);     //function that focuses on the consecutive moves if user's first move is on an corner cell

void UserplaysFirst_Middle_Second_Corner(int tictactoe[], int optimized[], int start,int user,int computer);     //function that focuses on the consecutive moves if user's first move is on an middle cell or second move is on edge

void Result(int tictactoe[], int final[], int start,int user,int computer,int number);     // function which would work one particular hard coded manner when parent function has been called after some moves have been played and lead to a result

void Draw(int tictactoe[], int user);                   // function that just outputs if the game is drawn

void Win(int tictactoe[]);                    //  function that just outputs if the game is won by the computer

/*
The program starts from here and functions have been mostly defined as they are used in the flow of the program.
*/

int main()            // Main function from where the whole program is initiated
{
    bool play = true;   //variable to ensure if the game will be played again and again
    while(play)         // runs until user wants to play
    {
        int playing;            // to get user answer for playing
        int tictactoe[9];       // stores the state of the game
        int user;             //variable to store when user plays i.e first or second
        cout << "Enter number between 1 and 9 to select that respective cell in the TicTacToe, as shown below:\n";
        ExampleTictactoe();          // printing example of initial example TicTacToe
        for(int i=0;i<9;i++)
            tictactoe[i] = -1;              // making an initial state for the game to show that no cell is occupied initially
        cout << "Which Player do you want to play as:\n1)Player 1(Symbol - X ) Enter 1 \n2)Player 2(Symbol - O) Enter 2\n";
        cin >> user;                       // getting user's playing number
        while(user!=1 && user!=2)          // getting if got invalid
        {
            cout << "Enter a valid Player Number i.e 1 or 2:\n";
            cin >> user;
        }
        if(user == 1)
            Userplaysfirst(tictactoe);          // if user plays first
        else
            Computerplaysfirst(tictactoe);      // if computer plays first
        cout << "\nPlay Again - Enter 1 \nExit - Else\n";
        cin >> playing;
        if(playing == 1)            // if user plays again or not
            play = true;
        else
            play = false;
    }
    return 0;
}

void ExampleTictactoe()             //function that prints an tictactoe example with the cell number's in them
{
    cout << "\n";
    for(int i=0;i<9;i++)
    {
        cout << "|";
        cout << " " << i + 1 << " ";
        if(i==2 || i==5 || i== 8)
            cout << "|\n";
        if(i==2 || i==5)
            cout << "-------------\n";
    }
    cout << "\n";
    return;
}

void printTictactoe(int tictactoe[])    //function to print the tictactoe at the current state
{
    int i,j;
    cout << "\n";
    for(i=0;i<9;i++)                    // runs through each cell
    {
        cout << "|";
        if(tictactoe[i]==1)             // outputs depending upon the player type
            cout << " X ";
        else
        {
            if(tictactoe[i] == 2)
                cout << " O ";
            else                        // empty if no move has been played here yet
                cout << "   ";
        }
        if(i==2 || i==5 || i== 8)
            cout << "|\n";
        if(i==2 || i==5)
            cout << "-------------\n";
    }
    cout << "\n";
    cout << "X - Player 1 | O - Player 2\n";            // gives identification of each player symbol
    return;
}

int ValidMove(int tictactoe[])      // function which verifies that next move of user is valid or not
{
    int check;
    cout << "\nEnter a number between 1 and 9 to place your move in that cell, respectively:\n";
    cin >> check;
    check = check - 1;
    while(check < 0 || check > 8 || tictactoe[check]!=-1)                           // consition for invalidity
    {
        cout << "\nEnter a valid cell number for your move (as this is invalid):\n";
        cin >> check;
        check = check - 1;
    }
    return check;
}

void Draw(int tictactoe[],int user)                      // function outputs if the game is drawn
{
    for(int i=0;i<9;i++)
    {
        if(tictactoe[i] == -1)
        {
            tictactoe[i] = user;
            break;
        }
    }
    printTictactoe(tictactoe);                  // to print the final tictactoe
    cout << "\nThe game concludes as a Draw.\n";
    return;
}

void Win(int tictactoe[])                       // function outputs if the game is won by the computer
{
    printTictactoe(tictactoe);                  // to print the final tictactoe
    cout << "\nThe Computer wins the game.!!!\n";
    return;
}

void Userplaysfirst(int tictactoe[])            // function to play the game when starting player is User
{
    int move = ValidMove(tictactoe);            // getting users initial valid move
    int user = 1;                               // storing computer and user's player number for use in future functions
    int computer = 2;
    tictactoe[move] = user;
    move = move + 1;
    switch ( move )                             // now setting the hard coded optimized moves for the computer to win or draw the game for any particular user move
    {
        case 1:                                 // places in cell one
        {
            tictactoe[5-1] = computer;          // if user places other than middle cell then it is optimized to move their and hence in all cases
            printTictactoe(tictactoe);
            int intermediate[] = {2,3,4,6,7,8,9};                                                   // all the cases consists of respective optimized hard coded cell numbers through respective moves of users to
            int final[] = {3,7,4,6,9,2,8,4,6,9,7,3,2,8,9,3,7,4,9,8,4,6,8,2,3,7,3,2,9,6,4,6,3,7,8};  // to get the resulted output
            UserplaysFirst_Corner(tictactoe,final,intermediate,user,computer);                 // when the respective move of user is in corner
            break;
        }
        case 2:                                 // places in cell two
        {                                       // the respective cell numbers for best output
            tictactoe[5-1] = computer;          // best move for computer to win
            printTictactoe(tictactoe);
            int intermediate[] = {1,3,4,6,7,8,9};
            int final[] = {3,7,4,6,9,1,9,6,4,7,1,9,7,3,6,3,7,9,1,4,1,9,8,3,6,4,6,7,3,1,4,6,3,7,8};
            UserplaysFirst_Edge(tictactoe,final,intermediate,user,computer);                   // when the respective move of user is in edge
            break;
        }
        case 3:                                 // places in cell three (corner)
        {
            tictactoe[5-1] = computer;          // middle cell best move
            printTictactoe(tictactoe);
            int intermediate[] = {6,9,2,8,1,4,7};   // optimized movees
            int final[] = {9,1,2,8,7,6,4,2,8,7,1,9,6,4,7,9,1,2,7,4,2,8,4,7,9,1,9,6,7,8,2,8,9,1,4};
            UserplaysFirst_Corner(tictactoe,final,intermediate,user,computer);// when the respective move of user is in corner
            break;
        }
        case 4:                                 // places in cell four(edge)
        {
            tictactoe[5-1] = computer;          // middle cell best move
            printTictactoe(tictactoe);
            int intermediate[] = {7,1,8,2,9,6,3};       // optimized cell moves
            int final[] = {1,9,8,2,3,7,3,2,8,7,3,9,1,2,1,9,3,7,8,7,3,6,1,2,8,2,9,1,7,8,2,1,9,6};
            UserplaysFirst_Edge(tictactoe,final,intermediate,user,computer);// when the respective move of user is in edge
            break;
        }
        case 5:                                 // places in cell five
        {
            tictactoe[0] = computer;            // if user places in middle cell then computer has to make moves in different manner
            printTictactoe(tictactoe);          // as user might play optimally and hence have to lead to draw
            int move2 = ValidMove(tictactoe);
            tictactoe[move2] = user;
            move2 = move2 + 1;                  // now depending on the second move of user we make optimized cell moves to get required output
            switch ( move2 )
            {
                case 2:                         // cell 2 i.e edge cell
                {
                    int optimized[] = {8,3,7,9,4,4,6,6,4,7,3,3};        // resepective optmized moves
                    UserplaysFirst_Middle_Second_Edge(tictactoe,optimized,user,computer);
                    break;
                }
                case 3:                         // cell 3 i.e corner cell
                {
                    int optimized[] = {7,4,6,2,8};        // resepective optmized moves
                    UserplaysFirst_Middle_Second_Corner(tictactoe,optimized,0,user,computer);
                    break;
                }
                case 4:                         // cell 4 i.e edge cell
                {
                    int optimized[] = {6,7,3,9,2,2,8,8,2,3,7,7};        // resepective optmized moves
                    UserplaysFirst_Middle_Second_Edge(tictactoe,optimized,user,computer);
                    break;
                }
                case 6:                         // cell 6 i.e edge cell
                {
                    int optimized[] = {4,7,3,2,8};        // resepective optmized moves
                    Result(tictactoe,optimized,0,user,computer,2);
                    break;
                }
                case 7:                         // cell 7 i.e corner cell
                {
                    int optimized[] = {3,2,8,4,6};        // resepective optmized moves
                    UserplaysFirst_Middle_Second_Corner(tictactoe,optimized,0,user,computer);
                    break;
                }
                case 8:                         // cell 8 i.e edge cell
                {
                    int optimized[] = {2,3,7,4,6};        // resepective optmized moves
                    Result(tictactoe,optimized,0,user,computer,2);
                    break;
                }
                case 9:                         // cell 9 i.e corner cell
                {
                    int optimized[] = {7,4,6,8,2};        // resepective optmized moves
                    UserplaysFirst_Middle_Second_Corner(tictactoe,optimized,0,user,computer);
                    break;
                }
            }
            break;
        }
        case 6:                                 // places in cell six
        {
            tictactoe[5-1] = computer;          // middle cell best move
            printTictactoe(tictactoe);
            int intermediate[] = {3,9,2,8,1,4,7};       // optimized cell moves
            int final[] = {9,1,2,8,7,3,7,8,2,1,3,7,1,9,8,9,1,7,3,2,3,7,4,9,8,2,8,1,9,3,2,8,1,4};
            UserplaysFirst_Edge(tictactoe,final,intermediate,user,computer);// when the respective move of user is in edge
            break;
        }
        case 7:                                 // places in cell seven
        {
            tictactoe[5-1] = computer;          // middle cell best move
            printTictactoe(tictactoe);
            int intermediate[] = {4,1,8,2,9,6,3};       // optimized cell moves
            int final[] = {1,9,8,2,3,4,6,8,2,3,9,1,4,6,3,1,9,8,3,6,8,2,6,4,1,9,1,4,3,2,8,2,1,9,6};
            UserplaysFirst_Corner(tictactoe,final,intermediate,user,computer);// when the respective move of user is in corner
            break;
        }
        case 8:                                 // places in cell eight
        {
            tictactoe[5-1] = computer;          // middle cell best move
            printTictactoe(tictactoe);
            int intermediate[] = {9,7,6,4,3,2,1};       // optimized cell moves
            int final[] = {7,3,6,4,1,9,1,4,6,3,9,1,3,7,4,7,3,1,9,6,9,1,2,7,4,6,4,3,7,9,6,4,7,3,2};
            UserplaysFirst_Edge(tictactoe,final,intermediate,user,computer);// when the respective move of user is in edge
            break;
        }
        case 9:                                 // places in cell nine
        {
            tictactoe[5-1] = computer;          // middle cell best move
            printTictactoe(tictactoe);
            int intermediate[] = {8,7,6,4,3,2,1};       // optimized cell moves
            int final[] = {7,3,6,4,1,8,2,6,4,1,3,7,2,1,7,3,6,1,2,6,4,2,8,7,3,7,8,1,4,6,4,7,3,2};
            UserplaysFirst_Corner(tictactoe,final,intermediate,user,computer);// when the respective move of user is in corner
            break;
        }
    }
    return;
}

void UserplaysFirst_Edge(int tictactoe[],int final[], int intermediate[],int user,int computer)    //function that focuses on the consecutive moves if user's first move is on an edge
{
    int move2 = ValidMove(tictactoe);                               // getting user next move
    tictactoe[move2] = user;
    move2 = move2 + 1;                                              // checking here for the cell number as we get index
    if(move2 == intermediate[0])                                    // respective further moves according to the moves of the user so that we get required output
        Result(tictactoe,final,0,user,computer,2);          // checking that range of the final moves
    else
    {
        if(move2 == intermediate[1])                                    // respective further moves according to the moves of the user so that we get required output
            Result(tictactoe,final,5,user,computer,2);          // checking that range of the final moves
        else
        {
            if(move2 == intermediate[2])                                    // respective further moves according to the moves of the user so that we get required output
                Result(tictactoe,final,10,user,computer,2);          // checking that range of the final moves
            else
            {
                if(move2 == intermediate[3])                                    // respective further moves according to the moves of the user so that we get required output
                    Result(tictactoe,final,15,user,computer,2);          // checking that range of the final moves
                else
                {
                    if(move2 == intermediate[4])                                    // respective further moves according to the moves of the user so that we get required output
                        UserplaysFirst_Middle_Second_Corner(tictactoe,final,20,user,computer);          // checking that range of the final moves
                    else
                    {
                        if(move2 == intermediate[5])                                    // respective further moves according to the moves of the user so that we get required output
                            Result(tictactoe,final,25,user,computer,1);          // checking that range of the final moves
                        else
                        {
                            if(move2 == intermediate[6])                                    // respective further moves according to the moves of the user so that we get required output
                                Result(tictactoe,final,30,user,computer,2);          // checking that range of the final moves
                        }
                    }
                }
            }
        }
    }
    return;
}

void UserplaysFirst_Middle_Second_Edge(int tictactoe[],int optimized[],int user,int computer)         //function that focuses on the consecutive moves if user's first move is on middle cell
{
    tictactoe[optimized[0] - 1] = computer;         // as user has played the second move on edge after the first one and then the respective moves according to the edge move
    printTictactoe(tictactoe);
    int move3 = ValidMove(tictactoe);
    tictactoe[move3] = user;                        // user third move
    move3 = move3 + 1;
    if(move3 == optimized[1])                       // possible moves after this for computer to achieve the required output, all cells are optimized
    {
        tictactoe[optimized[2] - 1] = computer;     // moves depending upon the previous optimized move
        printTictactoe(tictactoe);
        int move4 = ValidMove(tictactoe);           // getting another move
        tictactoe[move4] = user;
        move4 = move4 + 1;
        if(move4 == optimized[3])                   // getting the result depeding on all the previous movees
        {
            tictactoe[optimized[4] - 1] = computer;
            Win(tictactoe);                                                         // reached the respective moves for winning
        }
        else
        {
            tictactoe[optimized[3] - 1] = computer;
            Win(tictactoe);                                                         // reached the respective moves for winning
        }
    }
    else
    {
        if(move3 == optimized[4])                   // hence accordingly all the moves have been optimised for output
        {
            tictactoe[optimized[6] - 1] = computer;
            printTictactoe(tictactoe);
            int move4 = ValidMove(tictactoe);
            tictactoe[move4] = user;
            move4 = move4 + 1;
            if(move4 == optimized[1])
            {
                tictactoe[optimized[9] - 1] = computer;
                Draw(tictactoe,user);                                                         // reached the respective moves for draw
            }
            else
            {
                tictactoe[optimized[1] - 1] = computer;
                Draw(tictactoe,user);                                                         // reached the respective moves for draw
            }
        }
        else
        {
            if(move3 == optimized[7])                   // hence accordingly all the moves have been optimised for output
            {
                tictactoe[optimized[8] - 1] = computer;
                printTictactoe(tictactoe);
                int move4 = ValidMove(tictactoe);
                tictactoe[move4] = user;
                move4 = move4 + 1;
                if(move4 == optimized[9])
                {
                    tictactoe[optimized[10] - 1] = computer;
                    Draw(tictactoe,user);                                                         // reached the respective moves for draw
                }
                else
                {
                    tictactoe[optimized[9] - 1] = computer;
                    Win(tictactoe);                                                         // reached the respective moves for winning
                }
            }
            else
            {
                if(move3 == optimized[9])                   // hence accordingly all the moves have been optimised for output
                {
                    tictactoe[optimized[11] - 1] = computer;
                    printTictactoe(tictactoe);
                    int move4 = ValidMove(tictactoe);
                    tictactoe[move4] = user;
                    move4 = move4 + 1;
                    if(move4 == optimized[4])
                    {
                        tictactoe[optimized[6] - 1] = computer;
                        Draw(tictactoe,user);                                                         // reached the respective moves for draw
                    }
                    else
                    {
                        tictactoe[optimized[4] - 1] = computer;
                        Draw(tictactoe,user);                                                         // reached the respective moves for draw
                    }
                }
                else                                      // hence accordingly all the moves have been optimised for output
                {
                    tictactoe[optimized[4] - 1] = computer;
                    printTictactoe(tictactoe);
                    int move4 = ValidMove(tictactoe);
                    tictactoe[move4] = user;
                    move4 = move4 + 1;
                    if(move4 == optimized[2])
                    {
                        tictactoe[optimized[1] - 1] = computer;
                        Draw(tictactoe,user);                                                         // reached the respective moves for draw
                    }
                    else
                    {
                        tictactoe[optimized[2] - 1] = computer;
                        Win(tictactoe);                                                         // reached the respective moves for winning
                    }
                }
            }
        }
    }
}

void UserplaysFirst_Corner(int tictactoe[], int final[], int intermediate[],int user,int computer)   //function that focuses on the consecutive moves if user's first move is on an corner
{
    int move3 = ValidMove(tictactoe);           // getting user's next valid move
    tictactoe[move3] = user;
    move3 = move3 + 1;                          // checking for the cell number
    if(move3 == intermediate[0])               // checking for the respective optimized moves to get the desired output
        Result(tictactoe,final,0,user,computer,2);
    else
    {
        if(move3 == intermediate[1])               // checking for the respective optimized moves to get the desired output
            Result(tictactoe,final,5,user,computer,2);
        else
        {
            if(move3 == intermediate[2])               // checking for the respective optimized moves to get the desired output
                Result(tictactoe,final,10,user,computer,2);
            else
            {
                if(move3 == intermediate[3])               // checking for the respective optimized moves to get the desired output
                    UserplaysFirst_Middle_Second_Corner(tictactoe,final,15,user,computer);
                else
                {
                    if(move3 == intermediate[4])               // checking for the respective optimized moves to get the desired output
                        Result(tictactoe,final,20,user,computer,2);
                    else
                    {
                        if(move3 == intermediate[5])               // checking for the respective optimized moves to get the desired output
                            UserplaysFirst_Middle_Second_Corner(tictactoe,final,25,user,computer);
                        else
                        {
                            if(move3 == intermediate[6])               // checking for the respective optimized moves to get the desired output
                                Result(tictactoe,final,30,user,computer,2);
                        }
                    }
                }
            }
        }
    }
    return;
}

void UserplaysFirst_Middle_Second_Corner(int tictactoe[], int optimized[], int start,int user,int computer)      //function that focuses on the consecutive moves if user's first move is on an middle cell or second move is on edge
{
    tictactoe[optimized[start]-1] = computer;           // inputting depending upon user's previous move and hence getting that optimized output
    printTictactoe(tictactoe);
    int nextmove = ValidMove(tictactoe);                // user's next valid move
    tictactoe[nextmove] = user;
    nextmove = nextmove + 1;
    if(nextmove == optimized[start + 1])                // finding which move played and hence iterating through the optimized moves to get the required output
    {
        tictactoe[optimized[start+2] - 1] = computer;
        printTictactoe(tictactoe);
        int nextmove1 = ValidMove(tictactoe);
        tictactoe[nextmove1] = user;
        nextmove1 = nextmove1 + 1;
        if(nextmove1 == optimized[start + 3])                // finding which move played and hence iterating through the optimized moves to get the required output
        {
            tictactoe[optimized[start + 4] - 1] = computer;
            Draw(tictactoe,user);                                                         // reached the respective moves for draw
        }
        else
        {
            if(nextmove1 == optimized[start + 4])                // finding which move played and hence iterating through the optimized moves to get the required output
            {
                tictactoe[optimized[start + 3] - 1] = computer;
                Draw(tictactoe,user);                                                         // reached the respective moves for draw
            }
            else
            {
                tictactoe[optimized[start+4] - 1] = computer;
                Draw(tictactoe,user);                                                         // reached the respective moves for draw
            }
        }
    }
    else
    {
        tictactoe[optimized[start+1]-1] = computer;
        Win(tictactoe);                                                         // reached the respective moves for winning
    }
    return;
}

void Computerplaysfirst(int tictactoe[])            //function to play the game when starting player is Computer
{
    int user = 2;
    int computer = 1;
    tictactoe[0] = 1;                               // best optimized move to win the game and hence placed by computer in first cell
    printTictactoe(tictactoe);
    int move = ValidMove(tictactoe);                // inputing user's first valid move
    tictactoe[move] = user;             // if user moves in the middle cell after out 1 cell then have to work in a particular manner to get the required output
    move = move + 1;
    switch ( move )                                // iterating all possible cases depending upon user's move and hence performing optimised moves for the required output
    {
        case 2:                                    // user moves in cell 2 (edge)
        {
            int final[] = {7,4,5,9,3};              // optimized moves
            Result(tictactoe,final,0,user,computer,1);       // function to get the final result depending upon all the previous moves
            break;
        }
        case 3:                                    // user moves in cell 3 (corner)
        {
            int final[] = {7,4,9,8,5};              // optimized moves
            Result(tictactoe,final,0,user,computer,1);       // function to get the final result depending upon all the previous moves
            break;
        }
        case 4:                                    // user moves in cell 4 (corner)
        {
            int final[] = {5,9,3,2,7};              // optimized moves
            Result(tictactoe,final,0,user,computer,1);       // function to get the final result depending upon all the previous moves
            break;
        }
        case 5:                                    // user moves in cell 5 (middle) and hence have to work out on a more optimised moves
        {
            tictactoe[8] = computer;                // hence putting in the down edge to get two possible rows to get the required win output
            printTictactoe(tictactoe);
            int move2 = ValidMove(tictactoe);       // getting user's next valid move
            tictactoe[move2] = user;
            move2 = move2 + 1;                      // getting the cell number
            switch ( move2 )                        // now depenging upon the latest user move we get to check which respective move would give us the required output
            {
                case 2:                             // move in the cell 2 (top edge)
                {
                    int final[] = {8,7,3,6,4};              // optimized moves
                    Result(tictactoe,final,0,user,computer,2);       // function to get the final result depending upon all the previous moves
                    break;
                }
                case 3:                             // move in the cell 3 (upper right corner)
                {
                    int final[] = {7,4,8};              // optimized moves
                    Result(tictactoe,final,0,user,computer,3);       // function to get the final result depending upon all the previous moves
                    break;
                }
                case 4:                             // move in the cell 4 (left edge)
                {
                    int final[] = {6,3,7,8,2};              // optimized moves
                    Result(tictactoe,final,0,user,computer,2);       // function to get the final result depending upon all the previous moves
                    break;
                }
                case 6:                             // move in the cell 6 (right edge)
                {
                    int final[] = {4,7,3,2,8};              // optimized moves
                    Result(tictactoe,final,0,user,computer,2);       // function to get the final result depending upon all the previous moves
                    break;
                }
                case 7:                             // move in the cell 7 (bottom left corner)
                {
                    int final[] = {3,2,6};              // optimized moves
                    Result(tictactoe,final,0,user,computer,3);       // function to get the final result depending upon all the previous moves
                    break;
                }
                case 8:                             // move in the cell 8 (bottom edge)
                {
                    int final[] = {2,3,7,4,6};              // optimized moves
                    Result(tictactoe,final,0,user,computer,2);       // function to get the final result depending upon all the previous moves
                    break;
                }
            }
            break;
        }
        case 6:                                    // user moves in cell 6 (edge)
        {
            int final[] = {7,4,5,9,3};              // optimized moves
            Result(tictactoe,final,0,user,computer,1);       // function to get the final result depending upon all the previous moves
            break;
        }
        case 7:                                    // user moves in cell 7 (corner)
        {
            int final[] = {9,5,3,2,6};              // optimized moves
            Result(tictactoe,final,0,user,computer,1);       // function to get the final result depending upon all the previous moves
            break;
        }
        case 8:                                    // user moves in cell 8 (edge)
        {
            int final[] = {5,9,7,4,3};              // optimized moves
            Result(tictactoe,final,0,user,computer,1);       // function to get the final result depending upon all the previous moves
            break;
        }
        case 9:                                    // user moves in cell 9 (corner)
        {
            int final[] = {7,4,3,5,2};              // optimized moves
            Result(tictactoe,final,0,user,computer,1);       // function to get the final result depending upon all the previous moves
            break;
        }
    }
    return;
}

void Result(int tictactoe[], int final[], int start,int user,int computer,int number)  // function which would work one particular hard coded manner when parent function has been called after some moves have been played and lead to a result
{
    switch ( number )
    {
        case 1:                                     // respectively checking for those optimized cases
        {
            tictactoe[final[start] - 1] = computer;
            printTictactoe(tictactoe);
            int move = ValidMove(tictactoe);                        // getting user's next valid move
            tictactoe[move] = user;
            move = move + 1;
            if(move == final[start + 1])                            // respectively checking for the user's move and hence give output depending upon computer's optimized move
            {
                tictactoe[final[start + 2] - 1] = computer;
                printTictactoe(tictactoe);
                int nextmove = ValidMove(tictactoe);                        // getting user's next valid move
                tictactoe[nextmove] = user;
                nextmove = nextmove + 1;
                if(nextmove == final[start + 3])                            // respectively checking for the user's move and hence give output depending upon computer's optimized move
                {
                    tictactoe[final[start + 4] - 1] = computer;
                    Win(tictactoe);                                                         // reached the respective moves for winning
                }
                else
                {
                    tictactoe[final[start + 3] - 1] = computer;
                    Win(tictactoe);                                                         // reached the respective moves for winning
                }
            }
            else
            {
                tictactoe[final[start+1] - 1] = computer;
                Win(tictactoe);                                                         // reached the respective moves for winning
            }
            break;
        }
        case 2:                                     // respectively checking for those optimized cases
        {
            tictactoe[final[start] - 1] = computer;
            printTictactoe(tictactoe);
            int move = ValidMove(tictactoe);
            tictactoe[move] = user;                        // getting user's next valid move
            move = move + 1;
            if(move == final[start + 1])                            // respectively checking for the user's move and hence give output depending upon computer's optimized move
            {
                tictactoe[final[start+2]-1] = computer;
                printTictactoe(tictactoe);
                int nextmove = ValidMove(tictactoe);
                tictactoe[nextmove] = user;
                nextmove = nextmove + 1;
                    if(nextmove == final[start + 3])                            // respectively checking for the user's move and hence give output depending upon computer's optimized move
                    {
                        tictactoe[final[start + 4] - 1] = computer;
                        Draw(tictactoe,user);                                                         // reached the respective moves for draw
                    }
                    else
                    {
                        tictactoe[final[start + 3] - 1] = computer;
                        Win(tictactoe);                                                         // reached the respective moves for winning
                    }
                }
            else
            {
                tictactoe[final[start + 1] - 1] = computer;
                Win(tictactoe);                                                         // reached the respective moves for winning
            }
            break;
        }
        case 3:                                     // respectively checking for those optimized cases
        {
            tictactoe[final[start] - 1] = computer;
            printTictactoe(tictactoe);
            int move = ValidMove(tictactoe);
            tictactoe[move] = user;                        // getting user's next valid move
            move = move + 1;
            if(move == final[start + 1])                            // respectively checking for the user's move and hence give output depending upon computer's optimized move
            {
                tictactoe[final[start+2]-1] = computer;
                Win(tictactoe);                                                         // reached the respective moves for winning
            }
            else
            {
                tictactoe[final[start + 1] - 1] = computer;
                Win(tictactoe);                                                         // reached the respective moves for winning
            }
            break;
        }
    }
    return;
}

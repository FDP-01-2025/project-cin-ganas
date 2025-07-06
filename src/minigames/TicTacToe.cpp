#include <iostream>
#include <windows.h>
using namespace std;

string board[3][3] = {{"1", "2", "3"},
                      {"4", "5", "6"},
                      {"7", "8", "9"}};

int row, column;
int turn = 0;

void DisplayBoard()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << board[i][j];
            if (j < 2)
            {
                cout << "|";
            }
        }
        if (i < 2)
        {
            cout << "\n-------\n";
        }
    }
}

string CurrentPlayer()
{
    if (turn % 2 == 0)
    {
        return "X";
    }
    else
    {
        return "O";
    }
}

void GetRowColumn(int value, int &row, int &column)
{
    row = (value - 1) / 3;
    column = (value - 1) % 3;

    if (board[row][column] != "X" && board[row][column] != "O")
    {
        board[row][column] = CurrentPlayer();
        turn++;
    }
    else
    {
        cout << "Cell already taken.\n";
    }
}

bool CheckWinner()
{
    // Rows
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
        {
            return true;
        }
    }

    // Columns
    for (int j = 0; j < 3; j++)
    {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j])
        {
            return true;
        }
    }

    // Diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
    {
        return true;
    }

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
    {
        return true;
    }

    return false;
}

void TicTacToe()
{
    int num;

    // TITLE
    cout << R"(
       __                                                                                                          
      /  |                                                                                                         
     _$$ |_     ______    ______    _______         ______   _______          ______   ______   __    __   ______  
    / $$   |   /      \  /      \  /       |       /      \ /       \        /      \ /      \ /  |  /  | /      \ 
    $$$$$$/   /$$$$$$  |/$$$$$$  |/$$$$$$$/       /$$$$$$  |$$$$$$$  |      /$$$$$$  |$$$$$$  |$$ |  $$ | $$$$$$  |
      $$ | __ $$ |  $$/ $$    $$ |$$      \       $$    $$ |$$ |  $$ |      $$ |  $$/ /    $$ |$$ |  $$ | /    $$ |
      $$ |/  |$$ |      $$$$$$$$/  $$$$$$  |      $$$$$$$$/ $$ |  $$ |      $$ |     /$$$$$$$ |$$ \__$$ |/$$$$$$$ |
      $$  $$/ $$ |      $$       |/     $$/       $$       |$$ |  $$ |      $$ |     $$    $$ |$$    $$ |$$    $$ |
       $$$$/  $$/        $$$$$$$/ $$$$$$$/         $$$$$$$/ $$/   $$/       $$/       $$$$$$$/  $$$$$$$ | $$$$$$$/ 
                                                                                               /  \__$$ |          
                                                                                               $$    $$/           
                                                                                                $$$$$$/            
)" << endl;

    while (true)
    {
        DisplayBoard();
        cout << "\n\nJugador #" << CurrentPlayer() << ", escribe un numero: ";
        cin >> num;

        if (num < 1 || num > 9)
        {
            cout << "Movimiento invalido. Prueba otro\n";
            continue;
        }

        GetRowColumn(num, row, column);

        if (CheckWinner())
        {
            DisplayBoard();
            cout << "\nJugador" << (turn % 2 == 0 ? "O" : "X") << " gana!\n";
            break;
        }

        if (turn == 9)
        {
            DisplayBoard();
            cout << "\nEmpate!\n";
            break;
        }
    }

    Sleep(5000);
}

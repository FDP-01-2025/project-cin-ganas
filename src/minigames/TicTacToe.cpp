#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
    string board[3][3] = {{"1", "2", "3"},
                          {"4", "5", "6"},
                          {"7", "8", "9"}};

    int row, column;
    int turn = 0;
    int num;

    // Display the centered title exactly as provided
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
        // Display the board
        for (int i = 0; i < 3; i++)
        {
            cout << " ";
            for (int j = 0; j < 3; j++)
            {
                cout << board[i][j];
                if (j < 2) cout << "|";
            }
            cout << "\n";
            if (i < 2) cout << "-------\n";
        }

        cout << "\n\nPlayer #" << (turn % 2 == 0 ? "X" : "O") << ", enter a number: ";
        cin >> num;

        // Validate move range
        if (num < 1 || num > 9)
        {
            cout << "Invalid move. Try again\n";
            continue;
        }

        // Calculate row and column
        row = (num - 1) / 3;
        column = (num - 1) % 3;

        // Check if the cell is empty
        if (board[row][column] == "X" || board[row][column] == "O")
        {
            cout << "Cell already taken.\n";
            continue;
        }
        else
        {
            board[row][column] = (turn % 2 == 0) ? "X" : "O";
            turn++;
        }

        // Check winner (rows)
        bool winner = false;
        for (int i = 0; i < 3; i++)
        {
            if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            {
                winner = true;
                break;
            }
        }

        // Check winner (columns)
        if (!winner)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[0][j] == board[1][j] && board[1][j] == board[2][j])
                {
                    winner = true;
                    break;
                }
            }
        }

        // Check winner (diagonals)
        if (!winner)
        {
            if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||
                (board[0][2] == board[1][1] && board[1][1] == board[2][0]))
            {
                winner = true;
            }
        }

        if (winner)
        {
            // Display final board
            for (int i = 0; i < 3; i++)
            {
                cout << " ";
                for (int j = 0; j < 3; j++)
                {
                    cout << board[i][j];
                    if (j < 2) cout << "|";
                }
                cout << "\n";
                if (i < 2) cout << "-------\n";
            }
            cout << "\nPlayer " << ((turn % 2 == 0) ? "O" : "X") << " wins!\n";
            break;
        }

        // Check for draw
        if (turn == 9)
        {
            // Display final board
            for (int i = 0; i < 3; i++)
            {
                cout << " ";
                for (int j = 0; j < 3; j++)
                {
                    cout << board[i][j];
                    if (j < 2) cout << "|";
                }
                cout << "\n";
                if (i < 2) cout << "-------\n";
            }
            cout << "\nDraw!\n";
            break;
        }
    }

    Sleep(5000);
    return 0;
}

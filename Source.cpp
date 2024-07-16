#include <iostream>
using namespace std;

// Define constants for board capacity and number of players
#define  Capacity 100
#define Number_of_Players 2

// Function to initialize the game board and player details
void Initialization(char Board[Capacity][Capacity], int& Dimensions, char Player_Name[Number_of_Players][30], char Player_Symbol[], int& Turn, int& Win_Count)
{
    // Input game dimensions and win count
    cout << "Enter Dimesions : ";
    cin >> Dimensions;
    cout << "Enter Win Count : ";
    cin >> Win_Count;

    // Input player names and symbols
    for (int pi = 0; pi < Number_of_Players; pi++)
    {
        cout << "Player " << pi + 1 << " : ";
        cin >> Player_Name[pi];
        cout << "Player " << pi + 1 << " 's Symbol : ";
        cin >> Player_Symbol[pi];
    }

    // Initialize the board with empty cells
    for (int ri = 0; ri < Dimensions; ri++)
    {
        for (int ci = 0; ci < Dimensions; ci++)
        {
            Board[ri][ci] = '-';
        }
    }
    // Randomly decide which player starts first
    Turn = rand() % Number_of_Players;
}

// Function to display the game board
void DisplayBoard(char Board[Capacity][Capacity], int Dimensions)
{
    system("cls"); // Clear the console screen
    for (int ri = 0; ri < Dimensions; ri++)
    {
        for (int ci = 0; ci < Dimensions; ci++)
        {
            cout << Board[ri][ci] << "\t";
        }
        cout << endl;
    }
}

// Function to display the current player's turn message
void PlayerMessage(char Player_Name[], char Player_Symbol)
{
    cout << Player_Name << "'s (" << Player_Symbol << ") Turn : \n";
}

// Function to input the player's move
void PlayerTurn(int& ri, int& ci)
{
    cout << "Enter Row and Column Number : ";
    cin >> ri >> ci;
    ri = ri - 1; // Convert to 0-based index
    ci = ci - 1; // Convert to 0-based index
}

// Function to check if the move is valid
bool IsValidMove(char Board[Capacity][Capacity], int Dimensions, int ri, int ci)
{
    return(ri >= 0 && ri < Dimensions && ci >= 0 && ci < Dimensions && Board[ri][ci] == '-');
}

// Function to update the board with the player's move
void UpdateBoard(char Board[Capacity][Capacity], int ri, int ci, char Player_Symbol)
{
    Board[ri][ci] = Player_Symbol;
}

// Function to change the turn to the next player
void TurnChange(int& Turn)
{
    Turn = (Turn + 1) % Number_of_Players;
}

// Function to check horizontal win condition
bool Is_Horizontal_Win(char Board[Capacity][Capacity], int Dimension, int ri, int ci, int win_count, char player_sym)
{
    if (ci + win_count - 1 >= Dimension)
    {
        return false;
    }
    for (int i = 0; i < win_count; i++)
    {
        if (Board[ri][ci + i] != player_sym)
        {
            return false;
        }
    }
    return true;
}

// Function to check vertical win condition
bool Is_Vertical_Win(char Board[Capacity][Capacity], int Dimension, int ri, int ci, int win_count, char player_sym)
{
    if (ri + win_count - 1 >= Dimension)
    {
        return false;
    }
    for (int i = 0; i < win_count; i++)
    {
        if (Board[ri + i][ci] != player_sym)
        {
            return false;
        }
    }
    return true;
}

// Function to check diagonal win condition (top-left to bottom-right)
bool Is_Diagnol_Win_1(char Board[Capacity][Capacity], int Dimension, int ri, int ci, int win_count, char player_sym)
{
    if (ci + win_count - 1 >= Dimension || ri + win_count - 1 >= Dimension)
    {
        return false;
    }
    for (int i = 0; i < win_count; i++)
    {
        if (Board[ri + i][ci + i] != player_sym)
        {
            return false;
        }
    }
    return true;
}

// Function to check diagonal win condition (bottom-left to top-right)
bool Is_Diagnol_Win_2(char Board[Capacity][Capacity], int Dimension, int ri, int ci, int win_count, char player_sym)
{
    if ((ri + win_count - 1 >= Dimension) || (ci - (win_count - 1) < 0))
    {
        return false;
    }
    for (int i = 0; i < win_count; i++)
    {
        if (Board[ri + i][ci - i] != player_sym)
        {
            return false;
        }
    }
    return true;
}

// Function to check if a player has won
bool IsWin(char Board[Capacity][Capacity], int Dimensions, int Win_Count, char Player_Symbol)
{
    for (int ri = 0; ri < Dimensions; ri++)
    {
        for (int ci = 0; ci < Dimensions; ci++)
        {
            if (Is_Horizontal_Win(Board, Dimensions, ri, ci, Win_Count, Player_Symbol) ||
                Is_Vertical_Win(Board, Dimensions, ri, ci, Win_Count, Player_Symbol) ||
                Is_Diagnol_Win_1(Board, Dimensions, ri, ci, Win_Count, Player_Symbol) ||
                Is_Diagnol_Win_2(Board, Dimensions, ri, ci, Win_Count, Player_Symbol))
            {
                return true;
            }
        }
    }
    return false;
}

// Function to check if the game is a draw
bool IsDraw(char Board[Capacity][Capacity], int Dimensions)
{
    for (int ri = 0; ri < Dimensions; ri++)
    {
        for (int ci = 0; ci < Dimensions; ci++)
        {
            if (Board[ri][ci] == '-')
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    char Board[Capacity][Capacity];
    int Dimensions;
    char Player_Name[Number_of_Players][30];
    char Player_Symbol[Number_of_Players], PlayAgain;
    int Turn, ri = 0, ci = 0;
    int Win_Count, Winner = -1;
    int WinnerCounts[Number_of_Players] = { 0 };
    bool Game_Over = false;

    // Main game loop
    do
    {
        Initialization(Board, Dimensions, Player_Name, Player_Symbol, Turn, Win_Count);

        do
        {
            DisplayBoard(Board, Dimensions);

            do
            {
                PlayerMessage(Player_Name[Turn], Player_Symbol[Turn]);
                PlayerTurn(ri, ci);
                if (!IsValidMove(Board, Dimensions, ri, ci))
                {
                    cout << "InValid Move \n";
                }
            } while (!IsValidMove(Board, Dimensions, ri, ci));

            UpdateBoard(Board, ri, ci, Player_Symbol[Turn]);

            Game_Over = IsWin(Board, Dimensions, Win_Count, Player_Symbol[Turn]);

            if (Game_Over)
            {
                Winner = Turn;
            }

            if (!Game_Over)
            {
                Game_Over = IsDraw(Board, Dimensions);
            }

            if (!Game_Over)
            {
                TurnChange(Turn);
            }

        } while (!Game_Over);

        if (Winner == -1)
        {
            cout << "Draw Game.. ";
        }
        else
        {
            cout << Player_Name[Winner] << " has won the Match \n";
            WinnerCounts[Winner]++;
        }

        cout << "\nDo you want to play again \n"
            << "Press Y for yes and N for No \n";
        cin >> PlayAgain;
        system("cls"); // Clear the console screen
    } while (PlayAgain == 'Y' || PlayAgain == 'y');

    // Display total matches played and the number of matches won by each player
    int total_match = 0;
    for (int i = 0; i < Number_of_Players; i++)
    {
        total_match = total_match + WinnerCounts[i];
    }
    cout << "Total Matches Played : " << total_match << endl;
    for (int i = 0; i < Number_of_Players; i++)
    {
        cout << Player_Name[i] << " has won the " << WinnerCounts[i] << " matches.. \n";
    }
}

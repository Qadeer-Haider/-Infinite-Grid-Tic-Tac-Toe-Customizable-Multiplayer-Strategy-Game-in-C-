# Infinite-Grid-Tic-Tac-Toe-Customizable-Multiplayer-Strategy-Game-in-C++

This project implements a two-player Tic-Tac-Toe game in C++ using a dynamic game board and customizable game settings. Players can set the dimensions of the board and the win count required to win the game.

## Project Structure

1. **Initialization**
    - Initialize game settings (board dimensions, win count, player names, and symbols)
    - Initialize the game board with empty cells
    - Randomly decide which player starts first

2. **Game Loop**
    - Display the game board
    - Handle player's turn
    - Validate moves
    - Update the game board
    - Check for win or draw conditions
    - Change the turn to the next player
    - Repeat until the game is over

3. **Win and Draw Conditions**
    - Check horizontal, vertical, and diagonal win conditions
    - Check for draw condition

4. **Play Again**
    - Prompt the players to play again
    - Display the total matches played and the number of matches won by each player

## Code Overview

### Initialization

The `Initialization` function sets up the game by taking inputs for the board dimensions, win count, player names, and symbols. It also initializes the board with empty cells and randomly decides which player starts first.

### Displaying the Board

The `DisplayBoard` function clears the console screen and displays the current state of the game board.

### Handling Player Turns

The `PlayerTurn` function takes input for the row and column numbers from the player and converts them to 0-based indices.

### Validating Moves

The `IsValidMove` function checks if the player's move is within the board dimensions and if the selected cell is empty.

### Updating the Board

The `UpdateBoard` function updates the game board with the player's symbol at the selected cell.

### Changing Turns

The `TurnChange` function switches the turn to the next player.

### Win and Draw Conditions

The `IsWin` function checks for horizontal, vertical, and diagonal win conditions. The `IsDraw` function checks if the game is a draw by verifying if all cells are filled.

### Main Game Loop

The main game loop initializes the game, handles player turns, checks for win or draw conditions, and prompts the players to play again.



## Example Output

```
Enter Dimensions : 3
Enter Win Count : 3
Player 1 : Alice
Player 1 's Symbol : X
Player 2 : Bob
Player 2 's Symbol : O

X	-	X
O	X	O
O	X	O

Alice (X) has won the Match!

Do you want to play again?
Press Y for yes and N for No
```

## References
- [Tic-Tac-Toe](https://en.wikipedia.org/wiki/Tic-tac-toe)


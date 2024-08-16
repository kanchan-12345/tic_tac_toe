#include <stdio.h>

char board[3][3];         // 3x3 board for the game
char currentPlayer = 'X'; // X always starts the game

// Function to initialize the game board
void initializeBoard()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = ' ';
        }
    }
}
// Function to print the game board
void printBoard()
{
    printf("\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf(" %c ", board[i][j]);
            if (j < 2)
                printf("|");
        }
        printf("\n");
        if (i < 2)
            printf("---|---|---\n");
    }
    printf("\n");
}

// Function to check if the game board is full
int isBoardFull()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == ' ')
            {
                return 0; // board is not full
            }
        }
    }
    return 1; // board is full
}

// Function to check if there's a winner
int checkWin()
{
    // Check rows
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer)
        {
            return 1;
        }
    }
    // Check columns
    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)
        {
            return 1;
        }
    }
    // Check diagonals
    if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer)
    {
        return 1;
    }
    if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)
    {
        return 1;
    }
    return 0;
}

// Function to switch the current player
void switchPlayer()
{
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

// Function to handle player input and make a move
void makeMove()
{
    int row, col;
    while (1)
    {
        printf("Player %c, enter your move (row and column): ", currentPlayer);
        scanf("%d %d", &row, &col);
        if (row >= 1 && row <= 3 && col >= 1 && col <= 3 && board[row - 1][col - 1] == ' ')
        {
            board[row - 1][col - 1] = currentPlayer;
            break;
        }
        else
        {
            printf("Invalid move, try again.\n");
        }
    }
}

// Main function
int main()
{
    initializeBoard();
    printBoard();

    while (1)
    {
        makeMove();
        printBoard();
        if (checkWin())
        {
            printf("Player %c wins!\n", currentPlayer);
            break;
        }
        if (isBoardFull())
        {
            printf("It's a draw!\n");
            break;
        }
        switchPlayer();
    }

    return 0;
}

#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

struct Players
{
	string playerName;
	char playerChar;
};

// Dimensions for the player grid
#define WIDTH 7
#define HEIGHT 6

// Prints the title
void showTitle() {
	cout << "[-------------------------------------]" << endl;
	cout << "[          CONSOLE CONNECT 4          ]" << endl;
	cout << "[-------------------------------------] " << endl;
	cout << "\n";
	cout << "\n";
}

// Asks the player for their input as long as the number is within range
int promptPlayer(char board[][WIDTH], Players activePlayer)
{
	int playerInput;

	do
	{
		cout <<  "Hey, " <<activePlayer.playerName << ", " << "Please enter the column youd like to place your token 1 - 7: ";
		cin >> playerInput;

		while (board[1][playerInput] == 'X' || board[1][playerInput] == 'O')
		{
			cout << "That row is full, please enter a new row: ";
			cin >> playerInput;
					
		}

	} while (playerInput < 1 || playerInput > WIDTH);

	return playerInput;
}

// Adds the player token to the array at thr chosen location
void updateGrid(char board[][WIDTH], Players activePlayer, int playerInput)
{
	int length, turn;
	length = 6;
	turn = 0;

	do
	{
		if (board[length][playerInput] != 'X' && board[length][playerInput] != 'O')
		{
			board[length][playerInput] = activePlayer.playerChar;
			turn = 1;
		}
		else
			--length;
	} while (turn != 1);


}

// Prints the array in a 7x6 grid, empty indicies are printed as '.'
void displayGrid(char board[][WIDTH])
{
	int rows = 6, columns = 7;

	cout << " |1| |2| |3| |4| |5| |6| |7| \n";
	cout << " [                         ]\n";
	cout << "\n";
	for (int h = 1; h <= rows; h++)
	{
		for (int w = 1; w <= columns; w++)
		{
			if (board[h][w] != 'X' && board[h][w] != 'O')
				board[h][w] = '.';

			cout << " |" << board[h][w] << "|";

		}

		cout << endl;
	}

	cout << " [_________________________]\n";
	cout << "\n";
}

// Checks if there are four tokens vertically, horizontally and diagonally
int validatePosition(char board[][WIDTH], Players activePlayer)
{
	char currentChar;
	int win;

	currentChar = activePlayer.playerChar;
	win = 0;

	for (int h = 6; h >= 1; --h) 
	{
		for (int w = 7; w >= 1; --w) {

			//Vertically
			if (board[h][w] == currentChar &&
				board[h - 1][w] == currentChar &&
				board[h - 2][w] == currentChar &&
				board[h - 3][w] == currentChar)
			{
				win = 1;
			}

			//Horizontally left
			if (board[h][w] == currentChar &&
				board[h][w - 1] == currentChar &&
				board[h][w - 2] == currentChar &&
				board[h][w - 3] == currentChar)
			{
				win = 1;
			}

			//Horizontally right
			if (board[h][w] == currentChar &&
				board[h][w + 1] == currentChar &&
				board[h][w + 2] == currentChar &&
				board[h][w + 3] == currentChar)
			{
				win = 1;
			}

			//Diagonally left to right
			if (board[h][w] == currentChar &&
				board[h - 1][w - 1] == currentChar &&
				board[h - 2][w - 2] == currentChar &&
				board[h - 3][w - 3] == currentChar)
			{
				win = 1;
			}

			//Diagonally right to left
			if (board[h][w] == currentChar &&
				board[h - 1][w + 1] == currentChar &&
				board[h - 2][w + 2] == currentChar &&
				board[h - 3][w + 3] == currentChar)
			{
				win = 1;
			}
		}
	}

	return win;
}

// Increments a counter which checks if the top of a row is full
int isBoardFull(char board[][WIDTH])
{
	int full;
	full = 0;
	for (int i = 1; i <= 7; ++i)
	{
		if (board[1][i] != '.')
			++full;
	}

	return full;
}

// Print to win!
void YouWin(Players activePlayer)
{
	cout << endl << activePlayer.playerName << " Connected Four, You Win!" << endl;
}

// Restarts the game with an empty grid
int restart(char board[][WIDTH])
{
	char restart;

	cout << "Would you like to restart? Y / N: ";
	cin >> restart;
	
	switch (int(restart))
	{
	case (89):
	case (121):
		/*for (int h = 1; h <= 6; h++)
		{
			for (int w = 1; w <= 7; w++) {
				board[h][w] = '.';
			}
		}*/
		cout << "yes" << endl;
			break;
	case(78):
	case(110):
		cout << "Goodbye!" << endl;
	default:
		break;
	}
	
	return restart;
}

int main()
{
	Players P1, P2;
	char board[HEIGHT][WIDTH];
	int playerInput, win, full, again;

	showTitle();
	displayGrid(board);
	cout << "Player 1, please enter your name: ";
	cin >> P1.playerName;
	cout << endl;
	P1.playerChar = 'X';
	cout << "Player 2, please enter your name: ";
	cin >> P2.playerName;
	cout << endl;
	P2.playerChar = 'O';

	full = 0;
	win = 0;
	again = 0;
	do
	{
		playerInput = promptPlayer(board, P1);
		updateGrid(board, P1, playerInput);
		system("cls");
		showTitle();
		cout << ">>>>>> " << P2.playerName << "'s Turn " << "<<<<<<<<" << "\n \n";
		displayGrid(board);
		win = validatePosition(board, P1);
		if (win == 1)
		{
			YouWin(P1);
			again = restart(board);
			if (again >= 2)
			{
				break;
				system("exit");
			}
		}

		playerInput = promptPlayer(board, P2);
		updateGrid(board, P2, playerInput);
		system("cls");
		showTitle();
		cout << ">>>>>> " << P1.playerName << "'s Turn " << "<<<<<<<<" << "\n \n";
		displayGrid(board);
		win = validatePosition(board, P2);
		if (win == 1)
		{
			YouWin(P2);
			again = restart(board);
			if (again >= 2)
			{
				break;
				system("exit");
			}
		}

		full = isBoardFull(board);
		if (full == WIDTH)
		{
			cout << "The board is full, it is a draw!" << endl;
			again = restart(board);
		}

	} while (again != 2);



	return 0;
}

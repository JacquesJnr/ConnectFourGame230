#include <iostream>
#include <string>
#include <sstream>
#include <ctype.h>
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

//Ask the player if they'd like to play normal connect 4 or secondary objective connect 4
int gameMode(string name1, string name2, int playerInput) {

	int option_select = NULL;

	cout << "Welcome " << name1 + " and " << name2 << ".\n\n";

	cout << "  CHOOSE AN OPTION: \n";
	
	do {
		cout << "|---------------------------------------------------------------------------------------|" << endl;
		cout << "| 1: Play Normal Connect 4!                                                     |\n";
		cout << "|---------------------------------------------------------------------------------------|" << endl;
		cout << "| 2: Play Connect 4 with the option to remove pieces at the bottom of the board!|\n";
		cout << "|---------------------------------------------------------------------------------------|" << endl;
		cin >> playerInput;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}

		if (playerInput == 1) {
			cout << "THATS A 1\n";
			option_select = 1;
		}
		else if (playerInput == 2) {
			cout << "THATS A 2\n";
			option_select = 2;
		}
		else
		{
			cout << "That was an invalid answer... Input 1 or 2\n\n";
			option_select == NULL;
		}

	} while (option_select == NULL);


	system("cls");
	showTitle();
	return option_select;
}

// Asks the player for their input as long as the number is within range
int promptPlayer(char board[][WIDTH], Players activePlayer)
{
	int playerInput;


	do
	{
		cout <<  "Hey, " <<activePlayer.playerName << ", " << "Please enter the column youd like to place your token 1 - 7: ";
		cin >> playerInput;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}

		if (playerInput < 1 || playerInput > WIDTH) {
			cout << "That is an invalid column... \n";
		}

		while (board[1][playerInput] == 'X' || board[1][playerInput] == 'O')
		{
			cout << "That row is full, please enter a new row: ";
			cin >> playerInput;						
		}

	} while (playerInput < 1 || playerInput > WIDTH);
	cout << "\n";

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
	for (int i = 1; i <= WIDTH; ++i)
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
	int my_int = NULL;

	do {
		cout << "Would you like to restart? Y / N: ";
		cin >> restart;

		cin.ignore(restart, '\n');

		if (isalpha(restart)) {

			if (restart == 89 || restart == 121) {
				my_int = 1;
			}
			else if (restart == 78 || restart == 110) {
				my_int = 2;
			}
			else
			{
				my_int = NULL;
				cout << "That wasn't Y or N, try again... \n";
			}
		}
		else
		{
			cout << "I'm sorry, that's a number not a letter, please input Y or N: \n";
		}

	} while (my_int == NULL);

	system("cls");
	showTitle();
	return my_int;
}

int main()
{
	Players P1, P2;
	char board[HEIGHT][WIDTH];
	int mode, playerInput, win, full, again;

	showTitle();
	cout << "Player 1, please enter your name: ";
	cin >> P1.playerName;
	cout << endl;
	P1.playerChar = 'X';
	cout << "Player 2, please enter your name: ";
	cin >> P2.playerName;
	cout << endl;
	P2.playerChar = 'O';

	playerInput = 0;

	gameMode(P1.playerName, P2.playerName, playerInput);
	displayGrid(board);

	full = 0;
	win = 0;
	again = 0;
	do
	{
		//Player 1
		playerInput = promptPlayer(board, P1);
		updateGrid(board, P1, playerInput);
		system("cls");
		showTitle();
		cout << ">>>>>> " << P2.playerName << "'s Turn " << "<<<<<<<<" << "\n \n";
		displayGrid(board);
		win = validatePosition(board, P1);
		if (win == 1)
		{
			//Player 1 win
			YouWin(P1);
			again = restart(board);
			if (again >= 2)
			{
				break;
				system("exit");
			}
		}
		
		//Player 2
		playerInput = promptPlayer(board, P2);
		updateGrid(board, P2, playerInput);
		system("cls");
		showTitle();
		cout << ">>>>>> " << P1.playerName << "'s Turn " << "<<<<<<<<" << "\n \n";
		displayGrid(board);
		win = validatePosition(board, P2);
		if (win == 1)
		{
			//Player 2 win
			YouWin(P2);
			again = restart(board);			
			if (again >= 2)
			{
				break;
				system("exit");
			}
		}

		// Draw
		full = isBoardFull(board);
		if (full == WIDTH)
		{
			cout << "The board is full, it is a draw!" << endl;
			again = restart(board);
		}

	} while (again != 2);

	return 0;
}

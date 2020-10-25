#include <iostream>
using namespace std;

struct Players
{
	string playerName;
	char playerID;
};

#define WIDTH 7
#define HEIGHT 6
void showTitle();
int recieveInput(char board[][WIDTH], Players activePlayer);
void validateInput(char board[][WIDTH], Players activePlayer, int dropChoice);
void displayGrid(char board[][WIDTH]);
int validatePosition(char board[][WIDTH], Players activePlayer);
int isBoardFull(char board[][WIDTH]);
void YouWin(Players activePlayer);
int restart(char board[][WIDTH]);

int main()
{
	Players P1, P2;
	char board[HEIGHT][WIDTH];
	int dropChoice, win, full, again;

	showTitle();
	cout << "Player One please enter your name: ";
	cin >> P1.playerName;
	cout << endl;
	P1.playerID = 'X';
	cout << "Player Two please enter your name: ";
	cin >> P2.playerName;
	cout << endl;
	P2.playerID = 'O';

	full = 0;
	win = 0;
	again = 0;
	displayGrid(board);
	do
	{
		dropChoice = recieveInput(board, P1);
		validateInput(board, P1, dropChoice);
		system("cls");
		showTitle();
		cout << ">>>>>> " << P2.playerName << "'s Turn " << "<<<<<<<<" << "\n \n";
		displayGrid(board);
		win = validatePosition(board, P1);
		if (win == 1)
		{
			YouWin(P1);
			again = restart(board);
			if (again == 2)
			{
				break;
			}
		}

		dropChoice = recieveInput(board, P2);
		validateInput(board, P2, dropChoice);
		system("cls");
		showTitle();
		cout << ">>>>>> " << P2.playerName << "'s Turn " << "<<<<<<<<" << "\n \n";
		cout << "\n";
		displayGrid(board);
		win = validatePosition(board, P2);
		if (win == 1)
		{
			YouWin(P2);
			again = restart(board);
			if (again == 2)
			{
				break;
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

void showTitle() {
	cout << "[-------------------------------------]" << endl;
	cout << "[          CONSOLE CONNECT 4          ]" << endl;
	cout << "[-------------------------------------] " << endl;
	cout << "\n";
	cout << "\n";
}

int recieveInput(char board[][WIDTH], Players activePlayer)
{
	int dropChoice;
	do
	{

		cout << activePlayer.playerName << ", " << "Please enter a number between 1 and 7: ";
		cin >> dropChoice;

		while (board[1][dropChoice] == 'X' || board[1][dropChoice] == 'O')
		{
			cout << "That row is full, please enter a new row: ";
			cin >> dropChoice;
			
			if (cin.fail()) {
				cout << "///////////\n";
				cout << "Not an int!\n";
			}
		}

	} while (dropChoice < 1 || dropChoice > WIDTH);

	return dropChoice;
}

void validateInput(char board[][WIDTH], Players activePlayer, int dropChoice)
{
	int length, turn;
	length = 6;
	turn = 0;

	do
	{
		if (board[length][dropChoice] != 'X' && board[length][dropChoice] != 'O')
		{
			board[length][dropChoice] = activePlayer.playerID;
			turn = 1;
		}
		else
			--length;
	} while (turn != 1);


}

void displayGrid(char board[][WIDTH])
{
	int rows = 6, columns = 7, i, ix;

	cout << " |1| |2| |3| |4| |5| |6| |7| \n";
	cout << " [                         ]\n";
	cout << "\n";
	for (i = 1; i <= rows; i++)
	{
		for (ix = 1; ix <= columns; ix++)
		{
			if (board[i][ix] != 'X' && board[i][ix] != 'O')
				board[i][ix] = '*';

			cout << " |"<< board[i][ix] << "|";

		}

		cout << endl;
	}

	cout << " [_________________________]\n";
	cout << "\n";
}

int validatePosition(char board[][WIDTH], Players activePlayer)
{
	char XO;
	int win;

	XO = activePlayer.playerID;
	win = 0;

	for (int i = 8; i >= 1; --i)
	{

		for (int ix = 9; ix >= 1; --ix)
		{

			if (board[i][ix] == XO &&
				board[i - 1][ix - 1] == XO &&
				board[i - 2][ix - 2] == XO &&
				board[i - 3][ix - 3] == XO)
			{
				win = 1;
			}


			if (board[i][ix] == XO &&
				board[i][ix - 1] == XO &&
				board[i][ix - 2] == XO &&
				board[i][ix - 3] == XO)
			{
				win = 1;
			}

			if (board[i][ix] == XO &&
				board[i - 1][ix] == XO &&
				board[i - 2][ix] == XO &&
				board[i - 3][ix] == XO)
			{
				win = 1;
			}

			if (board[i][ix] == XO &&
				board[i - 1][ix + 1] == XO &&
				board[i - 2][ix + 2] == XO &&
				board[i - 3][ix + 3] == XO)
			{
				win = 1;
			}

			if (board[i][ix] == XO &&
				board[i][ix + 1] == XO &&
				board[i][ix + 2] == XO &&
				board[i][ix + 3] == XO)
			{
				win = 1;
			}
		}

	}

	return win;
}

int isBoardFull(char board[][WIDTH])
{
	int full;
	full = 0;
	for (int i = 1; i <= 7; ++i)
	{
		if (board[1][i] != '*')
			++full;
	}

	return full;
}

void YouWin(Players activePlayer)
{
	cout << endl << activePlayer.playerName << " Connected Four, You Win!" << endl;
}

int restart(char board[][WIDTH])
{
	int restart;

	cout << "Would you like to restart? Yes(1) No(2): ";
	cin >> restart;
	if (restart == 1)
	{
		for (int i = 1; i <= 6; i++)
		{
			for (int ix = 1; ix <= 7; ix++)
			{
				board[i][ix] = '*';
			}
		}
	}
	else
		cout << "Goodbye!" << endl;
	return restart;
}
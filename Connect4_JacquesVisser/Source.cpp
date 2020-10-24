#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

struct playerInfo
{
	char playerName[81];
	char playerChar;
};

const int WIDTH = 7;
const int HEIGHT = 6;
int gridArray[HEIGHT][WIDTH] = {};
int playerNumber;
bool gridUpdate = false;
bool gameOver = false;
int currentHeight = 6;

//Displays the 6x7 Grid 
void displayGrid(char board[][7]) {
	cout << "\n";
	cout << "\n";
	int row_letter = 64; //In ASCII 64 represents "@", the character before A,B,C etc.

	cout << " |1| |2| |3| |4| |5| |6| |7| \n";
	cout << " [                         ]\n";

	for (int h = 0; h < HEIGHT; h++) {
		for (int w = 0; w < WIDTH; w++) {

			if (board[h][w] != 'X' && board[h][w] != 'O')
				board[h][w] = '.';

			if (h > 0) {
				if (w == 0) {
					cout << endl;

				}
			}

			cout <<" |" << board[h][w] << "|";
		}
	}

	cout << "\n";
	cout << " [_________________________]\n";
	cout << "\n";
	cout << "Empty = .\n";
	cout << "Player 1 = X\n";
	cout << "Player 2 = O\n";
	cout << "\n";
	cout << "\n";
}

//Takes the input of the current player
int promptPlayer(char board[][7], playerInfo activePlayer) {

	int dropChoice;
	do
	{
		cout << activePlayer.playerName << "'s Turn ";
		cout << "Please enter a number between 1 and 7: ";
		cin >> dropChoice;

		while (board[1][dropChoice] == 'X' || board[1][dropChoice] == 'O')
		{
			cout << "That row is full, please enter a new row: ";
			cin >> dropChoice;
		}

	} while (dropChoice < 1 || dropChoice > 7);

	cout << "\n";
	cout << "You entered column: " << dropChoice;
	return dropChoice;
}

// Checks if the player wants to continue with the row they've entered
char validateInput(char yesNo) {

	int optionLetter = (int)yesNo;

	switch (optionLetter)
	{
	case(89):
	case (121):
	{
		cout << "Updating Grid\n";
		system("cls");
		gridUpdate = true;
		cout << "\n";
		break;
	}
	case(78):
	case(110):
	{
		cout << "Starting over\n";
		gridUpdate = false;
		system("cls");
		break;
	}
	default:
		gridUpdate = false;
		cout << "Invalid input, enter Y or y, N or n";
		break;
	}

	return yesNo;
}

void validatePosition(char board[][7], playerInfo activePlayer, int tokenPosition) {
	
	int length, turn;
	length = 6;
	turn = 0;

	do
	{
		if (board[length][tokenPosition - 1] != 'X' && board[length][tokenPosition -1] != 'O')
		{
			board[length][tokenPosition -1] = activePlayer.playerChar;
			turn = 1;
		}
		else
			--length;
	} while (turn != 1);

}

// Inserts the players token into the array
void updateGrid(int columnNumber) {
	cout << "GRID UPDATED...\n";
	cout << "\n";

	int h;
	int w;
	//string my_array[WIDTH][HEIGHT];

	for (h = 0; h < HEIGHT; h++) {

		if (gridArray[0][0] == NULL) {
			currentHeight--;
			cout << currentHeight << endl;
			h = currentHeight;
		}
		for (w = 0; w < WIDTH; w++) {

			gridArray[h][columnNumber - 1] = 1;
		}
	}

	cout << "Height: " << currentHeight << endl;
	cout << "Column: " << columnNumber << endl;
}

int winCheck(char board[][7], playerInfo activePlayer) {
	char activeChar;
	int win;

	activeChar = activePlayer.playerChar;
	win = 0;

	for (int i = 8; i >= 1; --i)
	{

		for (int ix = 9; ix >= 1; --ix)
		{

			if (board[i][ix] == activeChar &&
				board[i - 1][ix - 1] == activeChar &&
				board[i - 2][ix - 2] == activeChar &&
				board[i - 3][ix - 3] == activeChar)
			{
				win = 1;
			}


			if (board[i][ix] == activeChar &&
				board[i][ix - 1] == activeChar &&
				board[i][ix - 2] == activeChar &&
				board[i][ix - 3] == activeChar)
			{
				win = 1;
			}

			if (board[i][ix] == activeChar &&
				board[i - 1][ix] == activeChar &&
				board[i - 2][ix] == activeChar &&
				board[i - 3][ix] == activeChar)
			{
				win = 1;
			}

			if (board[i][ix] == activeChar &&
				board[i - 1][ix + 1] == activeChar &&
				board[i - 2][ix + 2] == activeChar &&
				board[i - 3][ix + 3] == activeChar)
			{
				win = 1;
			}

			if (board[i][ix] == activeChar &&
				board[i][ix + 1] == activeChar &&
				board[i][ix + 2] == activeChar &&
				board[i][ix + 3] == activeChar)
			{
				win = 1;
			}
		}

	}

	return win;
}

void playerWin(playerInfo activePlayer) {
	cout << endl << activePlayer.playerName << " Connected Four, You Win!" << endl;
}


//Allows me to color the text
void colorText() {
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int col = 12;

	// color your text in Windows console mode
	// colors are 0=black 1=blue 2=green and so on to 15=white  
	// colorattribute = foreground + background * 16
	// to get red text on yellow use 4 + 14*16 = 228
	// light red on yellow would be 12 + 14*16 = 236

	FlushConsoleInputBuffer(hConsole);
	SetConsoleTextAttribute(hConsole, col);

	cout << "Color Text\n";
	SetConsoleTextAttribute(hConsole, 10);
}


// Does what it says on the tin
void showTitle() {
	cout << "[-------------------------------------]" << endl;
	cout << "[          CONSOLE CONNECT 4          ]" << endl;
	cout << "[-------------------------------------] " << endl;
	cout << "\n";
	cout << "\n";
}


int main()
{
	char board[HEIGHT][WIDTH];
	int tokenPos, winCondition, drawCondition,  restart;
	char cont;
	playerInfo P1, P2;

	winCondition = 0;
	drawCondition = 0;
	restart = 0;

	showTitle();
	cout << "Player 1, Input your name please: ";
	cin >> P1.playerName;
	P1.playerChar = 'X';

	cout << "Player 2, Input your name please: ";
	cin >> P2.playerName;
	P2.playerChar = 'O';

	displayGrid(board);
	
	do
	{
		tokenPos = promptPlayer(board, P1);
		validatePosition(board, P1, tokenPos);
		system("cls");
		showTitle();
		displayGrid(board);
		winCondition = winCheck(board, P1);
		if (winCondition == 1) {
			playerWin(P1);
		}
		
		tokenPos = promptPlayer(board, P2);
		validatePosition(board, P2, tokenPos);
		winCondition = winCheck(board, P2);
		system("cls");
		showTitle();
		displayGrid(board);
		if (winCondition == 1) {
			playerWin(P2);
		}

	} while (true);




	system("pause");
	return 0;
}



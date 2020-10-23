#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

const int WIDTH = 7;
const int HEIGHT = 6;
int gridArray[HEIGHT][WIDTH] = {};
int playerNumber;
bool gridUpdate = false;
int placeToken = 0;
int current_height = 5;

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

//Displays the 6x7 Grid 
void displayGrid() {

	int row_letter = 64; //In ASCII 64 represents "@", the character before A,B,C etc.
	
	cout << " |1| |2| |3| |4| |5| |6| |7| \n";
	cout << " [                         ]\n";

	for (int h = 0; h < HEIGHT; h++) {
		for (int w = 0; w < WIDTH; w++) {
			if (h > 0) {
				if (w == 0) {
					cout << endl;
				}
			}
			cout << " |" << gridArray[h][w] << "|";
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

void updateGrid(int columnNumber) {

	int h;
	int w;
	int my_array[WIDTH][HEIGHT];

	for (h = 0; h < HEIGHT; h++) {
		for (w = 0; w < WIDTH; w++) {
			if (columnNumber > 0) {

				if (gridArray[current_height][0] == 1) {
					current_height--;
				}
				
				gridArray[current_height][columnNumber -1] = 1;
			}
			else
			{
				gridArray[current_height][columnNumber] = 1;
			}
		}
	}

	cout << current_height << endl;
	cout << columnNumber << endl;
}

// Checks which players turn it is and prompts their turn accordingly
void promptPlayer() { 
	
	string welcome = "Hello! Welcome...";
	string prompt = "ENTER YOUR TURN PLAYER ";

	string p1_s = "Player 1, please enter the column number where you'd like to place your first piece! For example... 1 \n";
	string p1 = "Player 1's Turn";

	string p2_s = "Player 2, please enter where you'd like to place your first piece! For example... 2\n";
	string p2 = "Player 2's Turn";

	bool turn = false; // FALSE reperestents player 1's turn, TRUE will represent player 2's turn
	
	cout << welcome;

	if (!turn) {
		playerNumber = 1;
		cout << p1_s << endl;
	}
	else
	{
		playerNumber = 2;
		cout << p2_s;
	}

	cout << prompt << playerNumber << ": "<< endl;

}

//Takes the input of the current player
void recieveInput(string desiredPosition) { 

	//char desiredRow; ---- This is useless bc row is selected automatically
	int desiredColumn;
	size_t cascii;
	size_t column_int;

	for (unsigned int i = 0; i < desiredPosition.length(); i++) {
		cascii = desiredPosition.at(0);
		column_int = (int)cascii - 48;
		desiredColumn = (char)column_int;
	}

	placeToken = desiredColumn;
	
	cout << "\n";
	cout << "You entered column: " << desiredColumn << "\n" << "CONTINUE? Y/N?" << endl;
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
		cout << "GRID UPDATED...\n";
		updateGrid(placeToken);
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
	string dPos;
	char my_option;

	showTitle();

	displayGrid();

	do {
		promptPlayer();
		cin >> dPos;
		recieveInput(dPos);
		cin >> my_option;
		validateInput(my_option);
		displayGrid();
	} while (!gridUpdate);

	gridUpdate = false;

	system("pause");
	return 0;
}



#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

const int WIDTH = 7;
const int HEIGHT = 6;
int columnArray[WIDTH] = {};
char rowArray[HEIGHT] = {};
int playerNumber;
bool gridUpdate = false;

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

	int w;
	int h;
	int row_letter = 64; //In ASCII 64 represents "@", the character before A,B,C etc.
	
	cout << "  |1| |2| |3| |4| |5| |6| |7| \n";
	cout << "  +-+-+-+-+-+-+-+-+-+-+-+-+-+\n";

	for (w = 0; w < HEIGHT; w++)
	{
		for (h = 0; h < WIDTH; h++) 
		{
			if (h == 0) {
				row_letter++;
				cout << char(row_letter);
			}
			cout << " |" << "." << "|";
		}
		cout << "\n";
	}
	cout << "  +-+-+-+-+-+-+-+-+-+-+-+-+-+\n";
	cout << "\n";
	cout << "Player 1 = X\n";
	cout << "Player 2 = O\n";
	cout << "\n";
	cout << "\n";
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

void updateGrid() {
	int i;
	int j;

	for (i = 0; i < WIDTH; i++) {
		for (j = 0; j < HEIGHT; j++) {

		}
	}

}

// Does what it says on the tin
void showTitle() {
	cout << "{-------------------------------------}" << endl;
	cout << "{          CONSOLE CONNECT 4          }" << endl;
	cout << "{-------------------------------------} " << endl;
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



#include <iostream>
#include <string>

using namespace std;

const int WIDTH = 7;
const int HEIGHT = 6;
int columnArray[WIDTH] = {};
char rowArray[HEIGHT] = {};
int playerNumber;


void displayGrid() { //Displays the 6x7 Grid 

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
	cout << "\n";
}

void promptPlayer() { // Checks which players turn it is and prompts their turn accordingly
	
	string welcome = "Hello! Welcome...";
	string prompt = "ENTER YOUR TURN PLAYER ";

	string p1_s = "Player 1, please enter where you'd like to place your first piece! For example... B2\n";
	string p1 = "Player 1's Turn";

	string p2_s = "Player 2, please enter where you'd like to place your first piece! For example... B2\n";
	string p2 = "Player 2's Turn";

	bool turn = false; // FALSE reperestents player 1's turn, TRUE will represent player 2's turn
	
	cout << welcome;

	if (!turn) {
		cout << p1_s << endl;
		playerNumber = 1;
	}
	else
	{
		cout << p2_s;
		playerNumber = 2;
	}

	cout << prompt << playerNumber << ": "<< endl;

}

void recieveInput(string desiredPosition) { //Takes the input of the current player

	char desiredRow;
	int desiredColumn;
	size_t row;
	size_t cascii;
	size_t column_int;

	for (unsigned int i = 0; i < desiredPosition.length(); i++) {
		row = desiredPosition.at(0);
		desiredRow = (char)row;
		cascii = desiredPosition.at(1);
		column_int = (int)cascii - 48;
		desiredColumn = (char)column_int;
	}

	cout << "You enetred row: " << desiredRow << " and column: " << desiredColumn << endl;
}

void randExample() { // Generates a random example

}

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

	showTitle();
	displayGrid();
	promptPlayer();
	cin >> dPos;
	recieveInput(dPos);
	system("pause");
	return 0;
}



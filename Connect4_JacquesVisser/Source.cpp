#include <iostream>
#include <string>

using namespace std;

const int WIDTH = 7;
const int HEIGHT = 6;
int columnArray[WIDTH] = {};
int rowArray[HEIGHT] = {};

void displayGrid() {

	int w;
	int h;
	int row_letter = 64; //In ASCII 64 represents "@", the character before A,B,C etc.

	cout << "  |1| |2| |3| |4| |5| |6| |7| \n";
	cout << "  +-+-+-+-+-+-+-+-+-+-+-+-+-+\n";

	for (w = 0; w < HEIGHT; w++) {
		for (h = 0; h < WIDTH; h++) {
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

void promptPlayer() {
	
	string welcome = "Hello! Welcome...";
	string p1 = "Player 1, go!\n";
	string p2;
	bool turn = false;
	
	cout << welcome;

	if (!turn) {
		cout << p1;
	}
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
	char dRow;
	int dColumn;

	showTitle();
	displayGrid();
	promptPlayer();
	system("pause");
	return 0;
}



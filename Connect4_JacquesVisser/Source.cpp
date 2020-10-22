#include <iostream>

using namespace std;

const int WIDTH = 7;
const int HEIGHT = 6;

int main()
{
	int width[WIDTH] = {};
	int height[HEIGHT] = {};
	int w;
	int h;
	char row = 'A';

	cout << "  |1| |2| |3| |4| |5| |6| |7| \n";
	cout << "  +-+-+-+-+-+-+-+-+-+-+-+-+-+\n";

	for (w = 0; w < HEIGHT; w++) {
		for (h = 0; h < WIDTH; h++) {
			if (h == 0) {
				row++;
				cout << char(row - 1);
			}
			cout << " |" << width[w] << "|";
		}
		cout << "\n";
	}

	system("pause");
	return 0;
}
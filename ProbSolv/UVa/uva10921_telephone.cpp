#include <iostream>

using namespace std;

int main() {
	while (!cin.eof()) {
		char input[30] = {};

		cin >> input;

		if (cin.eof()) {
			break;
		}

		int i = 0;
		while (input[i] != '\0') {
			int res = input[i] % 65;
			if (res <= 2) {
				cout << 2;
			}
			else if (res <= 5) {
				cout << 3;
			}
			else if (res <= 8) {
				cout << 4;
			}
			else if (res <= 11) {
				cout << 5;
			}
			else if (res <= 14) {
				cout << 6;
			}
			else if (res <= 18) {
				cout << 7;
			}
			else if (res <= 21) {
				cout << 8;
			}
			else if (res <= 25) {
				cout << 9;
			}
			else {
				cout << input[i];
			}
			i++;
		}
		cout << endl;
	}

}
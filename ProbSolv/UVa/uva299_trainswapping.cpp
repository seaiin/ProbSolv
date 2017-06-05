#include <iostream>

using namespace std;

int main() {
	int n, l, tmp, swap;
	int train[50];

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> l;

		swap = 0;
		
		for (int j = 0; j < l; j++) {
			cin >> train[j];
		}

		for (int j = 0; j < l; j++) {
			for (int k = 0; k + 1 < l; k++) {
				if (train[k] > train[k + 1]) {
					tmp = train[k];
					train[k] = train[k + 1];
					train[k + 1] = tmp;
					swap++;
				}
			}
		}

		cout << "Optimal train swapping takes " << swap << " swaps." << endl;
	}
}
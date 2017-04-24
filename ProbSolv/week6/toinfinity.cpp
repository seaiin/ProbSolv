#include <iostream>
#include <stdlib.h>

using namespace std;

int main() {
	int n, x, y, r, ship = 1000000;
	
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> x >> y >> r;
		
		y = abs(y);

		if (ship > y - r) {
			ship = y - r;
		}		
	}

	if (ship < 1) {
		cout << -1 << endl;
	}
	else {
		cout << ship << endl;
	}
}
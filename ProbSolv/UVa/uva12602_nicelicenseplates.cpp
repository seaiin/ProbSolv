#include <iostream>
#include <math.h>

using namespace std;

int main() {
	int n;
	char licence[8];

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> licence;
		
		int l = 0, d = 0;

		for (int j = 0; j < 3; j++) {
			l += (licence[j] % 65) * pow(26, 2 - j);
		}

		for (int k = 4; k < 8; k++) {
			d += (licence[k] % 48) * pow(10, 7 - k);
		}

		if (abs(d - l) <= 100) {
			cout << "nice" << endl;
		}
		else {
			cout << "not nice" << endl;
		}
	}
}
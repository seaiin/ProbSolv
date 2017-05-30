#include <iostream>
#include <math.h>

using namespace std;

int decTobit(int a) {
	int b = 0;
	while (a > 0) {
		b += a % 2;
		a /= 2;
	}
	return b;
}

int decToHex(int a) {
	int hex = 0, i = 0;
	while (a > 0) {
		hex += (a % 10) * pow(16, ++i);
		a /= 10;
	}
	return hex;
}

int main() {
	int n, m;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> m;
		cout << decTobit(m) << " " << decTobit(decToHex(m)) << endl;
	}
}
#include <iostream>
#include <algorithm>

using namespace std;

int n;

int np(int a) {
	n++;
	if (a == 1) {
		return n;
	}
	if (a % 2 == 1) {
		a = (3 * a) + 1;
	}
	else {
		a /= 2;
	}
	np(a);
}

int main() {
	int i, j, tmp, maximum;

	while (!cin.eof()) {
		maximum = 0;
		cin >> i;
		if (cin.eof()) {
			break;
		}
		cin >> j;
		cout << i << " " << j << " ";
		if (i > j) {
			tmp = i;
			i = j;
			j = tmp;
		}
		for (int x = i; x <= j; x++) {
			n = 0;
			maximum = max(maximum, np(x));
		}
		cout << maximum << endl;
	}
}
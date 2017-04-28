#include <iostream>

using namespace std;

int n;
int banana[100000];
int point[100000];

int max(int x, int y) {
	if (x < y) {
		return y;
	}
	else {
		return x;
	}
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> banana[i];
	}

	for (int i = 0; i < n; i++) {
		if (i < 2) {
			point[i] = 0;
		}
		else if (i == 2) {
			point[i] = banana[i];
		}
		else {
			point[i] = max(banana[i] + point[i - 3], point[i - 1]);
		}
	}
	
	cout << point[n - 1] << endl;
}
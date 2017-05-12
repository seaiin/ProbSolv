#include <iostream>

using namespace std;

int main() {
	int n, k, val;
	cin >> n >> k;

	int map[20][20];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> val;
			map[i][j] = val;
		}
	}
}
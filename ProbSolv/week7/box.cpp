#include <iostream>

using namespace std;

int n, m;
bool isMove = false;

void canMove(char map[][30], int i, int j) {
	cout << i << j << endl;

	if (isMove) {
		return;
	}

	if (i >= 0 && j >= 0 && i + 1 < n && j + 1 < m) {
		canMove(map, i + 1, j);
		canMove(map, i - 1, j);
		canMove(map, i, j + 1);
		canMove(map, i, j - 1);
	}

	if (map[i][j] != '.' || map[i][j + 1] != '.' ||
		map[i + 1][j] != '.' || map[i + 1][j + 1] != '.') {
		return;
	}

	if (i + 2 == n) {
		isMove = true;
	}
}

int main() {
	char map[30][30];

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	canMove(map, 0, 0);

	cout << isMove << endl;

}

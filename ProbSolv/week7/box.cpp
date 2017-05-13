#include <iostream>

#define MAX_N 30

using namespace std;

int n, m;
bool isMove = false;
char map[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];

void canMove(int i, int j) {
	if (i < 0 || j < 0 || i >= n - 1 || j >= m - 1) {
		return;
	}
	
	if (visited[i][j]) {
		return;
	}

	if (map[i][j] != '.' || map[i][j + 1] != '.' || map[i + 1][j] != '.' || map[i + 1][j + 1] != '.') {
		return;
	}

	visited[i][j] = true;

	if (i == n - 2) {
		isMove = true;
		return;
	}

	canMove(i + 1, j);
	canMove(i - 1, j);
	canMove(i, j + 1);
	canMove(i, j - 1);
}

void unknow() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			visited[i][j] = false;
		}
	}
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	for (int j = 0; j < m - 1; j++) {
		unknow();
		canMove(0, j);
	}

	if (isMove) {
		cout << "yes" << endl;
	}
	else {
		cout << "no" << endl;
	}
}

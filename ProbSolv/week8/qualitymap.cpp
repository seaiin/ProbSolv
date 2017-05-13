#include <iostream>

#define MAX_N 30

using namespace std;

int n, m, type1 = 0, type2 = 0;
bool res1, res2;
char map[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];

void findLand(int r, int c) {

	if (r < 0 || c < 0 || r >= n || c >= m) {
		return;
	}

	if (visited[r][c]) {
		return;
	}

	if (map[r][c] == '#') {
		return;
	}

	visited[r][c] = true;

	if (map[r][c] == '*') {
		res1 = true;
	}

	if (map[r][c] == '$') {
		res2 = true;
	}

	findLand(r - 1, c);
	findLand(r + 1, c);
	findLand(r, c - 1);
	findLand(r, c + 1);

}

void unknow() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			visited[i][j] = false;
		}
	}
	res1 = false;
	res2 = false;
}

int main() {

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			unknow();
			findLand(i, j);
			if (res1 && res2) {
				type1++;
			}
			else if (res1 || res2) {
				type2++;
			}
		}
	}

	cout << type1 << " " << type2 << endl;
}
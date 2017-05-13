#include <iostream>
#define MAX_N 20

using namespace std;

int n, q;
bool res;
char map[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];

void findWay(int r, int c, int a, int b, int key) {

	if (r < 0 || c < 0 || r >= n || c >= n) {
		return;
	}
	
	if (visited[r][c]) {
		return;
	}

	if (map[r][c] == '#') {
		return;
	}
	
	visited[r][c] = true;

	if (map[r][c] == 'O') {
		if (key == 0) {
			return;
		}
		key = 0;
	}

	if (r == a && c == b) {
		res = true;
		return;
	}

	findWay(r - 1, c, a, b, key);
	findWay(r + 1, c, a, b, key);
	findWay(r, c - 1, a, b, key);
	findWay(r, c + 1, a, b, key);

}

void unknow() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			visited[i][j] = false;
		}
	}
}

int main() {
	int r, c, a, b;

	cin >> n >> q;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < q; i++) {
		cin >> r >> c >> a >> b;
		res = false;
		unknow();
		findWay(r - 1, c - 1, a - 1, b - 1, 1);
		if (res) {
			cout << "yes" << endl;
		}
		else {
			cout << "no" << endl;
		}
	}
}
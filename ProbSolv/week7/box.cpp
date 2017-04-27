#include <iostream>

using namespace std;

int n, m;
bool isMove = false;

void canMove(char map[][30], int i, int j) {

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

}

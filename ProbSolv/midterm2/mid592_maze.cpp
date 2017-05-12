#include <iostream>
#define MAX_N 20

using namespace std;

int n, q, a, b;
bool res;
char map[MAX_N][MAX_N];

void findWay(int r, int c, int key, char dir) {
	printf("%d %d\n", r, c);
	if (r == a - 1 && c == b - 1) {
		res = true;
	}
	if (map[r][c] == 'O') {
			key = 0;
	}
	if (map[r][c] != '\0' || map[r][c] != '#' ||
		(map[r][c] == 'O' && key == 0)) {
		if (map[r][c] == '.') {
			if (c > 0 && dir != 'r') {
				dir = 'l';
				findWay(r, c - 1, key, dir);
			}
			if (c < n && dir != 'l') {
				dir = 'r';
				findWay(r, c + 1, key, dir);
			}
			if (r > 0 && dir != 'd') {
				dir = 'u';
				findWay(r - 1, c, key, dir);
			}
			if (r < n && dir != 'u') {
				dir = 'd';
				findWay(r + 1, c, key, dir);
			}
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
		findWay(r - 1, c - 1, 1, ' ');
		if (res) {
			printf("yes\n");
		}
		else {
			printf("no\n");
		}
	}
}
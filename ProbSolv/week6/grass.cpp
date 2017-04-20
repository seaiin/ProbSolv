#include <iostream>

using namespace std;

int main() {
	int n, m, k;
	char commd;
	char land[100][100];

	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> land[i][j];
		}
	}

	for (int i = 0; i < m; i++) {
		cin >> commd >> k;
		k -= 1;
		if (commd == 'L') {
			for (int j = 0; j < n; j++) {
				if (land[k][j] == 'x') {
					land[k][j] = '.';
				}
				else {
					break;
				}
			}
		}
		else if (commd == 'R') {
			for (int j = n - 1; j >= 0; j--) {
				if (land[k][j] == 'x') {
					land[k][j] = '.';
				}
				else {
					break;
				}
			}
		}
		else if (commd == 'U') {
			for (int i = 0; i < n; i++) {
				if (land[i][k] == 'x') {
					land[i][k] = '.';
				}
				else {
					break;
				}
			}
		}
		else if (commd == 'D') {
			for (int i = n - 1; i >= 0; i--) {
				if (land[i][k] == 'x') {
					land[i][k] = '.';
				}
				else {
					break;
				}
			}
		}
		else if (commd == 'A') {
			for (int j = 0; j < n; j++) {
				if (land[k][j] == '.') {
					land[k][j] = 'x';
				}
			}
		}
		else if (commd == 'B') {
			for (int i = 0; i < n; i++) {
				if (land[i][k] == '.') {
					land[i][k] = 'x';
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << land[i][j];
		}
		cout << endl;
	}
}
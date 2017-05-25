#include <iostream>

#define MAX_N 10

using namespace std;

int r, c, b, t, water, res = 0;
int val[MAX_N][MAX_N], total[MAX_N];

int main() {

	cin >> r >> c >> b >> t;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> val[i][j];
			total[i] += val[i][j];
		}
	}

	water = b;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			for (int k = 0; k < val[i][j]; k++) {
				if (water >= t) {
					water -= t;
				}
				else {
					water = b - t;
					res++;
				}
			}
		}
		res++;
		water = b;
		if (i < r - 1) {
			if (total[i + 1] == 0) {
				res--;
			}
		}
	}

	cout << res << endl;
}
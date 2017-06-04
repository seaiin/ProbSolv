#include <iostream>

using namespace std;

int t, n, p, m, tmp, res;

int main() {
	cin >> t;

	for (int i = 0; i < t; i++) {
		int work[3650] = {};
		res = 0;

		cin >> n;

		cin >> m;

		for (int i = 0; i < m; i++) {
			cin >> p;
			
			tmp = p;

			while (tmp <= n) {
				work[tmp] = 1;
				tmp += p;
			}
		}

		for (int i = 1; i <= n; i++) {
			if (work[i] == 1 && i % 7 != 6 && i % 7 != 0) {
				res++;
			}
		}

		cout << res << endl;

	}
}

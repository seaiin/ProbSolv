#include <iostream>
#include <set>

using namespace std;

int main() {
	int n, m, cd, res;

	while (1) {
		cin >> n >> m;

		if (n == 0 && m == 0) {
			break;
		}

		set<int> jack;
		res = 0;

		for (int i = 0; i < n; i++) {
			cin >> cd;
			jack.insert(cd);
		}

		for (int i = 0; i < m; i++) {
			cin >> cd;
			if (jack.find(cd) != jack.end()) {
				res++;
			}
		}
		
		cout << res << endl;
	}
}
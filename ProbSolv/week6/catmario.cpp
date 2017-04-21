#include <iostream>

using namespace std;

int main() {
	int n, m, total = 0, stage, time;
	int times[100] = {};

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		cin >> stage >> time;
		if (times[stage - 1] == 0) {
			times[stage - 1] = time;
			total += time;
		}
		else if (times[stage - 1] > time) {
			total -= times[stage - 1];
			times[stage - 1] = time;
			total += time;
		}
	}
	
	cout << total << endl;

	for (int i = 0; i < n; i++) {
		cout << i + 1 << " " << times[i] << endl;
	}

}
#include <iostream>

using namespace std;

int main() {
	int n, a, b, bag = 0, temp = 1000000, total = 0;
	int over[1000] = {};
	int weight[1000] = {};
	
	cin >> n >> a >> b;

	for (int i = 0; i < n; i++) {
		cin >> weight[i];
	}

	for (int i = a; i <= b; i++) {
		for (int j = 0; j < n; j++) {
			if (weight[j] > i) {
				over[i] = 1000000;
				break;
			}
			total += weight[j];
			if (total > i) {
				over[i] += i - (total - weight[j]);
				total = weight[j];
			}
			if (j == n - 1) {
				over[i] += i - total;
			}
		}
		if (over[i] < temp) {
			bag = i;
			temp = over[i];
		}
		total = 0;
	}

	cout << bag << endl;
	
}
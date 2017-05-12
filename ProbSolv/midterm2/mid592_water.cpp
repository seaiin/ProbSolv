#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int n, res = 0;
	int water[10000] = {};
	int power[10000] = {};

	cin >> n;

	for (int i = 1; i <= n; i++) {	
		cin >> water[i];
		
		if (water[i -1] > water[i] + 10) {
			power[i] = 10 * abs(water[i - 1] - water[i]);
		}
		if (power[i] > 700) {
			power[i] = 700;
		}
		res += power[i];
	}
	cout << res << endl;
}
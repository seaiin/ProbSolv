#include <iostream>
#include <math.h>

using namespace std;

int main() {
	int t, n, ans;
	
	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> n;
		
		ans = (((((n * 567) / 9) + 7492) * 235) / 47) - 498;
		ans = abs((ans / 10) % 10);

		cout << ans << endl;
	}
}
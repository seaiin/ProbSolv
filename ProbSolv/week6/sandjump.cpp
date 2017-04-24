#include <iostream>

using namespace std;

int main() {
	int r, s, t, n, jump, range;

	cin >> r >> s >> t;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> jump;
		
		range = (jump - r) % (s + t);

		if (range <= s && jump - r > 0) {
			cout << "yes" << endl;
		}
		else {
			cout << "no" << endl;
		}
	}
}
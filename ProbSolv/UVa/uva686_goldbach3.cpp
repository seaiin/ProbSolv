#include <iostream>

using namespace std;

bool isPrime(int a) {
	if (a <= 1) {
		return false;
	}

	for (int i = 2; i < a; i++) {
		if (a % i == 0) {
			return false;
		}
	}

	return true;
}

int main() {
	int input;

	while (1) {
		cin >> input;
		
		if (input == 0) {
			break;
		}

		int tmp = 2, res = 0;
		
		while (tmp <= input / 2) {
			if (isPrime(tmp) && isPrime(input - tmp)) {
				res++;
			}
			tmp++;
		}
		
		cout << res << endl;
	}
}
#include <iostream>
#include <cmath>

using namespace std;

int main() {
	char set[1000];
	int count = 0, num = 0;
	
	cin >> set;
	
	for (int i = 0; set[i] != '\0'; i++) {
		if (set[i] >= 48 && set[i] <= 57) {
			num++;
		}
		else {
			num = 0;
		}
		if (num == 1) {
			count++;
		}
	}

	cout << (int)pow(2, count) << endl;
}
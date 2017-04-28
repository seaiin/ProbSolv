#include <iostream>

using namespace std;

int n, maximum, maxSeq = 0, point;
int seq[1000], range[1000];

int main() {

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> seq[i];
	}

	for (int i = 0; i < n; i++) {
		maximum = seq[i];
		range[i] = 1;
		for (int j = i; j < n; j++) {
			if (seq[j] > maximum) {
				maximum = seq[j];
				range[i]++;
			}
		}
		if (range[i] >= maxSeq) {
			maxSeq = range[i];
			point = i;
		}
	}

	maximum = -1000001;

	cout << range[point] << endl;

	for (int i = point; i < n; i++) {
		if (seq[i] > maximum) {
			cout << seq[i] << " ";
			maximum = seq[i];
		}
	}

	cout << endl;
}
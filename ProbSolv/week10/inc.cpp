#include <iostream>

#define MAX_N 10000

using namespace std;

int n, point, longest = 0, maxLenght;
int seq[MAX_N], lenght[MAX_N], maxPoint[MAX_N];

void printSeq(int n) {
	if (maxPoint[n] != -1) {
		printSeq(maxPoint[n]);
	}
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> seq[i];
		lenght[i] = 1;
		maxPoint[i] = -1;
	}

	for (int i = 0; i < n; i++) {
		maxLenght = 0;
		for (int j = 0; j < i; j++) {
			if (seq[i] > seq[j] && lenght[j] > maxLenght) {
				maxLenght = lenght[j];
				maxPoint[i] = j;
			}
			lenght[i] = maxLenght + 1;
			if (lenght[i] >= longest) {
				longest = lenght[i];
				point = i;
			}
		}
	}

	cout << longest << endl;

	for (int i = 0; i < n; i++) {
		cout << i << " " << maxPoint[i] << endl;
	}

}
#include <stdio.h>

#define MAX_N 1000

using namespace std;

int n, k, maxScore, maximum = 0;
int h[MAX_N], s[MAX_N];

int main() {

	scanf("%d %d", &n, &k);

	for (int i = 0; i < n; i++) {
		scanf("%d %d", &h[i], &s[i]);
	}

	for (int i = 0; i < n; i++) {
		
		maxScore = s[i];

		for (int j = i - 1; j >= 0; j--) {

			if (j >= 0) {

				if (h[i] <= h[j] && h[i] + k >= h[j] && s[j] + s[i] > maxScore) {
					maxScore = s[j] + s[i];
				}

			}
		}

		s[i] = maxScore;

		if (maxScore > maximum) {
			maximum = maxScore;
		}
	}

	printf("%d\n", maximum);
}
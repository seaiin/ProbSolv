#include <stdio.h>
#include <map>

using namespace std;

map<int, int> like;

int main() {
	int n, input, max = 0, mostLike;

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &input);
		if (++like[input] >= max) {
			mostLike = input;
			max = like[input];
		}
		printf("%d\n", mostLike);
	}
}
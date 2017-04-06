#include <stdio.h>
#include <map>

using namespace std;

map<int, int> costSet;
map<int, int>::iterator it;

int main() {
	int n, k, cost, budget, sum = 0;

	scanf("%d %d", &n, &k);

	for (int i = 1; i <= n; i++) {
		scanf(" %d", &cost);
		sum += cost;
		costSet.insert(make_pair(sum, i));
	}

	for (int i = 0; i < k; i++) {
		scanf(" %d", &budget);
		it = costSet.lower_bound(budget);
		if (budget >= sum) {
			printf("%d\n", n);
		}
		else if (budget < it->first) {
			printf("%d\n", it->second - 1);
		}
		else {
			printf("%d\n", it->second);
		}
	}
}
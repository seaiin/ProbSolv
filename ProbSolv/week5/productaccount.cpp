#include <stdio.h>
#include <map>

using namespace std;

map<int, int> product;
map<int, int>::iterator it;

int main() {
	int m, commd, prod, val;

	scanf("%d", &m);

	for (int i = 0; i < m; i++) {

		scanf("%d %d", &commd, &prod);

		it = product.find(prod);

		if (commd == 1) {
			scanf("%d", &val);
			if (it != product.end()) {
				it->second += val;
			}
			else {
				product.insert(pair<int, int>(prod, val));
			}
		}

		else if (commd == 2) {
			if (it != product.end()) {
				printf("%d\n", it->second);
			}
			else {
				printf("0\n");
			}

		}
		else if (commd == 3) {
			scanf("%d", &val);
			if (it != product.end()) {
				if (val > it->second) {
					printf("%d\n", it->second);
					it->second = 0;
				}
				else {
					printf("%d\n", val);
					it->second -= val;
				}
			}
			else {
				printf("0\n");
			}
		}
	}
}
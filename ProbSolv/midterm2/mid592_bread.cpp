#include <stdio.h>
#include <map>

using namespace std;

int n, q;

struct Bakery {
	int x;
	int c;
	int l;
};

map<int, Bakery*> bakerys;
map<int, Bakery*>::iterator it;

int main() {
	int xi, ci, li, qi;

	scanf("%d %d", &n, &q);

	for (int i = 0; i < n; i++) {
		scanf(" %d %d %d", &xi, &ci, &li);

		Bakery *bake = new Bakery();
		bake->x = xi;
		bake->c = ci;
		bake->l = li;

		for (int i = xi - 5; i <= xi + 5; i++) {
			it = bakerys.find(i);
			if (it != bakerys.end()) {
				if (it->second->c > bake->c) {
					bakerys.insert(make_pair(i, bake));
				}
			}
			else {
				bakerys.insert(make_pair(i, bake));
			}
		}
	}

	for (int i = 0; i < q; i++) {
		scanf(" %d", &qi);

		it = bakerys.find(qi);

		if (it != bakerys.end()) {
			if (it->second->l > 0) {
				printf("%d\n", it->second->c);
				it->second->l -= 1;
			}
		}
		else {
			printf("0\n");
		}
	}
}
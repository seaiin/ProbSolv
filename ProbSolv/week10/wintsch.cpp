#include <stdio.h>
#include <algorithm>
#include <set>

using namespace std;

int n;

struct Schd {
	int start;
	int finish;
	int weight;
	Schd *prev;
};

set<pair<int, Schd*>> schds;

int main() {
	int s, f, w;

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf(" %d %d %d", s, f, w);
		Schd *schd = new Schd();
		schd->start = s;
		schd->finish = f;
		schd->weight = w;
		schd->prev = NULL;
		schds.insert(make_pair(f, schd));
	}

	for (set<pair<int, Schd*>>::reverse_iterator i = schds.rbegin() + 1;
		i != schds.rend(); i++) {
		for (set<pair<int, Schd*>>::reverse_iterator j = schds.rbegin();
			j != i; j++) {
			if (i->second->start >= j->second->finish) {
			}
		}
	}
}
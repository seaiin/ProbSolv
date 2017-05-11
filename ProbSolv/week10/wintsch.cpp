#include <stdio.h>
#include <set>

using namespace std;

struct Schd {
	int no;
	int start;
	int finish;
	int weight;
	int prevs;
	Schd *prev;
};

set<pair<int, Schd*>> schds;

void print(Schd *sch) {
	if (sch->prev != NULL) {
		print(sch->prev);
	}
	printf("%d ", sch->no);
}

int main() {
	int n, s, f, w, maxWeight, opt = 0;
	Schd *res = new Schd();

	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		scanf(" %d %d %d", &s, &f, &w);
		Schd *schd = new Schd();
		schd->no = i;
		schd->start = s;
		schd->finish = f;
		schd->weight = w;
		schd->prevs = 1;
		schd->prev = NULL;
		schds.insert(make_pair(f, schd));
	}

	for (set<pair<int, Schd*>>::iterator i = schds.begin();
		i != schds.end(); i++) {
		maxWeight = i->second->weight;
		for (set<pair<int, Schd*>>::iterator j = schds.begin();
			j != i; j++) {
			if (i->second->start >= j->second->finish) {
				if (i->second->weight + j->second->weight > maxWeight) {
					maxWeight = i->second->weight + j->second->weight;
					i->second->prevs += j->second->prevs;
					i->second->prev = j->second;
				}
			}
		}
		i->second->weight = maxWeight;
		if (i->second->weight > opt) {
			opt = i->second->weight;
			res = i->second;
		}
	}

	printf("%d\n%d\n", res->weight, res->prevs);
	print(res);
	printf("\n");

}
#include <stdio.h>
#include <vector>
#include <list>

using namespace std;

#define MAX_N 100000

int n, m;
vector<int> adj[MAX_N];
int deg[MAX_N];
int levels[MAX_N];
bool isBipartite;

void read_input() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		deg[i] = 0;
		adj[i].clear();
	}

	for (int i = 0; i < m; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		u--;
		v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
		deg[u]++;
		deg[v]++;
	}
}

void find_levels(int s) {
	list<int> next_level;
	for (int u = 0; u < n; u++) {
		levels[u] = -1;
	}

	next_level.push_back(s);
	levels[s] = 0;
	
	while (!next_level.empty()) {
		list<int> current_level = next_level;
		next_level.clear();

		for (list<int>::iterator i = current_level.begin(); i != current_level.end(); i++) {
			int u = *i;
			for (vector<int>::iterator j = adj[u].begin(); j != adj[u].end(); j++) {
				int v = *j;
				if (levels[v] == -1) {
					levels[v] = levels[u] + 1;
					next_level.push_back(v);
				}
				else if (levels[v] % 2 == levels[u] % 2) {
					isBipartite = false;
				}
			}
		}
	}
}

int main() {
	int k;
	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		read_input();
		isBipartite = true;
		find_levels(0);
		if (isBipartite) {
			printf("yes\n");
		}
		else {
			printf("no\n");
		}
	}
}
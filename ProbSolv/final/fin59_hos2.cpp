#include <stdio.h>
#include <functional>
#include <queue>
#include <vector>

using namespace std;

int n, m, h, res = 0, maxHos = 0;

vector<pair<int, int>> *adj;
priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void addEdge(int a, int b, int w) {
	adj[a].push_back(make_pair(b, w));
	adj[b].push_back(make_pair(a, w));
}

void shortestPath(int src) {
	int a, b, weight;
	vector<int> dist(n, 100000);
	pq.push(make_pair(0, src));
	dist[src] = 0;
	while (!pq.empty()) {

		a = pq.top().second;
		pq.pop();

		for (vector<pair<int, int>>::iterator i = adj[a].begin();
			i != adj[a].end(); i++) {

			b = (*i).first;
			weight = (*i).second;

			if (dist[b] > dist[a] + weight) {
				dist[b] = dist[a] + weight;
				pq.push(make_pair(dist[b], b));
			}
		}
	}
	for (int j = 0; j < n; j++) {
		if (dist[j] <= h) {
			res++;
		}
	}
	maxHos = max(res, maxHos);
	res = 0;
}

int main() {
	int a, b;

	scanf("%d %d %d", &n, &m, &h);

	adj = new vector<pair<int, int>>[n];

	for (int i = 0; i < m; i++) {
		scanf(" %d %d", &a, &b);

		addEdge(a - 1, b - 1, 1);
	}

	for (int i = 0; i < n; i++) {
		shortestPath(i);
	}

	printf("%d\n", maxHos);
}
#include <stdio.h>
#include <map>
#include <set>

using namespace std;

struct Node
{
	int rank;
	int data;
	Node *parent;
};

struct Edge
{
	int edge1;
	int edge2;
};

map<int, Node*> maps;
set<pair<int, Edge*>> edges;

void makeSet(int data) {
	Node *node = new Node();
	node->data = data;
	node->parent = node;
	node->rank = 0;
	maps[data] = node;
}

Node* findSet(Node *node) {
	Node *parent = node->parent;
	if (parent == node) {
		return parent;
	}
	return findSet(node->parent);
}

void un(int data1, int data2) {
	Node *node1 = maps.find(data1)->second;
	Node *node2 = maps.find(data2)->second;

	Node *parent1 = findSet(node1);
	Node *parent2 = findSet(node2);

	if (parent1->data == parent2->data) {
		return;
	}

	if (parent1->rank >= parent2->rank) {
		parent1->rank = (parent1->rank == parent2->rank) ?
			parent1->rank + 1 : parent1->rank;
		parent2->parent = parent1;
	}
	else {
		parent1->parent = parent2;
	}
}

int find(int data) {
	return findSet(maps.find(data)->second)->data;
}

int main() {

	int n, m, node1, node2, w, res = 0;

	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++) {
		makeSet(i);
	}

	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &node1, &node2, &w);
		Edge *edge = new Edge();
		edge->edge1 = node1;
		edge->edge2 = node2;
		edges.insert(pair<int, Edge*>(w, edge));
	}

	for (set<pair<int, Edge*>>::iterator i = edges.begin();
		i != edges.end(); i++) {
		if (find(i->second->edge1) != find(i->second->edge2)) {
			un(i->second->edge1, i->second->edge2);
			res += i->first;
		}
	}

	printf("%d\n", res);
}
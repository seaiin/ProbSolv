#include <stdio.h>
#include <map>

using namespace std;

int n, q;

struct Node
{
	int rank;
	int data;
	Node *parent;
};

map<int, Node*> maps;

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
	node->parent = findSet(node->parent);
	return node->parent;
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

	char commd;
	int x, y;

	scanf("%d %d", &n, &q);

	for (int i = 1; i <= n; i++) {
		makeSet(i);
	}

	for (int i = 0; i < q; i++) {
		scanf(" %c %d %d", &commd, &x, &y);

		if (commd == 'c') {
			un(x, y);
		}
		else if (commd == 'q') {
			if (find(x) == find(y)) {
				printf("yes\n");
			}
			else {
				printf("no\n");
			}
		}
	}
}
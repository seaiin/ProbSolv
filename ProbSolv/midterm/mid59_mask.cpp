#include <iostream>
#include <map>

using namespace std;

map<int, int> winnerA;
map<int, int> winnerB;
map<int, int> winner;
map<int, int>::iterator it1;
map<int, int>::iterator it2;

int main() {
	int n, mostSkill = 0, skill, prog;

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> skill;
		if (skill > mostSkill) {
			mostSkill = skill;
			prog = i;
		}
	}
	winnerA.insert(pair<int, int>(prog, mostSkill));
	mostSkill = 0;

	for (int i = n + 1; i <= 2 * n; i++) {
		cin >> skill;
		if (skill > mostSkill) {
			mostSkill = skill;
			prog = i;
		}
	}
	winnerA.insert(pair<int, int>(prog, mostSkill));
	it2 = winnerA.find(prog);
	mostSkill = 0;

	for (int i = (2 * n) + 1; i <= 3 * n; i++) {
		cin >> skill;
		if (skill > mostSkill) {
			mostSkill = skill;
			prog = i;
		}
	}
	winnerB.insert(pair<int, int>(prog, mostSkill));
	mostSkill = 0;

	for (int i = (3 * n) + 1; i <= 4 * n; i++) {
		cin >> skill;
		if (skill > mostSkill) {
			mostSkill = skill;
			prog = i;
		}
	}
	winnerB.insert(pair<int, int>(prog, mostSkill));
	mostSkill = 0;

	it1 = winnerA.begin();

	if (it1->second > it2->second) {
		winner.insert(pair<int, int>(it1->first, it1->second));
		winnerA.erase(it1);
	}
	else {
		winner.insert(pair<int, int>(it2->first, it2->second));
		winnerA.erase(it2);
	}

	it1 = winnerB.begin();
	it2 = winnerB.find(prog);

	if (it1->second > it2->second) {
		winner.insert(pair<int, int>(it1->first, it1->second));
		winnerB.erase(it1);
	}
	else {
		winner.insert(pair<int, int>(it2->first, it2->second));
		winnerB.erase(it2);
	}

	it1 = winner.begin();
	it2 = it1;
	it2++;

	if (it1->second > it2->second) {
		cout << it1->first << " " << it2->first << " ";
	}
	else {
		cout << it2->first << " " << it1->first << " ";
	}
	
	it1 = winnerA.begin();
	cout << it1->first << " ";
	it2 = winnerB.begin();
	cout << it2->first << endl;
}
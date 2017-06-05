#include <iostream>
#include <map>
#include <list>

using namespace std;

int main() {

	int seq;
	map<int, int> seq_map;
	list<int> seq_list;

	while (1) {
		cin >> seq;

		map<int, int>::iterator it = seq_map.find(seq);
		if (it == seq_map.end()) {
			seq_map.insert(pair<int, int>(seq, 1));
			seq_list.push_back(seq);
		}
		else {
			it->second++;
		}

		if (cin.get() == '\n') {
			break;
		}
	}

	for (list<int>::iterator i = seq_list.begin(); i != seq_list.end(); i++) {
		map<int, int>::iterator it = seq_map.find(*i);
		cout << it->first << " " << it->second << endl;
	}
}
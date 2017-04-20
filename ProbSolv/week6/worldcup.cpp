#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct TeamStruct {
	char name[20];
	int gf;
	int ga;
	int gd;
	int point;

	bool operator < (const TeamStruct& rhs) const {
		return point < rhs.point;
	}

	TeamStruct() : gf(0), ga(0), point(0) {}
};

int main() {
	TeamStruct *team = new TeamStruct[4];
	TeamStruct *swap = new TeamStruct;
	int goalTb[4][4];
	for (int i = 0; i < 4; i++) {
		cin >> team[i].name;
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> goalTb[i][j];
			team[i].gf += goalTb[i][j];
		}
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			team[i].ga += goalTb[j][i];
			if (goalTb[i][j] > goalTb[j][i]) {
				team[i].point += 3;
			}
			else if (goalTb[i][j] == goalTb[j][i]) {
				team[i].point += 1;
			}
		}
		team[i].gd = team[i].gf - team[i].ga;
	}
	sort(team, team + 4);

	for (int i = 3; i >= 0; i--) {
		if (i > 0) {
			if (team[i].point == team[i - 1].point) {
				if (team[i - 1].gf > team[i].gf) {
					*swap = team[i];
					team[i] = team[i - 1];
					team[i - 1] = *swap;
				}
				else if (team[i - 1].gf == team[i].gf) {
					if (team[i - 1].gd > team[i].gd) {
						*swap = team[i];
						team[i] = team[i - 1];
						team[i - 1] = *swap;
					}
				}
			}
		}
		cout << team[i].name << " " << team[i].point - 1 << endl;
	}
}
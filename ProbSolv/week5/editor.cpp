#include <iostream>
#include <list>
#include <string>

using namespace std;

int main() 
{
	list<string> strList;
	list<string>::iterator it = strList.begin();
	int n;
	char commd;
	string str;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> commd;
		if (commd == 'l') {
			if (it != strList.begin()) {
				it--;
			}
		}
		else if (commd == 'r') {
			if (it != strList.end()) {
				it++;
			}
		}
		else if (commd == 'i') {
			cin >> str;
			strList.insert(it, str);
		}
		else if (commd == 'b') {
			if (it != strList.begin()) {
				it--;
				it = strList.erase(it);
			}
		}
		else if (commd == 'd') {
			if (it != strList.end()) {
				it = strList.erase(it);
			}
		}
	}
	for (list<string>::iterator j = strList.begin(); j != strList.end(); j++)
	{
		cout << *j << " ";
	}
	cout << endl;
}
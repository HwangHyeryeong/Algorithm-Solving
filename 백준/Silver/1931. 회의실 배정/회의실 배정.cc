#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n; cin >> n;
	vector<pair<int, int>> meeting;

	for (int i = 0; i < n; i++) {
		int s, e; cin >> s >> e;
		meeting.push_back({ e, s });
	}
	sort(meeting.begin(), meeting.end());

	int end = 0, count = 0;
	for (auto i : meeting) {
		if (i.second >= end) {
			end = i.first;
			count++;
		}
	}
	cout << count << endl;

	return 0;
}
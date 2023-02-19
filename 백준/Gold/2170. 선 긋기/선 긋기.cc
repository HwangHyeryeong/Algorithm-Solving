#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<long long, long long> a, pair<long long, long long> b) {
	if (a.first == b.first) {
		return a.second < b.second;
	}
	return a.first < b.first;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

	int n; cin >> n;

	vector<pair<long long, long long>> line;
	for (int i = 0; i < n; i++) {
		long long s, e; cin >> s >> e;
		line.push_back({ s, e });
	}
	sort(line.begin(), line.end(), cmp);

	int start = line[0].first, end = line[0].second, length = 0;
	for (int i = 1; i < n; i++) {
		if (end < line[i].first) {
			length += (end - start);
			start = line[i].first;
			end = line[i].second;
		}
		else if (start <= line[i].first && end >= line[i].first && end < line[i].second)
			end = line[i].second;
	}
	length += (end - start);

	cout << length << endl;

	return 0;
}
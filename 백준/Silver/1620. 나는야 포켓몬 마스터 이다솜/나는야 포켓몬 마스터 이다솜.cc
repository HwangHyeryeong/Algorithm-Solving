#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n, m; cin >> n >> m;
	map<string, string> map;
	for (int i = 1; i <= n; i++) {
		string name; cin >> name;
		map.insert({ name, to_string(i) });
		map.insert({ to_string(i), name });
	}

	while (m--) {
		string s; cin >> s;
		cout << map[s] << "\n";
	}

	return 0;
}
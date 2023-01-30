#include <iostream>
#include <stack>
using namespace std;

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

	int n, h = 0; 
	cin >> n;
	stack<pair<int, int>> tower;
	for (int i = 1; i <= n; i++) {
		cin >> h;
		while (!tower.empty()) {
			if (h < tower.top().second) {
				cout << tower.top().first << " ";
				break;
			}
			tower.pop();
		}
		if (tower.empty()) {
			cout << 0 << " ";
		}
		tower.push({i, h});
	}

	return 0;
}

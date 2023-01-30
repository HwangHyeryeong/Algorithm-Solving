#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
	int n; cin >> n;
	vector<long long> tower(n + 1, 0);
	stack<long long> hieght, s;

	for (int i = 1; i <= n; i++) {
		cin >> tower[i];
		hieght.push(i);
	}

	int now = 0;
	while (!hieght.empty()) {
		now = hieght.top();
		hieght.pop();

		if (hieght.empty()) {
			tower[now] = 0;
		}
		else if (tower[now] <= tower[hieght.top()]) {
			tower[now] = hieght.top();
			while (!s.empty()) {
				if (tower[s.top()] > tower[hieght.top()])
					break;
				else {
					tower[s.top()] = hieght.top();
					s.pop();
				}
			}
		}
		else {
			s.push(now);
		}
	}

	while (!s.empty()) {
		tower[s.top()] = 0;
		s.pop();
	}

	for (int i = 1; i <= n; i++) {
		cout << tower[i] << " ";
	}

	return 0;
}
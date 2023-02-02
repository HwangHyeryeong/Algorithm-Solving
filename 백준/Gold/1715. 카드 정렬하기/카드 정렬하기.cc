#include <iostream>
#include <queue>
using namespace std;

int main() {
	int n; cin >> n;
	priority_queue<int, vector<int>, greater<int>> q;

	for (int i = 0; i < n; i++) {
		int tmp; cin >> tmp;
		q.push(tmp);
	}

	int answer = 0;
	
	while (q.size() > 1) {
		int a = q.top(); q.pop();
		int b = q.top(); q.pop();
		answer += (a + b);
		q.push(a + b);
	}

	cout << answer << endl;

	return 0;
}
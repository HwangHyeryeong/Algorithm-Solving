#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, v;
vector<int> graph[1001];
bool visitedD[1001] = { 0 };
bool visitedB[1001] = { 0 };

void dfs(int s) {
	if (visitedD[s])
		return;
	
	visitedD[s] = true;
	cout << s << " ";

	for (int i = 0; i < graph[s].size(); i++) {
		if (!visitedD[graph[s][i]])
			dfs(graph[s][i]);
	}
}

void bfs(int s) {
	queue<int> q;

	visitedB[s] = true;
	q.push(s);
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		cout << cur << " ";

		for (int i = 0; i < graph[cur].size(); i++) {
			if (!visitedB[graph[cur][i]]) {
				visitedB[graph[cur][i]] = true;
				q.push(graph[cur][i]);
			}
		}
	}
	cout << '\n';
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

	cin >> n >> m >> v;
	while (m--) {
		int a, b; cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	for (int i = 1; i <= n; i++) {
		sort(graph[i].begin(), graph[i].end());
	}

	dfs(v); 
	cout << '\n';
	bfs(v);

	return 0;
}
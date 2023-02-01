#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> graph[1001];


void bfs(int start) {
	bool visited[1001] = { 0 };
	queue<int> q;

	q.push(start);
	visited[start] = true;
	while (!q.empty()) {
		int v = q.front(); q.pop();
		cout << v << ' ';
		for (int i : graph[v]) {
			if (!visited[i]) {
				q.push(i);
				visited[i] = true;
			}
		}
	}
	cout << '\n';
}

void dfs(int start, vector<bool> &visited) {
	if (visited[start]) return;
	
	visited[start] = true;
	cout << start << ' ';

	for (int i = 0; i < graph[start].size(); i++) {
		int x = graph[start][i];
		if (!visited[x])
			dfs(x, visited);
	}
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

	int n, m, s;
	cin >> n >> m >> s;

	for (int i = 0; i < m; i++) {
		int v1, v2; cin >> v1 >> v2;
		graph[v1].push_back(v2);
		graph[v2].push_back(v1);
	}

	//정점 번호 작은 것부터 방문하도록
	for (int i = 1; i <= n; i++)
		sort(graph[i].begin(), graph[i].end());

	vector<bool> visited(n + 1);
	dfs(s, visited);
	cout << '\n';
	bfs(s);

	return 0;
}
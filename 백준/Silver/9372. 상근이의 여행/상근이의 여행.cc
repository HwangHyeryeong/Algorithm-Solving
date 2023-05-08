#include <iostream>
#include<cstring>
#include <queue>
#include <vector>
using namespace std;

int n, m, num = 0;
bool visited[1001] = { 0 };

void bfs(vector<int> v[], int s) {
	queue<int> q;
	visited[s] = true;
	q.push(s);
	while(!q.empty()){
		int cur = q.front(); q.pop();
		for (int i = 0; i < v[cur].size(); i++) {
			if (!visited[v[cur][i]]) {
				visited[v[cur][i]] = true;
				q.push(v[cur][i]);
				num++;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int t; cin >> t;
	while (t--) {
		num = 0;
		memset(visited, 0, sizeof(visited));
		vector<int> airplane[1001];

		cin >> n >> m;
		for (int i = 0; i < m; i++) {
			int s, e; cin >> s >> e;
			airplane[s].push_back(e);
			airplane[e].push_back(s);
		}

		bfs(airplane, 1);
		cout << num << endl;
	}

	return 0;
}
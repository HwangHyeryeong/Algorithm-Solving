#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 50000001

int n, m;
vector<pair<int, int>> graph[50001];
int dist[50001];

void dijkstra(int start) {
	priority_queue<pair<int, int>> pq;
	dist[start] = 0;
	pq.push({ 0, start });


	while (!pq.empty()) {
		int curNode = pq.top().second;
		int curDist = -pq.top().first;
		pq.pop();

		if (dist[curNode] < curDist) continue;

		for (pair<int, int> i : graph[curNode]) {
			int updateNode = i.first;
			int updateDist = curDist + i.second;

			if (updateDist < dist[updateNode]) {
				dist[updateNode] = updateDist;
				pq.push({ -updateDist, updateNode });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c; cin >> a >> b >> c;
		graph[a].push_back({ b, c });
		graph[b].push_back({ a, c });
	}

	fill(&dist[0], &dist[n + 1], INF);
	dijkstra(1);

	cout << dist[n] << endl;

	return 0;
}
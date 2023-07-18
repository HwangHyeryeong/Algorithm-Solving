#include <bits/stdc++.h>
using namespace std;

int n, m;
int graph[101][101] = { 0 };
int dist[101][101] = { 0 };
bool visited[101][101] = { 0 };
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };

void bfs(int x, int y){
    queue<pair<int, int>> q;
    
    visited[x][y] = true;
    dist[1][1] = 1;
    q.push({x, y});
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        
        q.pop();
        for(int i = 0; i < 4; i++){
            int nextX = x + dx[i];
            int nextY = y + dy[i];
            
            if(nextX > 0 && nextX <= n && nextY > 0 && nextY <= m){
                if(!visited[nextX][nextY] && graph[nextX][nextY]){
                    visited[nextX][nextY] = true;
                    dist[nextX][nextY] = dist[x][y] + 1;
                    q.push({nextX, nextY});
                }
            }
        }
    }    
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%1d", &graph[i][j]);
		}
	}
    
    bfs(1,1);
    printf("%d", dist[n][m]);

	return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define INF 999999999

int n, m, x;
int graph[1001][1001];
vector<int> dist;

void calcRoute(){
    for(int k = 1; k <= n; k++)
        for(int a = 1; a <= n; a++){
            for(int b = 1; b <= n; b++){
                graph[a][b] = min(graph[a][b], graph[a][k] + graph[k][b]);
            }
        }
}

int main(){
    cin >> n >> m >> x;
    
    fill(&graph[0][0], &graph[1000][1001], INF);
    for(int i = 0; i < 1001; i++)
        graph[i][i] = 0;
        
    for(int i = 0; i < m; i++){
        int s, e, t; cin >> s >> e >> t;
        graph[s][e] = t;
    }
    
    calcRoute();
    
    int maxDist = 0;
    for(int i = 1; i <= n; i++){
        maxDist = max(maxDist, graph[i][x] + graph[x][i]);
    }
    cout << maxDist << endl;
    
    return 0;
}
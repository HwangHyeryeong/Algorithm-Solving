#include <bits/stdc++.h>
using namespace std;

#define INF 999999999

int n, m;
int graph[101][101];
vector<int> dist;

void floyd_warshall(){
    for(int k = 1; k <= n; k++)
        for(int a = 1; a <= n; a++){
            for(int b = 1; b <= n; b++){
                graph[a][b] = min(graph[a][b], graph[a][k] + graph[k][b]);
            }
        }
}

int main(){
    cin >> n >> m;
    
    fill(&graph[0][0], &graph[100][101], INF);
    for(int i = 0; i < 101; i++)
        graph[i][i] = 0;
        
    for(int i = 0; i < m; i++){
        int s, e, c; cin >> s >> e >> c;
        if(graph[s][e] != INF){
            graph[s][e] = min(graph[s][e], c);
        }
        else
            graph[s][e] = c;
    }
    
    floyd_warshall();
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(graph[i][j] == INF)
                cout << 0 << " ";
            else
                cout << graph[i][j]<<" ";
        }
        cout<< "\n" ;
    }
    
    return 0;
}
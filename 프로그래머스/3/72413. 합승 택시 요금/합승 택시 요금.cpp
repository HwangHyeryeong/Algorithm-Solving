#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define MAX_DIST 999999

int graph[201][201];

void floyd_warshall(int n){
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0;
    
    //그래프 초기화
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            graph[i][j] = (i==j)? 0 : MAX_DIST;
    
    for(int i = 0; i < fares.size(); i++){
        int u = fares[i][0];
        int v = fares[i][1];
        int w = fares[i][2];
        
        graph[u][v] = w;
        graph[v][u] = w;
    }
    
    floyd_warshall(n);
    
    answer = graph[s][a] + graph[s][b]; // 따로 가는 경우
    // 같이 가는 경우(경유지: m번 노드)
    for(int m = 1; m <= n; m++){
        answer = min(answer, graph[s][m] + graph[m][a] + graph[m][b]);
    }
    
    return answer;
}
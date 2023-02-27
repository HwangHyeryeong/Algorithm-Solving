#include <bits/stdc++.h>
using namespace std;

#define INF 99999999

int n, m, start, dest;
vector<pair<int, int>> graph[1001];
vector<int> dist(1001, INF);

void dijkstra(int start){
    priority_queue<pair<long long, int>> pq;
    dist[start] = 0;
    
    pq.push({dist[start], start});
    
    while(!pq.empty()){
        int d = -pq.top().first;
        int now = pq.top().second;
        pq.pop();
        
        if(dist[now] < d) continue;
        
        for(int i = 0; i < graph[now].size(); i++){
            int connNode = graph[now][i].first;
            int cost = d + graph[now][i].second;
            if(cost < dist[connNode]){
                dist[connNode] = cost;
                pq.push({-cost, connNode});
            }
        }
    }
}



int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int s, e, c; cin >> s >> e >> c;
        graph[s].push_back({e, c});
    }
    cin >> start >> dest;
    
    dijkstra(start);
    
    cout << dist[dest] << endl;
    
    return 0;
}
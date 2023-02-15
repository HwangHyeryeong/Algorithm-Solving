#include <bits/stdc++.h>
using namespace std;

#define INF 99999999

vector<pair<int, int>> cities[300001];
int dist[300001];

void dijkstra(int start){
    dist[start] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push({start, 0});
    
    while(!pq.empty()){
        int cur = pq.top().first;
        int d = -pq.top().second;
        pq.pop();
        
        if(dist[cur] < d) continue;
        for(int i = 0; i < cities[cur].size(); i++){
            int next = cities[cur][i].first;
            int nextDist = d + cities[cur][i].second;
            if(nextDist < dist[next]){
                dist[next] = nextDist;
                pq.push({next, -nextDist});
            }
        }
    }
}

int main(){
    int n, m, k, x; cin >> n >> m >> k >> x;
    
    for(int i = 0; i < m; i++){
        int s, e; cin >> s >> e;
        cities[s].push_back({e, 1});
    }
    
    for(int i = 1 ; i <= n; i++)
        dist[i] = INF;
    
    dijkstra(x);
    
    int count = 0;
    for(int i = 1; i <= n; i++){
        if(dist[i] == k){
            cout << i << endl;
            count++;
        }
    }
    if(!count)
        cout << -1 << endl;
    
    return 0;
}
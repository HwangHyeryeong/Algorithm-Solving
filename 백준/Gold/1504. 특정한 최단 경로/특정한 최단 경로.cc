#include <bits/stdc++.h>
using namespace std;

#define INF 10000000

int n, e, v1, v2;
vector<pair<int, int>> graph[801];
int dist[801];

void dijkstra(int start){
    priority_queue<pair<int, int>> pq;
    dist[start] = 0;
    pq.push({0, start});
    
    while(!pq.empty()){
        int curIndex = pq.top().second;
        int curDist = -pq.top().first;
        pq.pop();
        
        if(curDist > dist[curIndex]) continue;
        
        for(int i = 0; i < graph[curIndex].size(); i++){
            int updateIndex = graph[curIndex][i].first;
            int updateDist = graph[curIndex][i].second + curDist;
            if(updateDist < dist[updateIndex]){
                dist[updateIndex] = updateDist;
                pq.push({-updateDist, updateIndex});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> n >> e;
    for(int i = 0; i < e; i++){
        int s, e, c; cin >> s >> e >> c;
        graph[s].push_back({e, c});
        graph[e].push_back({s, c});
    }
    cin >> v1 >> v2;
    
    int ans1 = 0, ans2 = 0;
    
    fill_n(&dist[0], 801, INF);
    dijkstra(1);
    ans1 += dist[v1];
    ans2 += dist[v2];
    
    fill_n(&dist[0], 801, INF);
    dijkstra(v1);
    ans1 += dist[v2];
    ans2 += (dist[v2] + dist[n]); 
    
    fill_n(&dist[0], 801, INF);
    dijkstra(v2);
    ans1 += dist[n];
    
    
    if(ans1 >= INF && ans2 >= INF)
        cout << -1 << endl;
    else
        cout << min(ans1, ans2) << endl;
    
    return 0;
}
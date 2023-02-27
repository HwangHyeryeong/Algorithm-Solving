#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 999999

int v, e, start;
vector<pair<int, int>> graph[20001];
vector<int> dist(20001, INF);

void dijkstra(int start){
    dist[start] = 0;
    
    priority_queue<pair<int, int>> pq; //거리, 노드번호
    pq.push({dist[start], start});
    
    while(!pq.empty()){
        int curNode = pq.top().second;
        int curDist= -pq.top().first;
        pq.pop();
        
        if(dist[curNode] < curDist) continue;
        
        for(int i = 0; i < graph[curNode].size(); i++){
            int updateNode = graph[curNode][i].first;
            int updateDist = curDist + graph[curNode][i].second;
            
            if(updateDist < dist[updateNode]){
                dist[updateNode] = updateDist;
                pq.push({-updateDist, updateNode});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> v >> e >> start;
    for(int i = 0; i < e; i++){
        int u, v, w; cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }
    
    dijkstra(start);
    
    for(int i = 1; i <= v; i++){
        if(dist[i] == INF)
            cout <<"INF\n";
        else
            cout << dist[i] << endl;
    }
    
    return 0;
}
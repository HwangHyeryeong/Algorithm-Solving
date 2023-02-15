#include <bits/stdc++.h>
using namespace std;


vector<pair<long long, long long>> jewels;
vector<long long> bags;


int main(){
    int n, k; cin >> n >> k;
    for(int i = 0; i < n; i++){
        int m, v; cin >> m >> v;
        jewels.push_back({m, v});
    }
    sort(jewels.begin(), jewels.end());
    
    for(int i = 0; i < k; i++){
        long long w; cin >> w;
        bags.push_back(w);
    }
    sort(bags.begin(), bags.end());
    
    long long sum = 0;
    int cur = 0;
    priority_queue<long long> pq;
    for(auto bag : bags){
        while(cur < n && jewels[cur].first <= bag)
            pq.push(jewels[cur++].second);
        if(!pq.empty()){
            sum += pq.top();
            pq.pop();
        }
    }
    
    cout << sum << endl;
    
    return 0;
}
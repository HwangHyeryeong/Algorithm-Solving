#include <iostream>
#include <vector>
#include <cmath>
#include <limits.h>
#include <algorithm>
using namespace std;

int n, m;
vector<pair<int, int>> house;
vector<pair<int, int>> store;
vector<int> pick;

int calcChickenDist(){
    vector<int> hDist(house.size(), INT_MAX);
    for(int i : pick){
        int storeX = store[i].second, storeY = store[i].first;
        for(int j = 0; j < house.size(); j++){
            int tmpDist = abs(storeX - house[j].second) + abs(storeY - house[j].first);
            hDist[j] = min(hDist[j], tmpDist);
        }
    }
    
    int dist = 0;
    for(int d : hDist)
        dist += d;
        
    return dist;
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int info; cin >> info;
            
            if(info == 1) house.push_back({i, j});
            else if(info == 2) store.push_back({i, j});
        }
    }
    
    vector<bool> v(store.size() - m, false);
    v.insert(v.end(), m, true);
    int dist = INT_MAX;
    do{
        pick.clear();
        for(int i = 0; i < store.size(); i++){
            if(v[i])
                pick.push_back(i);
        }
        
        dist = min(dist, calcChickenDist());
    }while(next_permutation(v.begin(), v.end()));
    
    
    cout << dist;
    
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int n, m;
bool possible = false;
vector<int> friends[2000];
bool visited[2000] = { 0 };

void dfs(int x, int depth){
    if(depth == 4){
        possible = true;
        return;
    }
    
    if(visited[x])
        return;
    
    visited[x] = true;
    for(auto i : friends[x]){
        if(!visited[i]){
            dfs(i, depth + 1);
        }
    }
    visited[x] = false;
}

int main(){
    cin >> n >>m;
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        friends[a].push_back(b);
        friends[b].push_back(a);
    }
    
    for(int i = 0; i < n; i++){
        dfs(i, 0);
        if (possible){
            break;
        }
    }
    
    cout << possible << endl;
    
    return 0;
}
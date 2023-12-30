#include <iostream>
#include <vector>
using namespace std;

int cnt = 0, del;
vector<vector<int>> tree;

void dfs(int node){
    if(node == del){
        return;
    }

    if(tree[node].size() == 0){
        cnt++; 
        return;
    }
    
    for(int next : tree[node]){
        if(next == del && tree[node].size() == 1){
            cnt++;
            continue;
        }
        dfs(next);
    }
}

int main(){
    int n; cin >> n;
    tree = vector<vector<int>>(n);
    
    int root = 0;
    for(int i = 0; i < n; i++){
        int parent; cin >> parent;
        if(parent == -1){
            root = i;
            continue;
        }
        
        tree[parent].push_back(i);
    }
    cin >> del;
    
    dfs(root);
    cout << cnt;
    
    return 0;
}
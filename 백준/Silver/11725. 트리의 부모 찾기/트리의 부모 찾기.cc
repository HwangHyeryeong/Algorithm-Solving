#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> v[100001];
vector<int> parent(100001, 0);

void dfs(int cur){
    for(int i : v[cur]){
        if(!parent[i]){
            parent[i] = cur;
            dfs(i);
        }
    }
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        int tmp1, tmp2; cin >> tmp1 >> tmp2;
        v[tmp1].push_back(tmp2);
        v[tmp2].push_back(tmp1);
    }
    
    dfs(1);
    
    for(int i = 2; i <= n; i++)
        cout << parent[i] << '\n';
        
    return 0;
}
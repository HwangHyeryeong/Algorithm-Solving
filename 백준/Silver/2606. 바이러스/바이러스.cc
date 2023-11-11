#include <iostream>
#include <vector>
using namespace std;

vector<int> com[101];
bool visited[101] = {0};
int virus = 0;

void dfs(int x) {
    visited[x] = true;
    
    for(auto i : com[x]){
        if(!visited[i]){
            virus++;
            dfs(i);
        }
    }
}

int main() {
    int n, v; cin >> n >> v;
    
    for(int i = 0; i < v; i++){
        int s, e; cin >> s >> e;
        com[s].push_back(e);
        com[e].push_back(s);
    }
    
    dfs(1);
    
    cout << virus << endl;
    
    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
    
    int n; cin >> n;
    vector<vector<int>> tree(n + 1);
    for(int i = 1; i < n; i++){
        int s, e; cin >> s >> e;
        tree[s].push_back(e);
        tree[e].push_back(s);
    }
    
    int q; cin >> q;
    for(int i = 0; i < q; i++){
        int cmd, node; cin >> cmd >> node;
        
        if(cmd == 1){
            if(tree[node].size() == 1) cout << "no\n";
            else cout << "yes\n";
        }
        else if(cmd == 2){
            cout << "yes\n";
        }
    }
    return 0;
}
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int k, n;
vector<int> nodes;
vector<int> tree[11];

void level(int s, int e, int depth){
    int mid = (s + e) / 2;
    tree[depth].push_back(nodes[mid]);
    
    if(s == e) return;
    
    level(s, mid - 1, depth + 1);
    level(mid + 1, e, depth + 1);
}

int main(){
    cin >> k;
    n = pow(2, k) - 1;
    for(int i = 0; i < n; i++){
        int tmp; cin >> tmp;
        nodes.push_back(tmp);
    }
    
    level(0, n - 1, 1);
    for(int i = 1; i <= k; i++){
        for(int node : tree[i])
            cout << node << " ";
        cout << '\n';
    }
    
    return 0;
}
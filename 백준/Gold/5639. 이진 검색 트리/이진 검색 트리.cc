#include <iostream>
#include <vector>
using namespace std;

vector<int> tree;

void postOrder(int s, int e){
    if(s >= e) return;
    
    if(s == e - 1){
        cout << tree[s] << endl;
        return;
    }
    
    int idx = s + 1;
    while(idx < e){
        if(tree[s] < tree[idx]){
            break;
        }
        idx++;
    }
    
    postOrder(s + 1, idx);
    postOrder(idx, e);
    cout << tree[s] << endl;
}

int main(){
    int node;
    while(cin >> node){
        tree.push_back(node);
    }
    
    postOrder(0, tree.size());
    
    return 0;
}
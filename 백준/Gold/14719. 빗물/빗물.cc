#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int H, W; cin >> H >> W;
    vector<int> walls(W + 2, 0);
    
    for(int i = 1; i <= W; i++){
        cin >> walls[i];
    }
    
    int s = 0, e = 0, rains = 0;
    for(int c = 0; c < W; c++){
        for(int i = 0; i < c; i++){
            s = max(s, walls[i]);
        }
        for(int i = c + 1; i <= W; i++){
            e = max(e, walls[i]);
        }
        int h = min(s, e);
        if(h > walls[c])
            rains += h - walls[c];
        s = 0; e = 0;
    }
    cout << rains;    
    
    return 0;
}
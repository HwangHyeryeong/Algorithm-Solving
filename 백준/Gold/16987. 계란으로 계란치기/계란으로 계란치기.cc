#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, ans = 0; 
vector<pair<int, int>> eggs;

int cntCracked(){
    int ans = 0;
    for(auto e : eggs){
        if(e.first <= 0) ans++;
    }
    return ans;
}

void crackingEggs(int x){
    if(x > n) return;
    
    for(int i = 0; i < n; i++){
        if(eggs[x].first <= 0) crackingEggs(x + 1);
        else if(x == i || eggs[i].first <= 0) continue;
        else{
            eggs[x].first -= eggs[i].second;
            eggs[i].first -= eggs[x].second;
            
            crackingEggs(x + 1);
            
            eggs[x].first += eggs[i].second;
            eggs[i].first += eggs[x].second;
        }
    }
    
    ans = max(ans, cntCracked());
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        int tmpD, tmpW; cin >> tmpD >> tmpW; //내구도, 무게
        eggs.push_back({tmpD, tmpW});
    }
    
    crackingEggs(0);
    
    cout << ans;
    
    return 0;
}
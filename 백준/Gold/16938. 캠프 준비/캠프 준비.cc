#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int ans = 0;
int n, l, r, x;
vector<int> levels;
vector<bool> visit;

void backtracking(int m, int c, int sum){
    if(sum > r) return;
    
    if(l <= sum && sum <= r && levels[c] - levels[m] >= x)
        ans++;
        
    for(int i = c + 1; i <= n; i++){
        if(visit[i]) continue;
        
        visit[i] = true;
        backtracking(m, i, sum + levels[i]);
        visit[i] = false;
    }
}

int main(){
    cin >> n >> l >> r >> x;
    levels.resize(n + 1);
    visit.resize(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> levels[i];
    }
    sort(levels.begin(), levels.end());
    
    for(int i = 1; i <= n; i++){
        visit[i] = true;
        backtracking(i, i, levels[i]);
        visit[i] = false;
    }
    
    cout << ans;
    
    return 0;
}
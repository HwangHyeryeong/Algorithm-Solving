#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<pair<int, int>> items = {{0,0}};
int dp[101][100001] = { 0 };

int main(){
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        int w, v; cin >> w >> v;
        items.push_back({w, v});
    }
    sort(items.begin(), items.end());
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= k; j++){
            if(items[i].first > j)
                dp[i][j] = dp[i - 1][j];
            else{
                dp[i][j] = max(dp[i - 1][j], (items[i].second + dp[i - 1][j - items[i].first]));
            }
        } 
    }
    
    cout << dp[n][k] << endl;
    
    return 0;
}
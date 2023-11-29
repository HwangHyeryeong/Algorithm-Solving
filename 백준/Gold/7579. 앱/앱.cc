#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int ans = 10000001;

int main(){
    int n, m; cin >> n >> m;
    vector<pair<int, int>> apps = {{0, 0}};
       
    for(int i = 0; i < n; i++){
        int memory; cin >> memory;
        apps.push_back({memory, 0});
    }

    int cost = 0;
    for(int i = 1; i <= n; i++){
        cin >> apps[i].second;
        cost += apps[i].second;
    }
    
    sort(apps.begin(), apps.end());
    
    vector<vector<int>> dp(n + 1, vector<int>(cost + 1, 0));
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= cost; j++){
            if(j >= apps[i].second){
                dp[i][j] = max(dp[i - 1][j], apps[i].first + dp[i - 1][j - apps[i].second]);
            }
            else{
                dp[i][j] = dp[i - 1][j];
            }
            
            if(dp[i][j] >= m){
                ans = min(ans, j);
            }
        }
    }
    
    cout << ans << endl;
    
    return 0;
}
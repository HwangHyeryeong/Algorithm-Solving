#include <bits/stdc++.h>
using namespace std;

int main(){
    string a, b; cin >> a >> b;
    vector<vector<int>> dp(a.size() + 1, vector<int>(b.size() + 1, 0));
    
    int ans = 0;
    for(int i = 1; i <= a.size(); i++){
        for(int j = 1; j <= b.size(); j++){
            if(a[i - 1] == b[j - 1]){
                dp[i][j] = dp[i - 1][j - 1] + 1;
                ans = max(dp[i][j], ans);
            }
            
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    
    cout << ans << endl;
    
    return 0;
}
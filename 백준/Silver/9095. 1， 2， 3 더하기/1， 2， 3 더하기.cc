#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    vector<pair<int, int>> dp(12);
    
    dp[0] = {0, 0};
    dp[1] = {1, 1};
    dp[2] = {2, 1};
    dp[3] = {4, 2};
    dp[4] = {7, 3};
    
    for(int i = 5; i <= 11; i++){
        dp[i].second = dp[i - 1].second + dp[i - 2].second + dp[i - 3].second;
        dp[i].first = dp[i - 1].first + dp[i].second;
    }
    
    for(int i = 0; i < n; i++){
        int input; cin >>input;
        cout << dp[input].first << endl;
    }
    
    return 0;
}
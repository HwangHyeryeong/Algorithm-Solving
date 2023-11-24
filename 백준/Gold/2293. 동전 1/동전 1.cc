#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, k; cin >> n >> k;
    vector<int> coins(n + 1, 0);
    for(int i = 1; i <= n; i++){
        cin >> coins[i];
    }
    
    vector<int> dp(k + 1, 0);
    dp[0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = coins[i]; j <= k; j++){
            dp[j] += dp[j - coins[i]];
        }
    }
    
    cout << dp[k];
    
    return 0;
}

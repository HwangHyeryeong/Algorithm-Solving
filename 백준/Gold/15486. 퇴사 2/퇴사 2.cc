#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n; cin >> n;
    vector<int> schedule(n + 1, 0);
    vector<int> price(n + 1, 0);
    for(int i = 1; i <= n; i++){
        cin >> schedule[i] >> price[i];
    }
    
    vector<long long> dp(n + 2, 0);
    for(int i = n; i > 0; i--){
        if(i + schedule[i] > n + 1)
            dp[i] = dp[i + 1];
        else
            dp[i] = max(dp[i + 1], price[i] + dp[i + schedule[i]]);
    }
    
    cout << dp[1];
    
    return 0;
}
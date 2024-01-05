#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n; cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    vector<int> dp(n, 0);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            if(arr[i] > arr[j] && dp[i] < dp[j]) dp[i] = dp[j];
        }
        dp[i]++;
    }
    
    int ans = *max_element(dp.begin(), dp.end());
    cout << ans;
    
    return 0;
}
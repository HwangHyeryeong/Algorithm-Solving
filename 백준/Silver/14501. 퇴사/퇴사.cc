#include <iostream>
#include <algorithm>
using namespace std;

int n;
int schedule[16] = {0}; //기간
int price[16] = {0}; //금액
int dp[16] = {0};

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> schedule[i] >> price[i];
    }
    
    
    for (int i = n; i > 0; i--) {
		if (i + schedule[i] > n + 1)
			dp[i] = dp[i + 1];
		else
			dp[i] = max(dp[i + 1], price[i] + dp[i + schedule[i]]);
	}
    
    cout << dp[1];
    
    return 0;
}
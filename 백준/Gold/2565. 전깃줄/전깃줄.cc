#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    vector<pair<int, int>> line = {{0, 0}};
    
    int maxNumOfLine = 0;
    for(int i = 0; i < n; i++){
        int s, e; cin >> s >> e;
        line.push_back({s, e});
        maxNumOfLine = max(maxNumOfLine, e);
    }
    sort(line.begin(), line.end());
    
    vector<vector<int>> dp(n + 1, vector<int>(maxNumOfLine + 2, 0));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= maxNumOfLine; j++){
            if(line[i].second == j && (dp[i - 1][j + 1] >= dp[i][j])){
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else{
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }
    
    cout << n - dp[n][maxNumOfLine] << endl;
    
    return 0;
}
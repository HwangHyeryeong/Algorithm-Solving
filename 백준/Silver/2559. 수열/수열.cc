#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n, k; cin >> n >> k;
    vector<int> v(n+1, 0);
    
    int sum = 0, ans = -99999;
    for(int i = 1; i <= n; i++){
        cin >> v[i];
        
        if(i >= k){
            sum = sum - v[i - k] + v[i];
            ans = (ans > sum)? ans : sum;
        }
        else{
            sum += v[i];
        }
    }
    
    cout << ans << endl;
    
    return 0;
}
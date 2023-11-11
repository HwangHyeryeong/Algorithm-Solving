#include <iostream>
#include <vector>
using namespace std;

int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
    
    int n, x; cin >> n >> x;
    vector<int> visitor(n + 1, 0);
    for(int i = 1; i <= n; i++){
        int tmp; cin >> tmp;
        visitor[i] = visitor[i - 1] + tmp;
    }
    
    int max = 0, days = 0;
    for(int i = x; i <= n; i++){
        int curSum = visitor[i] - visitor[i - x];
        if(max < curSum){
            max = curSum;
            days = 1;
        }
        else if(max == curSum) days++;
    }
    
    (max != 0)? (cout << max << endl << days) : (cout << "SAD");
    
    return 0;
}
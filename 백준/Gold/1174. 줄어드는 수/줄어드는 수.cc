#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int n;
vector<long long> decreaseNums;

void backtracking(string tmp){
    decreaseNums.push_back(stoll(tmp));
    
    int last = stoi(tmp.substr(tmp.size() - 1));
    for(int i = last - 1; i >= 0; i--){
        backtracking(tmp + to_string(i));
    }
}

int main(){
    cin >> n;
    
    for(int i = 0; i < 10; i++)
        backtracking(to_string(i));
    
    sort(decreaseNums.begin(), decreaseNums.end());
    
    if(n > decreaseNums.size()) cout << -1;
    else cout << decreaseNums[n - 1];
    
    return 0;
}

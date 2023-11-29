#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, s;
vector<int> arr;
int answer = 0;

void dfs(int sum, int cnt){
    if(cnt == n)
        return;
    
    if(sum + arr[cnt] == s)
        answer++;
    
    dfs(sum + arr[cnt], cnt + 1);
    dfs(sum, cnt + 1);
}

int main(){
    cin >> n >> s;
    arr = vector<int>(n, 0);
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    
    dfs(0, 0);
    cout << answer;
    
    return 0;
}
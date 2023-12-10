#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;

int n, answer = INT_MAX;
bool visit[11] = {0};
int cost[10][10] = {0};

void move(int s, int idx, int cnt, int sum){
    if(cnt == n){
        if(!cost[idx][s]) return;
        answer = min(answer, sum + cost[idx][s]);
        return;
    }
    
    for(int i = 0; i < n; i++){
        if(visit[i] | !cost[idx][i]) continue;
        visit[i] = true;
        move(s, i, cnt+1, sum + cost[idx][i]);
        visit[i] = false;
    }
}

int main(){
    cin >> n;
    for(int  i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> cost[i][j];
        }
    }
    
    for(int i = 0; i < n; i++){
        visit[i] =true;
        move(i, i, 1, 0);
        visit[i] = false;
    }
    
    cout << answer;
    
    return 0;
}
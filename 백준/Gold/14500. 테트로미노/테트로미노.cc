#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int ans = 0;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int paper[502][502] = {0};
bool visit[502][502] = {0};

bool isValidLoc(int x, int y){
    return x > 0 && x <= m && y > 0 && y <=n;
}

void dfs(int x, int y, int cnt, int sum){
    if(cnt == 4){
        ans = max(sum, ans);
        return;
    }
    
    for(int i = 0; i < 4; i++){
        int nextX = x + dx[i];
        int nextY = y + dy[i];
        if(isValidLoc(nextX, nextY) && !visit[nextY][nextX]){
            visit[nextY][nextX] = true;
            dfs(nextX, nextY, cnt + 1, sum + paper[nextY][nextX]);
            visit[nextY][nextX] = false;
        }
    }
}

void specialShape(int i, int j) {
    int sum = paper[i][j];
    int mini = 1001;
    for (int k = 0; k < 4; k++) {
        mini = min(mini, paper[i + dy[k]][j + dx[k]]);
        sum += paper[i + dy[k]][j + dx[k]];
    }
    ans = max(sum - mini, ans);
}

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++)
            cin >> paper[i][j];
    }
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            visit[i][j] = true;
            dfs(j, i, 1, paper[i][j]);
            visit[i][j] = false;
            specialShape(i, j);
        }
    }
    
    cout << ans;
    
    return 0;
}
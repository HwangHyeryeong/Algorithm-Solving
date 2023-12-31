#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;
char seat[6][6];

vector<pair<int, int>> students;
bool safe = false;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

bool isSafe(bool check[6][6]){
    for(auto s : students){
        if(check[s.first][s.second]) return false;
    }
    
    return true;
}

void bfs(){
    queue<pair<int, int>> q;
    bool check[6][6] = {0};
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(seat[i][j] == 'T'){
                q.push({i, j});
                check[i][j] = true;
            }
        }
    }
    
    while(!q.empty()){
        int x = q.front().second;
        int y = q.front().first;
        q.pop();
        
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            while(nx >= 0 && nx < n && ny >= 0 && ny < n){
                if(seat[ny][nx] != 'O'){
                    check[ny][nx] = true;
                    nx += dx[i]; ny += dy[i];
                }
                else break;
            }
        }
    }
    
    safe |= isSafe(check);
}

void dfs(int cnt){
    if(cnt == 3){
        bfs();
        return;
    }

    if(safe) return;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(seat[i][j] == 'X'){
                seat[i][j] = 'O';
                dfs(cnt + 1);
                seat[i][j] = 'X';
            }
        }
    }
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> seat[i][j];
            if(seat[i][j] == 'S') students.push_back({i, j});
        }
    }

    dfs(0);
    cout << (safe? "YES" : "NO");
    
    return 0;
}
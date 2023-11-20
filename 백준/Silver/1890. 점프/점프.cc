#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> game[101];
vector<long> dist[101];

int dr[] = {1, 0};
int dc[] = {0, 1};


bool isValid(int r, int c){
    return r > 0 && c > 0 && r <= n && c <= n;
}

long dfs(int r, int c){
    if(r == n && c == n){
        return 1;
    }
    
    if(dist[r][c] != -1)
        return dist[r][c];
    
    dist[r][c] = 0;
    for(int i = 0; i < 2; i++){
        int nextR = r + dr[i] * game[r][c];
        int nextC = c + dc[i] * game[r][c];
        
        if(isValid(nextR, nextC)){
            dist[r][c] += dfs(nextR, nextC);
        }
    }

    return dist[r][c];
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        game[i] = vector<int>(n + 1, 0);
        dist[i] = vector<long>(n + 1, -1);
        
        for(int j = 1; j <= n; j++){
            cin >> game[i][j];
        }
    }
    
    dfs(1, 1);
    
    cout << dist[1][1];
    
    return 0;
}
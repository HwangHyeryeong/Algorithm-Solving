#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

vector<vector<int>> map;
vector<vector<bool>> visited;

int dfs(int x, int y){
    int days = map[y][x];
    visited[y][x] = true;
    
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 1 || nx > m || ny < 1 || ny > n) continue;
        if (!visited[ny][nx] && map[ny][nx]) {
            visited[ny][nx] = true;
            days += dfs(nx, ny);
        }    
    }
        
    return days;
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    n = maps.size(); //y
    m = maps[0].size(); //x
    map.resize(n + 1, vector<int>(m + 1, 0));
    visited.resize(n + 1, vector<bool>(m + 1, 0));
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            char c = maps[i][j];
            if(c != 'X') map[i + 1][j + 1] = (c - '0');
        }
    }
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if (!visited[i][j] && map[i][j] > 0) 
                answer.push_back(dfs(j, i));
        }
    }
    
    if(answer.size() > 0)
        sort(answer.begin(), answer.end());
    else
        answer.push_back(-1);
    
    return answer;
}
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> grid;

int solution(int m, int n, vector<vector<int>> puddles) {
    grid.resize(n + 1, vector<int>(m + 1));
    
    for(vector<int> p : puddles){
        int x = p[0];
        int y = p[1];
        grid[y][x] = -1; // 물에 잠긴 지역
    }
    
    grid[1][1] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if (grid[i][j] == -1) {
                grid[i][j] = 0; //물에 잠긴 지역 경로 수는 0
                continue;
            }
            grid[i][j] += grid[i - 1][j];
            grid[i][j] += grid[i][j - 1];
            grid[i][j] %= 1000000007;            
        }
    }
    
    return grid[n][m];
}
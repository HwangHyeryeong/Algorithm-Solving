#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, -1, 0, 1};

int main(){
    int r, c; cin >> r >> c;
    vector<vector<char>> map(r + 2, vector<char>(c + 2, '.'));
    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= c; j++){
            cin >> map[i][j];
        }
    }
    
    int trimRS = r, trimRE = 0, trimCS = c, trimCE = 0;
    vector<vector<char>> future(r + 1, vector<char>(c + 1, '.'));
    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= c; j++){
            int sink = 0;
            for(int k = 0; k < 4; k++){
                if(map[i + dr[k]][j + dc[k]] == '.') sink++;
            }
            if(map[i][j] == 'X' && sink < 3){
                future[i][j] = 'X';
                
                trimRE = i; trimRS = min(trimRS, i);
                trimCE = max(trimCE, j); trimCS = min(trimCS, j);
            }
        }
    }
    
    for(int i = trimRS; i <= trimRE; i++){
        for(int j = trimCS; j <= trimCE; j++)
            cout << future[i][j];
        cout << endl;
    }
    
    return 0;
}
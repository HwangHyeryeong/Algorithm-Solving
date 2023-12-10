#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> solution(vector<vector<int>> origin,int n, int m){
    vector<vector<int>> tmp = origin;

    int repeat = min(n,m) / 2;
    bool visited[300][300] = {0,};

    for(int size = 0; size < repeat; size++){
        int cntX = size, cntY = size;

        while(!visited[cntX][cntY]){
            visited[cntX][cntY] = true;
            if(cntX == size && cntY != m-1-size){
                tmp[cntX][cntY] = origin[cntX][cntY+1];
                cntY++;
            }
            else if(cntY == m-1-size && cntX != n-1-size){
                tmp[cntX][cntY] = origin[cntX+1][cntY];
                cntX++;
            }
            else if(cntX == n-1-size && cntY != size){
                tmp[cntX][cntY] = origin[cntX][cntY-1];
                cntY--;
            }
            else if(cntY == size && cntX != size){
                tmp[cntX][cntY] = origin[cntX-1][cntY];
                cntX--;
            }
        }
    }
    return tmp;
}
int main(){
    int N,M,R;
    vector<vector<int>> map;
    
    cin >> N >> M >> R;
    for(int i = 0; i < N; i++){
        vector<int> tmp;
        for(int j = 0; j < M; j++){
            int val;
            cin >> val;
            tmp.push_back(val);
        }
        map.push_back(tmp);
    }
    
    vector<vector<int>> answer;
    while(R--){
        map = solution(map,N,M);
    }
    answer = map;

    for(int i = 0; i < answer.size(); i++){
        for(int j = 0; j < answer[i].size(); j++)
            cout << answer[i][j] << " ";
        cout << endl;
    }
    
    return 0;
}
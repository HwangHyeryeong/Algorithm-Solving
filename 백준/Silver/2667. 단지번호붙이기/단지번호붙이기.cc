#include <bits/stdc++.h>
using namespace std;

int n, fam = 0;
int apt[25][25];
vector<int> fams;

bool dfs(int x, int y){
    if(x < 0 || x >= n || y < 0 || y >= n)
        return false;
    
    if(apt[y][x]){
        fam++;
        apt[y][x] = 0; //방문 처리
        dfs(x-1, y);
        dfs(x+1, y);
        dfs(x, y-1);
        dfs(x, y+1);
        return true;
    }
    return false;
}


int main(){
    cin >> n;
    
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%1d", &apt[i][j]);
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(dfs(j, i)){
                fams.push_back(fam);
                fam = 0;
            }
        }
    }
    
    sort(fams.begin(), fams.end());
    
    cout << fams.size() << endl;
    for(auto i : fams)
        cout << i << endl;
        
    return 0;
}
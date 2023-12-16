#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, target; cin >> n >> target;
    vector<vector<int>> table(n, vector<int>(n, 0));
    
    int move[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int x = 0, y = 0, d = 0, num = n * n;

    while(num){
        table[y][x] = num;
        
        if(x + move[d][0] < 0 || x + move[d][0] >= n 
        || y + move[d][1] < 0 || y + move[d][1] >= n || table[y+move[d][1]][x+move[d][0]])
            d = (d + 1) % 4;
        x += move[d][0];
        y += move[d][1];
        num--;
    }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(table[i][j] == target){
                x = j + 1; y = i + 1;    
            }
            cout << table[i][j] << " ";
        }
        cout << endl;
    }
    cout << y << " " << x;
    
    
    return 0;
}
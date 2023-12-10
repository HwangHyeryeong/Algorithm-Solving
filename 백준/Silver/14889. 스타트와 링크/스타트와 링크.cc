#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int n, num, answer = -1;
int map[22][22] = {0};
int team1[12] = {0};
int team2[12] = {0};
bool visit[12] = {0};

void play(int s, int cnt){
    if(cnt == num){
        int tmp1 = 0, tmp2 = 0;
        
        for (int i = 0; i < n; i++){
            if(visit[i]){
                team1[tmp1] = i; 
                tmp1++;
            }else{
                team2[tmp2] = i; 
                tmp2++;
            }
        }
        tmp1 = 0; tmp2 = 0;
        for (int j = 0; j < num - 1; j++){
            for (int k = j + 1; k < num; k++){
                tmp1 += map[team1[j]][team1[k]] + map[team1[k]][team1[j]]; 
                tmp2 += map[team2[j]][team2[k]] + map[team2[k]][team2[j]]; 
            }
        }
        int sub = abs(tmp1 - tmp2); 
        if(answer > sub || answer == -1){ 
            answer = sub;
        }
    }
    else{ 
        for (int i = s; i < n;i++){ 
            if(!visit[i]){
                visit[i] = true;
                play(i+1, cnt + 1);
                visit[i] = false;
            }
        }
    }
}

int main(){
    cin >>n;
    num = n / 2;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> map[i][j];
        }
    }
    
    play(0, 0);
    cout << answer;
    
    return 0;
}
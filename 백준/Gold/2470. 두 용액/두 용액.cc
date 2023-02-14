#include <bits/stdc++.h>
using namespace std;

vector<int> solution;
int sol1, sol2;

void findCombination(){
    int s = 0, e = solution.size() - 1;
    int sum = 2000000000, tmp;
    while(s < e){
        tmp = solution[s] + solution[e];
        if(abs(tmp) < sum){
            sol1 = solution[s];
            sol2 = solution[e];
            sum = abs(tmp);
        }
        if(tmp < 0) s++;
        else e--;
    }
}

int main(){
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int tmp; cin >> tmp;
        solution.push_back(tmp);
    }
    sort(solution.begin(), solution.end());
    
    findCombination();
    cout << sol1 << " " << sol2 << endl;
    
    return 0;
}
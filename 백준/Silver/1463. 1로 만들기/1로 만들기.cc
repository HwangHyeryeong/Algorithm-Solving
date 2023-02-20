#include <bits/stdc++.h>
using namespace std;

int x;
int num[1000001] = { 0 };

void getNum(){
    for(int i = 2; i <= x; i++){
        int a = 9999999, b = 9999999, c = 9999999;
        
        if(i % 3 == 0)
            a = num[i / 3] + 1;
        if(i % 2 == 0)
            b = num[i / 2] + 1;
        c = num[i - 1] + 1;
        num[i] = min({a, b, c});
    }
}

int main(){
    cin >> x;
    getNum();
    
    cout << num[x] << "\n";
    
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int h, w, n, room;

int main(){
    int t; cin >> t;
    for(int i = 0; i < t; i++){
        cin >> h >> w >> n;
        if(n % h == 0)
            room = h * 100 + (n / h);
        else
            room = (n % h) * 100 + (n / h) + 1;
        cout << room << endl;
    }
    
    return 0;
}
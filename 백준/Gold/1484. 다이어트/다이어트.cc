#include <iostream>
using namespace std;

int main(){
    int g; cin >> g;
    
    bool find = false;
    int now = 1, last = 1;
    while(true){
        if((now - last == 1) && (now * now - last * last > g)) break;
        
        int tmp = (now + last) * (now - last);
        if(tmp == g)    {
            find = true;
            cout << now << endl;
            now++; last++;
        }
        else if(tmp < g) now++;
        else last++;
    }
    if(!find) cout << -1;
        
    return 0;
}
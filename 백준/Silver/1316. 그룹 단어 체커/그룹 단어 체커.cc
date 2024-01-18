#include <iostream>
#include <map>
#include <string>
using namespace std;

bool isGroupWord(string str){
    map<char, int> check;
    
    for (int i = 0; i < str.length(); i++) {
        if(check.find(str[i]) != check.end() && check[str[i]] != i - 1)
            return false;
        
        check[str[i]] = i;
    }
    return true;
}

int main(){
    int n; cin >> n;
    
    int ans = 0;
    for(int i = 0; i < n; i++){
        string word; cin >> word;
        ans += isGroupWord(word);
    }
    cout << ans;
    
    return 0;
}
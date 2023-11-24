#include <iostream>
#include <string>
#include <map>
using namespace std;

int main(){
 int n, m; cin >> n >> m;
 map<string, int> notJYsFriend;
 
 for(int i = 0; i < n + m; i++){
     string tmp; cin >> tmp;
     notJYsFriend[tmp]++;
 }
 
 cout << (n + m - notJYsFriend.size()) << endl;
 for(auto name : notJYsFriend){
     if(name.second == 2){
         cout << name.first << endl;
     }
 }
 
 return 0;
}
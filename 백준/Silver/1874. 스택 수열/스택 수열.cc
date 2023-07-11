#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    vector<int> v(n+1, 0);
    stack<int> s;
    
    for(int i = 1; i <= n; i++)
        cin >> v[i];
    
        
    vector<char> ans;
    int j = 1;
    for(int i = 1; i <= n; i++){
        s.push(i);
        ans.push_back('+');
        
        while(!s.empty() && s.top() == v[j]){
            ans.push_back('-');
            s.pop();
            j++;
        }
    }
    
    while(!s.empty() && v[j] == s.top()){
        ans.push_back('-');
        s.pop();
        j++;
    }
    
    if(!s.empty()) cout << "NO";
    else{
        for(char c : ans)
            cout << c << '\n';
    }
    
    return 0;
}
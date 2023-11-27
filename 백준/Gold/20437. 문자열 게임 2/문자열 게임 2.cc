#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 10001
#define MIN 0

int main(){
    int t; cin >> t;
    
    while(t--){
        string w; cin >> w;
        int k; cin >> k;
        
        bool find = false;
        vector<int> alphabet[26];
        for(int i = 0; i < w.length(); i++){
            alphabet[w[i] - 'a'].push_back(i);
            
            find = find || (alphabet[w[i] - 'a'].size() >= k);
        }
        
        if(!find){
            cout << -1 << endl;
            continue;
        }
        
        int s = 10001, l = 0;
        for(int i = 0; i < 26; i++){
            if(alphabet[i].size() < k) continue;
            
            for(int j = k - 1; j < alphabet[i].size(); j++){
                s = min(s, alphabet[i][j] - alphabet[i][j - k + 1] + 1);
                l = max(l, alphabet[i][j] - alphabet[i][j - k + 1] + 1);
            }
        }
        cout << s << " " << l << endl;
    }
    
    return 0;
}
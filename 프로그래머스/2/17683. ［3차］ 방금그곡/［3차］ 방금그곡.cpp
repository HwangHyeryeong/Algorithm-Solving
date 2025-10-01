#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string trans(string s){
    string r;
    for(int i = 0; i < s.size(); i++){
        if(i + 1 < s.size() && s[i + 1] == '#'){
            r.push_back(tolower(s[i]));
            i++;
        } else r.push_back(s[i]);
    }
    return r;
}

string solution(string m, vector<string> musicinfos) {
    m = trans(m);
    string answer = "(None)";
    int mx = 0;
    
    for(auto x : musicinfos){
        int p1 = x.find(','); 
        int p2 = x.find(',',p1+1);
        int p3 = x.find(',',p2+1);
        
        string st = x.substr(0, p1), 
            et = x.substr(p1 + 1, p2 - p1 - 1);
        string name = x.substr(p2+1, p3 - p2 - 1), 
            song = x.substr(p3 + 1);
        
        int sh = stoi(st.substr(0, 2)), sm = stoi(st.substr(3, 2));
        int eh = stoi(et.substr(0, 2)), em = stoi(et.substr(3, 2));
        int t = (eh * 60 + em) - (sh * 60 + sm);
        
        song = trans(song);
        
        string play;
        for(int i = 0; i < t; i++) {
            play.push_back(song[i % song.size()]);
        }
        
        if(play.find(m) != string::npos && t > mx){
            mx = t;
            answer = name;
        }
    }
    return answer;
}

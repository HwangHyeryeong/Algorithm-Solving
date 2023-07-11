#include <iostream>
#include <map>
#include <string>
using namespace std;

int main(){
    int s, p; cin >> s >> p;
    string dna; cin >> dna;
    int pattern[4];
    cin >> pattern[0] >> pattern[1] >> pattern[2] >> pattern[3];
    
    map<char, int> cur;
    cur.insert({'A', 0});
    cur.insert({'C', 0});
    cur.insert({'G', 0});
    cur.insert({'T', 0});
    
    for(int i = 0; i < p; i++){
        if(cur.count(dna[i]))
            cur[dna[i]]++;
        else
            cur[dna[i]] = 1;
    }
    
    int count = 0;
    for(int i = p; i <= dna.size(); i++){
        bool find = true;
        if(pattern[0] > cur['A']) find = false;
        if(pattern[1] > cur['C']) find = false;
        if(pattern[2] > cur['G']) find = false;
        if(pattern[3] > cur['T']) find = false;
        if(find) count++;
        
        if(i < dna.size()){
            cur[dna[i-p]]--;
            cur[dna[i]]++;
        }

    }
    cout << count;
}
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main(){
    int n, like; cin>> n >> like;
    map<int, int> photos; //학생 번호, 추천수
    map<int, int> post; //학생 번호, 추천 시기
    
    for(int i = 0; i < like; i++){
        int student; cin >> student;
        
        if(photos.find(student) != photos.end())
            photos[student]++;
        else if(photos.size() < n){
            photos[student]++;
            post[student] = i;
        }
        else{
            int minNum = 0, minVal = 1001;
            for(auto p : photos){
                if((p.second < minVal) || (p.second == minVal && post[p.first] < post[minNum])){
                    minNum = p.first;
                    minVal = p.second;
                }
            }
            photos.erase(minNum);
            post.erase(minNum);
            photos[student]++;
            post[student] = i;
        }
    }
    
    for(auto s : photos){
        if(s.second != 0)
            cout << s.first << ' ';
    }
    
    return 0;
}
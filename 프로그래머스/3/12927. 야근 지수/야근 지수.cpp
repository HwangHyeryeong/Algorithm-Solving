#include <string>
#include <vector>
#include <queue>
using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    priority_queue<int> q;
    
    for(int w : works)
        q.push(w);
    
    while(n > 0 && !q.empty()){
        if(q.top() == 0) break;        
        q.push(q.top() - 1);
        q.pop();
        n--;
    }
    
    while(!q.empty()){
        int w = q.top(); q.pop();
        answer += (w * w);
    }
    
    return answer;
}
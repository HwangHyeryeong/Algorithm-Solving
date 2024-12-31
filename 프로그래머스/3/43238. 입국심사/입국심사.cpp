#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(int n, vector<int> times) {
    sort(times.begin(), times.end());
    long long l = 1;
    long long r = (long long) n * times[times.size() - 1];

    long long answer = r;
    
    while(l <= r){
        long long m = (l + r) / 2;
        long long total = 0;
                
        for(int time : times){
            total += m / time;
            if(total >= n) break;
        }
        
        if(total >= n){
            answer = m;
            r = m - 1;
        }
        else{
            l = m + 1;
        }
    }
    
    return answer;
}
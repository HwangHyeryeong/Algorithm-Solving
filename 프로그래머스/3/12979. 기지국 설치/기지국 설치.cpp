#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    int cur = 1; // 커버X 지점
    
    for(int s : stations){
        int left = max(1, s - w); // 기지국 왼쪽 범위
        int right = min(n, s + w); // 기지국 오른쪽 범위
        
        // [cur, left-1] 구간 커버
        if(cur < left){
            int len = left - cur;  
            answer += (len + (2*w)) / (2*w + 1);
        }
        
        cur = right + 1;
    }
    
    // 남은 구간 처리
    if(cur <= n){
        int len = n - cur + 1;
        answer += (len + (2*w)) / (2*w + 1);
    }
    
    return answer;
}

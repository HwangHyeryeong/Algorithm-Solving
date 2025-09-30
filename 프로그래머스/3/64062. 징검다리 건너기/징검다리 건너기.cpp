#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool canCross(const vector<int>& stones, int k, int mid) {
    int cnt = 0;
    for (int s : stones) {
        if (s - mid < 0) cnt++;
        else cnt = 0;
        
        if (cnt >= k) return false;
    }
    return true;
}

int solution(vector<int> stones, int k) {
    int left = 1, right = *max_element(stones.begin(), stones.end());
    int answer = 0;
    
    while (left <= right) {
        int mid = (left + right) / 2;
        if (canCross(stones, k, mid)) {
            answer = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return answer;
}

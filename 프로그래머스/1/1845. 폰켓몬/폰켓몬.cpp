#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int solution(vector<int> nums) {
    int answer = 0;
    set<int> s;
    int n = nums.size() / 2;
    
    for(int i : nums)
        s.insert(i);
    
    answer = min(n, (int)s.size());
    
    return answer;
}
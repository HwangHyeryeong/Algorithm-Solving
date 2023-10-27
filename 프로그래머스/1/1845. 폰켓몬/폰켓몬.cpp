#include <vector>
#include <set>
using namespace std;

int solution(vector<int> nums) {
    int answer = 0;
    set<int> s;
    int n = nums.size() / 2;
    
    for(int i : nums)
        s.insert(i);
    
    if(s.size() <= n)
        answer = s.size();
    else
        answer = n;
    
    
    return answer;
}
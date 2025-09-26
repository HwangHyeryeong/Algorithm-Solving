#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> gems) {
    map<string, int> table;
    for (string& g : gems) {
        table[g]++;
    }
    int type = table.size();

    int s = 0, e = 0;
    int rs = 0, re = gems.size() - 1;
    int minLen = gems.size() + 1;
    map<string, int> exist;

    while (e < gems.size()) {
        exist[gems[e]]++;

        // 모든 보석을 다 포함했을 때
        while (exist.size() == type && s <= e) {
            if (e - s < minLen) {
                minLen = e - s;
                rs = s;
                re = e;
            }
            // 시작점 줄이기
            if (--exist[gems[s]] == 0) {
                exist.erase(gems[s]);
            }
            s++;
        }
        e++;
    }

    return {rs + 1, re + 1};
}

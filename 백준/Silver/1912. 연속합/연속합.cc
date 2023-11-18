#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n; cin >> n;

    int sum = -2000, val = 0;
    for (int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        
        val = max(val + tmp, tmp);
        sum = max(val, sum);
    }
    
    cout << sum << endl;
    
    return 0;
}

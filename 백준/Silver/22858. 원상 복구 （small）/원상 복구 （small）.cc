#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

int main(){
    int n, k, num;
    cin >> n >> k;
    
    vector<pair<int, int>> v(n);
    vector<int> d(n);
    
    for (int i = 0; i < n; i++) {
        cin >> num;
        v[i] = { num, i + 1 };
    }
    for (int i = 0; i < n; i++) 
        cin >> d[i];

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) { 
            v[j].second = d[j]; 
        }
        
        sort(v.begin(), v.end(), cmp);
    }

    for (int i = 0; i < n; i++) 
        cout << v[i].first << " ";

    return 0;
}
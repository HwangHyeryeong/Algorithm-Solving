#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int n, m;
vector<int> arr;
set<vector<int>> result;

int main(){
    cin >> n >> m;
    arr = vector<int>(n, 0);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    
    do{
        vector<int> tmp;
        for(int i = 0; i < m; i++){
            tmp.push_back(arr[i]);
        }
        result.insert(tmp);
    }while(next_permutation(arr.begin(), arr.end()));
    
    for(auto s : result){
        for(int i : s){
            cout << i << " ";
        }
        cout << endl;
    }
    
    return 0;
}
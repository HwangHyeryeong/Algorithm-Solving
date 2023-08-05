#include <iostream>

using namespace std;

int main() {
    int n, k; cin >> n >> k;
    int arr[n + 1] = {0};
    
    for(int i = 2; i <= n; i++)
        arr[i] = i;
    
    for(int i = 2; i <= n; i++){
        for(int j = i; j <= n; j+= i){
            if(arr[j]){
                k--;
                arr[j] = 0; //지우기
                if(k == 0) cout << j;
            }
        }
    }
    
    return 0;
}

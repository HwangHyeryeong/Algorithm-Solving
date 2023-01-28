#include <iostream>
using namespace std;

int sugar[5001] = { 0 };

int howManySugarBag(int n) {
    if (n == 3 || n == 5) {
        sugar[n] = 1;
    }
    else if (n == 4 || n == 7) {
        sugar[n] = -1;
    }
    else if (n >= 6) {
        if (n % 5 == 0){
            sugar[n] = (n / 5);
        }
        else if (sugar[n - 3] != -1){
            sugar[n] = howManySugarBag(n - 3) + 1;
        }
    }

    return sugar[n];
}

int main() {
    int n; cin >> n;
    cout << howManySugarBag(n) << endl;

    return 0;
}
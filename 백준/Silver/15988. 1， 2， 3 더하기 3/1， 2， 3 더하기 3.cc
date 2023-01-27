#include <iostream>
#include <vector>
using namespace std;

long long num[1000000] = {0};

long long getNum(int target) {
	if (num[target] == 0) {
		num[1] = 1; num[2] = 2; num[3] = 4;
		for (int i = 4; i <= target; i++) {
			num[i] = (num[i - 3] + num[i - 2] + num[i - 1]) % 1000000009;
		}
	}
	return num[target];
}

int main() {
	int t; cin >> t;
	for (int i = 0; i < t; i++) {
		int n; cin >> n;
		cout << getNum(n) << endl;
	}

	return 0;
}
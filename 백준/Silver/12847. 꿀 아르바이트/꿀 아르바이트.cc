#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n, m; cin >> n >> m;
	
	vector<int> pay(n);
	for (int i = 0; i < n; i++) 
		cin >> pay[i];

	long long sum = 0, maxPay = 0;
	for (int i = 0; i < n; i++) {
		if (i >= m)
			sum -= pay[i - m];
		
		sum += pay[i];
		maxPay = max(sum, maxPay);
	}

	cout << maxPay << endl;

	return 0;
}
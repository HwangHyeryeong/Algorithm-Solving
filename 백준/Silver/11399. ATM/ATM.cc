#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n; cin >> n;
	vector<int> v(n);

	while (n--)
		cin >> v[n];
	sort(v.begin(), v.end());

	int sum = 0, wait = 0;
	for (int i = 0; i < v.size(); i++) {
		wait += v[i];
		sum += wait;
	}

	cout << sum << endl;

	return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, m; cin >> n >> m;
	vector<int> minus;
	vector<int> plus;

	for (int i = 0; i < n; i++) {
		int tmp; cin >> tmp;
		if (tmp > 0)
			plus.push_back(-tmp);
		else
			minus.push_back(tmp);
	}

	sort(plus.begin(), plus.end());
	sort(minus.begin(), minus.end());

	int sum = 0;
	for (int i = 0; i < plus.size(); i += m)
		sum -= plus[i] * 2;

	for (int i = 0; i < minus.size(); i += m)
		sum -= minus[i] * 2;


	if (minus.empty() || (!plus.empty() && (plus[0] < minus[0])))
		sum += plus[0];
	else 
		sum += minus[0];

	cout << sum << endl;

	return 0;
}
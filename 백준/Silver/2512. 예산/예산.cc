#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

	int n; cin >> n;

	vector<long long> government(n);
	for (int i = 0; i < n; i++)
		cin >> government[i];
	
	long long budget; cin >> budget;

	sort(government.begin(), government.end());

	int s = 1, e = government[n - 1], mid = 0;
	long long total = 0;
	while (s <= e) {
		mid = (s + e) / 2;
		total = 0;

		for (int i = 0; i < n; i++) {
			int assign = (government[i] > mid)? mid : government[i];
			total += assign;
		}

		if (total > budget) {
			e = mid - 1;
		}
		else {
			s = mid + 1;
		}
	}
	cout << s - 1 << endl;

	return 0;
}
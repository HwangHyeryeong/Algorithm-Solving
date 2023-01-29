#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

	int n; cin >> n;

	vector<int> locX(n);
	vector<int> copy(n);
	for (int i = 0; i < n; i++) {
		cin >> locX[i];
		copy[i] = locX[i];
	}
	sort(copy.begin(), copy.end());
	copy.erase(unique(copy.begin(), copy.end()), copy.end());

	for (int i = 0; i < n; i++) {
		auto index = lower_bound(copy.begin(), copy.end(), locX[i]);
		cout << index - copy.begin() << " ";
	}

	return 0;
}
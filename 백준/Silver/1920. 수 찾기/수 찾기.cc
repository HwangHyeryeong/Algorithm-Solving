#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> a;

void searchNum(int target) {
	int start = 0, end = (n - 1), mid = 0;

	while (start <= end) {
		mid = (start + end) / 2;

		if (a[mid] == target){
			cout << "1\n";
			return;
		}
		else {
			if (a[mid] > target) {
				end = mid - 1;
			}
			else {
				start = mid + 1;
			}
		}
	}
	cout << "0\n";
	return;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp; cin >> tmp;
		a.push_back(tmp);
	}
	sort(a.begin(), a.end());

	int m; cin >> m;
	for (int i = 0; i < m; i++) {
		int tmp; cin >> tmp;

		if (tmp > a[a.size() - 1] || tmp < a[0])
			cout << "0\n";
		else
			searchNum(tmp);
	}

	return 0;
}
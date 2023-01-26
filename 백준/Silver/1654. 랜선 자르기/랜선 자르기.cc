#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> line;

int main() {
	int k, n;
	cin >> k >> n;
	
	for (int i = 0; i < k; i++){
		long long tmp; cin >> tmp;
		line.push_back(tmp);
	}
	sort(line.begin(), line.end());

	long long start = 1, end = line[k - 1], mid = 0;
	int answer = 0;
	while (start <= end) {
		int numOfLine = 0;
		mid = (start + end) / 2;

		for (int i = 0; i < k; i++) {
			numOfLine += (line[i] / mid);
		}

		if (numOfLine < n) {
			end = mid - 1;
		}
		else {
			start = mid + 1;
			if (answer < mid)
				answer = mid;
		}
	}

	cout << answer << endl;

	return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n; cin >> n;
	vector<int> numbers(n);
	for (int i = 0; i < n; i++) {
		cin >> numbers[i];
	}
	sort(numbers.begin(), numbers.end());

	int count = 0;
	for (int i = 0; i < n; i++) {
		int s = 0, e = n - 1;
		while (s < e) {
			if (numbers[s] + numbers[e] < numbers[i]) s++;
			else if(numbers[s] + numbers[e] > numbers[i]) e--;
			else {
				if (s != i && e != i) {
					count++;
					break;
				}
				else if (s == i) s++;
				else if (e == i) e--;
			}
		}
	}

	cout << count << endl;

	return 0;
}
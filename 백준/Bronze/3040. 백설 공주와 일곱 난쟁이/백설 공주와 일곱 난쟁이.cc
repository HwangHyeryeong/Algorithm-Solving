#include <iostream>
using namespace std;

int nums[9], ans[7] = { 0 };
int sum = 0, r = 7;
bool isFind = false;

void DFS(int depth, int start) {
	if (depth == r) {
		if (sum == 100)
			isFind = true;

		return;
	}
	for (int i = start; i < 9; i++) {
		ans[depth] = nums[i];
		sum += nums[i];
		DFS(depth + 1, i + 1);
		if (isFind) return;
		sum -= nums[i];
	}
}

int main() {
	for (int i = 0; i < 9; i++) {
		cin >> nums[i];
	}
	DFS(0, 0);
	for (auto i : ans)
		cout << i << endl;

	return 0;
}
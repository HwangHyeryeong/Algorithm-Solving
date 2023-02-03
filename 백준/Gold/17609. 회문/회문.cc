#include <iostream>
#include <string>

using namespace std;

string target;

int isPalindrome(int s, int e, int differ) {
	while (s < e) {
		if (target[s] != target[e]) {
			if (differ == 0) {
				if (!isPalindrome(s + 1, e, 1) || !isPalindrome(s, e - 1, 1))
					return 1;
				else
					return 2;
			}
			else
				return 2;
		}
		else {
			s++;
			e--;
		}
	}
	return 0;
}

int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> target;
		cout << isPalindrome(0, target.size()-1, 0) << "\n";
	}

	return 0;
}
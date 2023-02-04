#include <iostream>
#include <string>
using namespace std;

int main() {
	while (true) {
		string n; cin >> n;
		
		if (n == "0") {
			break;
		}
		
		int s = 0, e = n.size() - 1;
		bool isPalinedrom = true;
		while (s < e) {
			if (n[s] != n[e]){
				isPalinedrom = false;
				break;
			}
			else {
				s++; e--;
			}
		}
		if (isPalinedrom)
			cout << "yes\n";
		else
			cout << "no\n";
	}

	return 0;
}
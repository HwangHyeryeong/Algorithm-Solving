#include <iostream>
using namespace std;

long long site[31][31] = { 0 };

void calcCombination() {
	for(int i = 0; i < 31; i++)
		for (int j = 0; j <= i; j++) {
			if (j == 0 || i == j) {
				site[i][j] = 1;
			}
			else if (j == 1) {
				site[i][j] = i;
			}
			else {
				if (i < j)
					j -= i;

				site[i][j] = site[i - 1][j - 1] + site[i - 1][j];
			}
		}
}

int main() {
	int t; cin >> t;
	
	calcCombination();

	for (int i = 0; i < t; i++) {
		int n, m; cin >> n >> m;
		cout << site[m][n] << endl;
	}

	return 0;
}
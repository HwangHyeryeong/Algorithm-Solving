#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

	int n; cin >> n;
	vector<int> wine(n+1, 0);
	vector<int> drunk(n+1, 0);

	for (int i = 1; i <= n; i++) 
		cin >> wine[i];

	drunk[1] = wine[1];
	drunk[2] = wine[1] + wine[2];
	for (int i = 3; i <= n; i++)
		drunk[i] = max({ drunk[i - 1], drunk[i - 2] + wine[i], drunk[i - 3] + wine[i - 1] + wine[i] });
	
	cout << drunk[n] << endl;

	return 0;
}

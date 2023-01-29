#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

	int n; cin >> n;
	
	map<int, int> x;
	vector<int> locX;
	for (int i = 0; i < n; i++) {
		int tmp; cin >> tmp;
		locX.push_back(tmp);
		x.insert({tmp, -1});
	}

	int order = 0;
	for (auto i : x) {
		i.second = order;
		x[i.first] = order;
		order++;

	}
	
	for (int i = 0; i < n; i++) {
		cout << x[locX[i]] << " ";
	}

	return 0;	
}
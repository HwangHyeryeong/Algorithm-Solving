#include <iostream>
#include <vector>
using namespace std;

vector<int> tree[51];
bool visited[51] = { 0 };

void getNumOfLeaf(int top, int del, int& count) {
	if (visited[top] || top == del) return;
	
	visited[top] = true;

	//자식노드인 경우
	if (tree[top].size() == 0){
		count++;
		return;
	}

	//dfs
	for (int i = 0; i < tree[top].size(); i++) {
		int x = tree[top][i];
		if (!visited[x] && x != del)
			getNumOfLeaf(x, del, count);
		else if (x == del && tree[top].size() == 1)
			count++;
	}
}

int main() {
	int n;
	cin >> n;

	int top = -1;
	for (int i = 0; i < n; i++) {
		int parent; cin >> parent;
		if (parent == -1)
			top = i;
		else
			tree[parent].push_back(i);
	}

	int del; cin >> del;
	int count = 0;
	getNumOfLeaf(top, del, count);
	cout << count << '\n';

	return 0;
}
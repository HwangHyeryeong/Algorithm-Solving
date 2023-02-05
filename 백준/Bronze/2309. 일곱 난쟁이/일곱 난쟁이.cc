#include <iostream>
#include <algorithm>
using namespace std;

int tall[9] = { 0 };

int main() {
	int sum = 0;
	for (int i = 0; i < 9; i++) {
		cin >> tall[i];
		sum += tall[i];
	}
	sort(tall, tall + 9);
	
	int del1, del2;
	for (int i = 0; i < 8; i++) {
		for (int j = i + 1; j < 9; j++) {
			if (sum - (tall[i] + tall[j]) == 100) {
				del1 = i; del2 = j;
				break;
			}
		}
	}

	for (int i = 0; i < 9; i++) {
		if (i != del1 && i != del2)
			cout << tall[i] << endl;
	}

	return 0;
}
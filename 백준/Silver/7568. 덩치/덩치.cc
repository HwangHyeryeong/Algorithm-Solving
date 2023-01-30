#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;//사람 수
	if (N < 2 || N  > 50) return 0;

	int** group = new int*[N];
	for (int i = 0; i < N; i++){
		group[i] = new int[3]; // N * 3 동적 할당
		cin >> group[i][0] >> group[i][1]; //몸무게 키 입력
		group[i][2] = 1;
	}

	for (int i = 0; i < N - 1; i++) {
		for (int j = i + 1; j < N; j++) {
			if (group[i][0] > group[j][0] && group[i][1] > group[j][1]) {
				group[j][2]++;
			}
			else if(group[i][0] < group[j][0] && group[i][1] < group[j][1])
				group[i][2]++;	
		}
	}

	for (int i = 0; i < N; i++) {
		cout << group[i][2] << " ";
	}

	return 0;
}
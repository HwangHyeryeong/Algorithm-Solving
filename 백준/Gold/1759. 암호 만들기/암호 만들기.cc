#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int L, C;

// conso : 자음 개수, vowel : 모음 개수
void dfs(vector<char> v, int now, string str, int consonant, int vowel){
	str.push_back(v[now]);
	
	if(v[now] == 'a' || v[now] == 'e' || v[now] == 'i' || v[now] == 'o' || v[now] == 'u')
		vowel++;
	else consonant++;

	if(str.length() == L){
		if(vowel >= 1 && consonant >= 2)
			cout << str << '\n';
		return;
	}

	for(int i = now + 1; i < C; i++)
		dfs(v, i, str, consonant, vowel);
	return;
}

int main(){
	cin >> L >> C;
	vector<char> v(C);

	for(int i = 0; i < C; i++)
		cin >> v[i];		
	
	sort(v.begin(), v.end());

	for(int i = 0; i <= C - L; i++)
		dfs(v, i, "", 0, 0);

	return 0;
}
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t; cin >> t;

    while (t--) {
        string w; cin >> w;
        int k; cin >> k;

        bool isFound = false;
        vector<int> alphabet[26];
        for (int i = 0; i < w.length(); i++) {
            alphabet[w[i] - 'a'].push_back(i);
            isFound = isFound || (alphabet[w[i] - 'a'].size() >= k);
        }

        if (!isFound) cout << -1 << endl;
        else {
            int shortest = 10001, longest = 0;
            for (int i = 0; i < 26; i++) {
                int size = alphabet[i].size();
                if (size >= k) {
                    for (int j = 0; j <= size - k; j++) {
                        shortest = min(shortest, alphabet[i][j + k - 1] - alphabet[i][j] + 1);
                        longest = max(longest, alphabet[i][j + k - 1] - alphabet[i][j] + 1);
                    }
                }
            }

            cout << shortest << " " << longest << endl;
        }
    }

    return 0;
}

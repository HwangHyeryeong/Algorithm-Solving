#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int box[1000][1000] = {0};
int dx[] = { 0, -1, 0, 1 };
int dy[] = { -1, 0, 1, 0 };
queue < pair<int, int>> q;//y, x

bool valid (int y, int x) {
    if (y < 0 || y >= n || x < 0 || x >= m)
        return false;

    return true;
}

void bfs () {
    while (!q.empty()) {
        int curY = q.front ().first;
        int curX = q.front ().second;
        q.pop ();

        for (int i = 0; i < 4; i++) {
            int nextY = curY + dy[i];
            int nextX = curX + dx[i];
            
	        if (valid(nextY, nextX) && (box[nextY][nextX] == 0)) {
	            box[nextY][nextX] = box[curY][curX] + 1;
	            q.push ({nextY, nextX});
	        }
	    }
    }
}

int main () {
    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> box[i][j];
            if (box[i][j] == 1)
	            q.push ({i, j});
	    }
    }

    bfs ();

    int result = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (box[i][j] == 0) {
                cout << -1;
                return 0;
            }
            result = max (result, box[i][j]);
        }
    }

    cout << result - 1;

  return 0;
}

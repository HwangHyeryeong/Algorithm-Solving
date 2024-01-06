#include <iostream>
#include <vector>
using namespace std;

int winner = 0;
int x = 0, y = 0;
int board[20][20] = {0};

int dx[] = {1, 0, 1, -1};
int dy[] = {0, 1, 1, 1};

bool search(int i, int j) {
    int focus = board[i][j];

    for (int k = 0; k < 4; ++k) {
        int cnt = 1;
        int nx = i + dx[k];
        int ny = j + dy[k];

        while (0 <= nx && nx < 19 && 0 <= ny && ny < 19 && board[nx][ny] == focus) {
            cnt++;

            if (cnt == 5) {
                if (0 <= i - dx[k] && i - dx[k] < 19 && 0 <= j - dy[k] && j - dy[k] < 19 && board[i - dx[k]][j - dy[k]] == focus)
                    break;
                if (0 <= nx + dx[k] && nx + dx[k] < 19 && 0 <= ny + dy[k] && ny + dy[k] < 19 && board[nx + dx[k]][ny + dy[k]] == focus)
                    break;

                winner = focus;
                x = j;
                y = i;
                return true;
            }

            nx += dx[k];
            ny += dy[k];
        }
    }

    return false;
}

int main() {
    for (int i = 0; i < 19; ++i) {
        for (int j = 0; j < 19; ++j)
            cin >> board[i][j];
    }

    for (int i = 0; i < 19; ++i) {
        for (int j = 0; j < 19; ++j) {
            if (board[i][j] != 0 && search(i, j)) {
                cout << winner << "\n" << y + 1 << " " << x + 1;
                return 0;
            }
        }
    }

    cout << 0;
    return 0;
}

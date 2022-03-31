/*
ID: aleksil1
TASK: maze1
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ifstream fin("maze1.in");
ofstream fout("maze1.out");
int H, W;
char maze[201][78];
bool visited[100][38]{};

int main() {
    fin >> W >> H;
    fin.get();
    int x, y;
    deque<pair<int, int>> q;
    fill_n((char *) maze, 201 * 77, ' ');
    for (int i = 0; i < H * 2 + 1; ++i) {
        fin.getline(maze[i], 78);
        for (int j = 0; j < W * 2 + 1; ++j) {
            if (maze[i][j] == ' ') {
                if (i == 0) {
                    x = 0, y = j / 2;
                } else if (i == H * 2) {
                    x = H - 1, y = j / 2;
                } else if (j == 0) {
                    x = i / 2, y = 0;
                } else if (j == W * 2) {
                    x = i / 2, y = W - 1;
                } else {
                    continue;
                }
                visited[x][y] = true;
                q.emplace_back(x, y);
            }
        }
    }
    for (int d = 1;; ++d) {
        for (int k = 0, len = q.size(); k < len; ++k) {
            tie(x, y) = q.front();
            q.pop_front();
            if (x > 0 && !visited[x - 1][y] && maze[x * 2][y * 2 + 1] == ' ') {
                visited[x - 1][y] = true;
                q.emplace_back(x - 1, y);
            }
            if (x < H - 1 && !visited[x + 1][y] && maze[x * 2 + 2][y * 2 + 1] == ' ') {
                visited[x + 1][y] = true;
                q.emplace_back(x + 1, y);
            }
            if (y > 0 && !visited[x][y - 1] && maze[x * 2 + 1][y * 2] == ' ') {
                visited[x][y - 1] = true;
                q.emplace_back(x, y - 1);
            }
            if (y < W - 1 && !visited[x][y + 1] && maze[x * 2 + 1][y * 2 + 2] == ' ') {
                visited[x][y + 1] = true;
                q.emplace_back(x, y + 1);
            }
        }
        if (q.empty()) {
            fout << d << endl;
            break;
        }
    }
    return 0;
}


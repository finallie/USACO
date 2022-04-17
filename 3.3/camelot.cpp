/*
ID: aleksil1
TASK: camelot
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;

int R, C, kr, kc;
using Knight = struct Knight {
    int r, c;
};
vector<Knight> knights;
int dist[30][26][30][26];
int dir[8][2]{
        {1, 2},
        {1, -2},
        {-1, 2},
        {-1, -2},
        {2, 1},
        {2, -1},
        {-2, 1},
        {-2, -1},
};

int dist_to_king(int r, int c) {
    return max(abs(kr - r), abs(kc - c));
}

bool is_valid(int r, int c) {
    return r >= 0 && r < R && c >= 0 && c < C;
}

deque<pair<int, int>> q;

void bfs(int r, int c) {
    dist[r][c][r][c] = 0;
    q.emplace_back(r, c);
    for (int d = 1; !q.empty(); ++d) {
        for (size_t i = 0, size = q.size(); i < size; ++i) {
            int cur_r, cur_c;
            tie(cur_r, cur_c) = q.front();
            q.pop_front();
            for (int j = 0; j < 8; ++j) {
                int new_r = cur_r + dir[j][0], new_c = cur_c + dir[j][1];
                if (is_valid(new_r, new_c) && dist[r][c][new_r][new_c] == -1) {
                    dist[r][c][new_r][new_c] = d;
                    q.emplace_back(new_r, new_c);
                }
            }
        }
    }
}


int main() {
    ifstream fin("camelot.in");
    ofstream fout("camelot.out");

    char c;
    int r;
    fin >> R >> C >> c >> r;
    kc = c - 'A';
    kr = r - 1;
    while (fin >> c >> r) {
        knights.push_back({r - 1, c - 'A'});
    }
    if (knights.empty()) {
        fout << 0 << endl;
        return 0;
    }

    fill_n((int *) dist, sizeof(dist) / sizeof(int), -1);
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            bfs(i, j);
        }
    }

    int ans = INT_MAX;
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            int sum=0;
            int mn = INT_MAX;
            for (const auto &knight: knights) {
                sum += dist[knight.r][knight.c][i][j];
                for (int x = 0; x < R; ++x) {
                    for (int y = 0; y < C; ++y) {
                        mn = min(mn, dist[knight.r][knight.c][x][y] + dist[x][y][i][j] + dist_to_king(x, y) -
                                     dist[knight.r][knight.c][i][j]);
                    }
                }
            }
            ans = min(ans, sum + mn);
        }
    }
    fout << ans << endl;

    return 0;
}


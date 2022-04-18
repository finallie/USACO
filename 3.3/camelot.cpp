/*
ID: aleksil1
TASK: camelot
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;

int R, C, kr, kc, INF = INT_MAX / 2;
using Knight = struct Knight {
    int r, c;
};
vector<Knight> knights;
int kdist[30][26], in_quene[2][30][26], cost[2][30][26], sum[30][26], mn[30][26];
int dir[8][2]{
        {1,  2},
        {1,  -2},
        {-1, 2},
        {-1, -2},
        {2,  1},
        {2,  -1},
        {-2, 1},
        {-2, -1},
};

int dist_to_king(int r, int c) {
    return max(abs(kr - r), abs(kc - c));
}

bool is_valid(int r, int c) {
    return r >= 0 && r < R && c >= 0 && c < C;
}

deque<tuple<int, int, int>> q;

void relax(int with_king, int r, int c, int d) {
    if (cost[with_king][r][c] > d) {
        cost[with_king][r][c] = d;
        if (!in_quene[with_king][r][c]) {
            in_quene[with_king][r][c] = 1;
            q.emplace_back(with_king, r, c);
        }
    }
}

void bfs(int r, int c) {
    fill_n((int *) cost, 2 * 30 * 26, INF);
    relax(0, r, c, 0);
    while (!q.empty()) {
        int with_king;
        tie(with_king, r, c) = q.front();
        q.pop_front();
        in_quene[with_king][r][c] = 0;
        if (!with_king) {
            relax(1, r, c, kdist[r][c] + cost[0][r][c]);
        }
        for (int i = 0; i < 8; ++i) {
            int x = r + dir[i][0], y = c + dir[i][1];
            if (is_valid(x, y)) {
                relax(with_king, x, y, cost[with_king][r][c] + 1);
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
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            kdist[i][j] = dist_to_king(i, j);
        }
    }
    int knight_count = 0;
    fill_n((int *) mn, 30 * 26, INF);
    while (fin >> c >> r) {
        ++knight_count;
        bfs(r - 1, c - 'A');
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                if (sum[i][j] == INF || cost[0][i][j] == INF) {
                    sum[i][j] = INF;
                } else {
                    sum[i][j] += cost[0][i][j];
                }
                mn[i][j] = min(mn[i][j], cost[1][i][j] - cost[0][i][j]);
            }
        }
    }
    if (!knight_count) {
        fout << 0 << endl;
        return 0;
    }
    int ans = INT_MAX;
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            ans = min(ans, sum[i][j] + mn[i][j]);
        }
    }
    fout << ans << endl;

    return 0;
}


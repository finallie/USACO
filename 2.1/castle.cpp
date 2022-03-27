/*
ID: aleksil1
TASK: castle
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;

int M, N;
int wall[50][50]{};
int component[50][50]{};
int dir[4][2]{{0,  -1},
              {-1, 0},
              {0,  1},
              {1,  0}};
char dir_name[4] = {'W', 'N', 'E', 'S'};
vector<int> component_size{0};

void dfs(int n, int m, int num) {
    component[n][m] = num;
    component_size[num]++;
    for (int i = 0; i < 4; ++i) {
        if (!(wall[n][m] & (1 << i)) && component[n + dir[i][0]][m + dir[i][1]] == 0)
            dfs(n + dir[i][0], m + dir[i][1], num);
    }
}

int main() {
    ifstream fin("castle.in");
    ofstream fout("castle.out");
    fill_n((char *) wall, 2500, 15);
    fin >> M >> N;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            fin >> wall[i][j];
    int component_num = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (component[i][j] == 0) {
                component_size.push_back(0);
                dfs(i, j, ++component_num);
            }
        }
    }
    fout << component_num << endl;
    fout << *max_element(begin(component_size), end(component_size)) << endl;

    int max_size = 0, wall_i = 0, wall_j = 0;
    char wall_dir = ' ';
    for (int j = 0; j < M; ++j) {
        for (int i = N - 1; i >= 0; --i) {
            for (int d = 0; d < 4; ++d) {
                if (wall[i][j] & (1 << d)) {
                    int i2 = i + dir[d][0], j2 = j + dir[d][1];
                    if (i2 < 0 || i2 >= N || j2 < 0 || j2 >= M) continue;
                    if (component[i][j] != component[i2][j2]) {
                        int t = component_size[component[i][j]] + component_size[component[i2][j2]];
                        if (t > max_size) {
                            max_size = t;
                            wall_i = i;
                            wall_j = j;
                            wall_dir = dir_name[d];
                        }
                    }
                }
            }
        }
    }
    fout << max_size << endl;
    fout << wall_i + 1 << ' ' << wall_j + 1 << ' ' << wall_dir << endl;
    return 0;
}


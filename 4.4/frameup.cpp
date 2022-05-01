/*
ID: aleksil1
TASK: frameup
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
int H, W, frame[30][30];
int north[128], sourth[128], west[128], east[128], gragh[128][128], frame_size, visited[128];
set<int> chars;

ifstream fin("frameup.in");
ofstream fout("frameup.out");

struct degree {
    int in;
    vector<int> out;
} degrees[128];

void print_answer(string s) {
    if (s.size() == frame_size) {
        fout << s << '\n';
        return;
    }
    for (const auto &c: chars) {
        if (degrees[c].in == 0 && !visited[c]) {
            for (const auto &i: degrees[c].out) {
                --degrees[i].in;
            }
            visited[c] = 1;
            print_answer(s + (char) c);
            for (const auto &i: degrees[c].out) {
                ++degrees[i].in;
            }
            visited[c] = 0;
        }
    }
}

int main() {


    fill_n(begin(north), 128, INT_MAX);
    fill_n(begin(west), 128, INT_MAX);
    fin >> H >> W;
    fin.get();
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            frame[i][j] = fin.get();
            if (frame[i][j] != '.') {
                north[frame[i][j]] = min(north[frame[i][j]], i);
                west[frame[i][j]] = min(west[frame[i][j]], j);
                sourth[frame[i][j]] = max(sourth[frame[i][j]], i);
                east[frame[i][j]] = max(east[frame[i][j]], j);
                chars.insert(frame[i][j]);
            }
        }
        fin.get();
    }
    frame_size = chars.size();

    for (const auto c: chars) {
        for (int i = north[c]; i <= sourth[c]; ++i) {
            if (frame[i][west[c]] != '.' && frame[i][west[c]] != c) {
                gragh[c][frame[i][west[c]]] = 1;
            }
            if (frame[i][east[c]] != '.' && frame[i][east[c]] != c) {
                gragh[c][frame[i][east[c]]] = 1;
            }
        }
        for (int i = west[c] + 1; i < east[c]; ++i) {
            if (frame[north[c]][i] != '.' && frame[north[c]][i] != c) {
                gragh[c][frame[north[c]][i]] = 1;
            }
            if (frame[sourth[c]][i] != '.' && frame[sourth[c]][i] != c) {
                gragh[c][frame[sourth[c]][i]] = 1;
            }
        }
    }

    for (const auto &i: chars) {
        for (const auto &j: chars) {
            if (gragh[i][j]) {
                ++degrees[j].in;
                degrees[i].out.push_back(j);
            }
        }
    }

    print_answer("");
    fout << flush;
    return 0;
}


/*
ID: aleksil1
TASK: game1
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;

int N;
int board[100], dp[2][100];

int main() {
    ifstream fin("game1.in");
    ofstream fout("game1.out");

    fin >> N;
    for (int i = 0; i < N; ++i) {
        fin >> board[i];
    }
    copy(board, board + N, dp[0]);
    for (int n = 2; n <= N; ++n) {
        for (int i = 0; i <= N - n; ++i) {
            if (board[i] + dp[1][i + 1] > board[i + n - 1] + dp[1][i]) {
                tie(dp[0][i], dp[1][i]) = make_tuple(board[i] + dp[1][i + 1], dp[0][i + 1]);
            } else {
                tie(dp[0][i], dp[1][i]) = make_tuple(board[i + n - 1] + dp[1][i], dp[0][i]);
            }
        }
    }
    fout << dp[0][0] << ' ' << dp[1][0] << endl;
    return 0;
}


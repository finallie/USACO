/*
ID: aleksil1
TASK: shopping
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;

struct Offer {
    int n;
    int price;
    int code[5];
    int count[5];
} offers[99];
int s, b, code[1000], price[5], k[5], dp[6][6][6][6][6];

int main() {
    ifstream fin("shopping.in");
    ofstream fout("shopping.out");

    fin >> s;
    for (int i = 0; i < s; ++i) {
        fin >> offers[i].n;
        for (int j = 0; j < offers[i].n; ++j) {
            fin >> offers[i].code[j];
            fin >> offers[i].count[j];
        }
        fin >> offers[i].price;
    }
    fin >> b;
    if (b == 0) {
        fout << 0 << endl;
        return 0;
    }
    for (int i = 0, t; i < b; ++i) {
        fin >> t;
        code[t] = i;
        fin >> k[i] >> price[i];
    }

    for (int a = 0; a <= k[0]; ++a) {
        for (int b = 0; b <= k[1]; ++b) {
            for (int c = 0; c <= k[2]; ++c) {
                for (int d = 0; d <= k[3]; ++d) {
                    for (int e = 0; e <= k[4]; ++e) {
                        dp[a][b][c][d][e] = a * price[0] + b * price[1] + c * price[2] + d * price[3] + e * price[4];
                        for (int i = 0; i < s; ++i) {
                            int t[5]{};
                            for (int j = 0; j < offers[i].n; ++j) {
                                t[code[offers[i].code[j]]] = offers[i].count[j];
                            }
                            if (t[0] > a || t[1] > b || t[2] > c || t[3] > d || t[4] > e) continue;
                            dp[a][b][c][d][e] = min(dp[a][b][c][d][e], offers[i].price +
                                                                       dp[a - t[0]][b - t[1]][c - t[2]][d - t[3]][e -
                                                                                                                  t[4]]);
                        }
                    }
                }
            }
        }
    }

    fout << dp[k[0]][k[1]][k[2]][k[3]][k[4]] << endl;

    return 0;
}


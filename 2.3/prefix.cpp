/*
ID: aleksil1
TASK: prefix
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ifstream fin("prefix.in");
ofstream fout("prefix.out");

struct TrieNode {
    struct TrieNode *children[26]{};
    int len{};
};

void insert(struct TrieNode *root, string s) {
    for (char c: s) {
        auto &p = root->children[c - 'A'];
        if (!p)
            p = new struct TrieNode;
        root = p;
    }
    root->len = s.size();
}

int main() {
    string s, S;
    auto root = new struct TrieNode;
    while (fin >> s) {
        if (s[0] == '.')
            break;
        insert(root, s);
    }
    while (fin >> s)
        S += s;
    vector<bool> dp(S.size() + 1);
    dp[0] = true;
    int ans = 0;
    for (int i = 0; i <= ans; ++i) {
        if (!dp[i]) continue;
        auto p = root;
        for (int j = i; j < S.size(); ++j) {
            p = p->children[S[j] - 'A'];
            if (!p) break;
            if (p->len) {
                dp[i + p->len] = true;
                ans = max(ans, i + p->len);
            }
        }
    }
    fout << ans << endl;
    return 0;
}


/*
ID: aleksil1
TASK: lgame
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
int value[26]{
        2, 5, 4, 4, 1, 6, 5,
        5, 1, 7, 6, 3, 5, 2,
        3, 5, 7, 2, 1, 2,
        4, 6, 6, 7, 5, 7
}, l_count[26], l_num, ans;
vector<string> word, line;

bool valid(const string &s) {
    if (s.size() > l_num) return false;
    int t[26]{};
    for (char c: s)
        if (++t[c - 'a'] > l_count[c - 'a'])
            return false;
    return true;
}

int score(const string &s) {
    int sum = 0;
    for (char c: s)
        sum += value[c - 'a'];
    return sum;
}

int main() {
    ifstream fin("lgame.in");
    ifstream fdic("lgame.dict");
    ofstream fout("lgame.out");

    string s;
    fin >> s;
    l_num = s.size();
    for (char c: s)
        ++l_count[c - 'a'];
    while (fdic >> s) {
        if (s == ".") break;
        if (valid(s)) {
            int sc = score(s);
            if (sc > ans) {
                ans = sc;
                line.clear();
                line.emplace_back(s);
            } else if (sc == ans) {
                line.emplace_back(s);
            }
            word.push_back(s);
        }
    }

    std::sort(word.begin(), word.end());
    for (int i = 0; i < word.size(); ++i) {
        for (int j = i + 1; j < word.size(); ++j) {
            if (valid(word[i] + word[j])) {
                int sc = score(word[i]) + score(word[j]);
                if (sc > ans) {
                    ans = sc;
                    line.clear();
                    line.emplace_back(word[i] + ' ' + word[j]);
                } else if (sc == ans) {
                    line.emplace_back(word[i] + ' ' + word[j]);
                }
            }
        }
    }

    std::sort(line.begin(), line.end());
    fout << ans << endl;
    for (const string &t: line)
        fout << t << endl;
    return 0;
}


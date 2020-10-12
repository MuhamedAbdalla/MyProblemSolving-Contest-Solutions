#include <bits/stdc++.h>

using namespace std;

const int N = 2e2 + 5;
long long dp[N][N][N];
int n, k;
string s, t;
vector<char> v;

long long solve(int l, int c, int k) {
    if (l == n) {
        return 0;
    }
    long long &re = dp[l][c][k];
    if (re != -1) return re;
    re = 0;
    if (s[l] == v[0])
        re = solve(l + 1, c + 1, k) + ((v[0] == v[1]) ? c : 0);
    else if (s[l] == v[1])
        re = solve(l + 1, c + ((v[0] == v[1]) ? 1 : 0), k) + c;
    else
        re = solve(l + 1, c, k);
    if (s[l] != v[0] && k > 0) {
        re = max(re, solve(l + 1, c + 1, k - 1) + ((v[0] == v[1]) ? c : 0));
    }
    if (s[l] != v[1] && k > 0) {
        re = max(re, solve(l + 1, c + ((v[0] == v[1]) ? 1 : 0), k - 1) + c);
    }
    return re;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen("D.txt", "r", stdin);
    cin >> n >> k >> s >> t;
    v.push_back(t[0]), v.push_back(t[1]);
    memset(dp, -1, sizeof(dp));
    cout << solve(0, 0, k) << endl;
    return 0;
}

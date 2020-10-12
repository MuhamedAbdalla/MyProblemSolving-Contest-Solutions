#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen("D.txt", "r", stdin);
    long long a, b, c;
    cin >> a >> b >> c;
    vector<long long> x, y, z;
    x.push_back(0), y.push_back(0), z.push_back(0);
    for (int i = 0; i < a; i++) {
        long long u;
        cin >> u;
        x.push_back(u);
    }
    for (int i = 0; i < b; i++) {
        long long u;
        cin >> u;
        y.push_back(u);
    }
    for (int i = 0; i < c; i++) {
        long long u;
        cin >> u;
        z.push_back(u);
    }
    long long dp[a + 5][b + 5][c + 5];
    memset(dp, 0, sizeof(dp));
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    sort(z.begin(), z.end());
    for (int i = a; i >= 0; i--) {
        for (int j = b; j >= 0; j--) {
            for (int k = c; k >= 0; k--) {
                if (j < b && k < c)
                    dp[i][j][k] = max(dp[i][j][k], dp[i][j + 1][k + 1] + z[k + 1] * y[j + 1]);
                if (i < a && k < c)
                    dp[i][j][k] = max(dp[i][j][k], dp[i + 1][j][k + 1] + x[i + 1] * z[k + 1]);
                if (i < a && j < b)
                    dp[i][j][k] = max(dp[i][j][k], dp[i + 1][j + 1][k] + x[i + 1] * y[j + 1]);
            }
        }
    }
    long long res = 0;
    for (int i = 0; i < a; i++) res = max(res, dp[i][0][0]);
    for (int i = 0; i < b; i++) res = max(res, dp[0][i][0]);
    for (int i = 0; i < c; i++) res = max(res, dp[0][0][i]);
    cout << res << endl;
    return 0;
}

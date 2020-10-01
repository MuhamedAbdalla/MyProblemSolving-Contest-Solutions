#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5, MOD = 1e9 + 7;
int t, n, dp[N], cnt[N];

void init() {
    for (int i = 0; i <= n; i++) {
        dp[i] = 0;
        cnt[i] = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen("D.txt", "r", stdin);
    cin >> t;
    while (t--) {
        cin >> n;
        int a[n + 1];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            dp[i] = cnt[i] = 1;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++){
                if (a[j] < a[i]) {
                    if (dp[i] == dp[j] + 1) {
                        cnt[i] = (cnt[i] % MOD + cnt[j] % MOD) % MOD;
                    }
                    else if (dp[i] < dp[j] + 1) {
                        dp[i] = dp[j] + 1;
                        cnt[i] = cnt[j];
                    }
                }
            }
        }
        int mx = -1, c = 0;
        for (int i = 0; i < n; i++) {
            if (dp[i] > mx) {
                mx = dp[i];
                c = cnt[i];
            }
            else if (dp[i] == mx) {
                c = (c % MOD + cnt[i] % MOD) % MOD;
            }
        }
        cout << mx << " " << c << endl;
        init();
    }
    return 0;
}

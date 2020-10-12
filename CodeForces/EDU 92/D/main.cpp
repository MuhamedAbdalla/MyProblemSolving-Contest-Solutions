#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen("D.txt", "r", stdin);
    long long t;
    cin >> t;
    while (t--) {
        long long n, k;
        cin >> n >> k;
        long long a, b, c, d;
        cin >> a >> b >> c >> d;
        if (max(c, a) <= min(b, d)) {
            k -= n * abs(max(c, a) - min(b, d));
        }
        if (k <= 0) {
            cout << 0 << endl;
            continue;
        }
        long long res = 2e18;
        for (long long i = 1; i <= n; i++) {
            long long ans = 0, cur = 0;
            if (min(b, d) < max(a, c)) {
                cur += (max(a, c) - min(b, d)) * i;
            }
            ans += (max(b, d) - min(a, c)) * i;
            ans -= max(0LL, (min(b, d) - max(a, c)) * i);
            if (ans >= k) {
                res = min(res, cur + k);
            }
            else {
                long long remK = k - ans;
                res = min(res, ans + cur + 2 * remK);
            }
        }
        cout << res << endl;
    }
    return 0;
}

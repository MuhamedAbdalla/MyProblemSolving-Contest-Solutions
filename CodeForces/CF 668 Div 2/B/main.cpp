#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n + 5];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        long long s = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] >= 0) {
                s += a[i];
            }
            else {
                long long dif = min(s, abs(1LL * a[i]));
                a[i] += dif;
                s -= dif;
            }
        }
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] < 0) {
                ans += abs(a[i]);
            }
        }
        cout << ans << endl;
    }
    return 0;
}


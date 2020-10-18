#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    long long ans = 0;
    cin >> n;
    int a[n + 5][n + 5];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        long long s = 0;
        int k = i, j = 0;
        while (k < n && j < n) {
            s += a[k][j];
            k++, j++;
        }
        ans = max(ans, s);
    }
    for (int i = 1; i < n; i++) {
        long long s = 0;
        int k = 0, j = i;
        while (k < n && j < n) {
            s += a[k][j];
            k++, j++;
        }
        ans = max(ans, s);
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int t, c = 1;
    cin >> t;
    while (t--) {
        cout << "Case #" << c << ": ";
        solve();
        c++;
    }
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen("D.txt", "r", stdin);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n + 5];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a, a + n);
        if (a[0] + a[1] <= a[n - 1]) {
            cout << 1 << " " << 2 << " " << n << endl;
        }
        else {
            cout << -1 << endl;
        }
    }
    return 0;
}

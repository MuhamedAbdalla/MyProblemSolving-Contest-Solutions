#include <bits/stdc++.h>

using namespace std;

int solve(int l, int r, int a[]) {
    if (l > r) {
        return 0;
    }
    int mn = 1e9, ret = 0;
    for (int i = l; i <= r; i++) {
        ret += (a[i] > 0);
        mn = min(mn, a[i]);
    }
    int cnt = mn, prev = 0;
    for (int i = l; i <= r; i++) {
        a[i] -= mn;
        if (a[i] == 0) {
            cnt += solve(prev, i - 1, a);
            prev = i + 1;
        }
    }
    cnt += solve(prev, r, a);
    ret = min(ret, cnt);
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen("D.txt", "r", stdin);
    int n;
    cin >> n;
    int a[n + 1];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << solve(0, n - 1, a) << endl;
    return 0;
}

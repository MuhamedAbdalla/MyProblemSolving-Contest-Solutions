#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    cin >> n;
    long long a[n + 5];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    long long inc = 0;
    for (int i = n - 1; i > 0; i--) {
        a[i] = a[i] - a[i - 1];
        inc += max(0LL, a[i]);
    }
    long long c = (a[0] + inc) / 2 + (a[0] + inc) % 2;
    long long b = a[0] - c + inc;
    cout << max(c, b) << endl;
    int q;
    cin >> q;
    while (q--) {
        int l, r, v;
        cin >> l >> r >> v;
        l--;
        if (l == 0) {
            a[0] += v;
        }
        else {
            if (a[l] > 0) inc -= a[l];
            a[l] += v;
            if (a[l] > 0) inc += a[l];
        }
        l = r;
        if (l == n) goto l1;
        v *= -1;
        if (a[l] > 0) inc -= a[l];
        a[l] += v;
        if (a[l] > 0) inc += a[l];
        l1:;
        c = (a[0] + inc) / 2 + (a[0] + inc) % 2;
        b = a[0] - c + inc;
        cout << max(c, b) << endl;
    }
    return 0;
}




#include <bits/stdc++.h>

using namespace std;

vector<long long> v;

void get(int st, int en, long long a[], long long s) {
    if (en == 0) {
        v.push_back(s);
        return;
    }
    long long aa[10];
    for (int i = st; i <= en; i++) {
        aa[i] = a[i];
    }
    for (int i = st; i < en; i++) {
        a[i] = a[i] + a[i + 1];
        for (int j = i + 1; j < en; j++) swap(a[j], a[j + 1]);
        get(st, en - 1, a, s + a[i]);
        for (int i = st; i <= en; i++) {
            a[i] = aa[i];
        }
    }
}

void solve() {
    int n;
    cin >> n;
    long long a[n + 5];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    long double ans = 0.0;
    get(0, n - 1, a, 0);
    for (auto i : v) {
        ans += (long double)i;
    }
    cout << fixed << setprecision(10) << (ans / (long double)v.size()) << endl;
    v.clear();
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


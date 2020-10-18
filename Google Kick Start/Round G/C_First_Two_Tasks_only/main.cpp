#include <bits/stdc++.h>

using namespace std;

long long get(int val, int a[], int w, int n) {
    long long s = 0;
    for (int i = 0; i < w; i++) {
        s += min(abs(a[i] - val), n - abs(a[i] - val));
    }
    return s;
}

void solve() {
    int w, n;
    cin >> w >> n;
    int a[w + 5];
    map<int, int> p;
    for (int i = 0; i < w; i++) {
        cin >> a[i];
        p[a[i]]++;
    }
    set<pair<int, int>> st;
    for (auto i : p) {
        st.insert({-i.second, -i.first});
    }
    long long mn = 2e18;
    sort(a, a + w);
    int md = (a[w / 2] - a[w / 2 - 1]) / 2;
    for (int i = max(1, md - 5); i <= min(md + 5, n); i++) {
        mn = min(mn, get(i, a, w, n));
    }
    int c = 0;
    for (auto i : st) {
        mn = min(mn, get(-i.second, a, w, n));
        c++;
        if (c == 1000) break;
    }
    cout << mn << endl;
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

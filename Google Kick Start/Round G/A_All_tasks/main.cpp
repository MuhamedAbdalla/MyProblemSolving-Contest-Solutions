#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    cin >> s;
    set<int> st;
    map<int, int> p;
    for (int i = 0; i + 4 < s.size(); i++) {
        if (s.substr(i, 5) == "START") {
            st.insert(i);
            p[i] = st.size();
        }
    }
    long long ans = 0;
    for (int i = 0; i + 3 < s.size(); i++) {
        if (s.substr(i, 4) == "KICK") {
            auto it = st.upper_bound(i);
            if (it != st.end()) {
                ans += abs(st.size() - p[*it] + 1);
            }
        }
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

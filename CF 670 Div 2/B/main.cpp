#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int t;
    cin >> t;
    vector<long long> v;
    while (t--) {
        int n;
        cin >> n;
        v.clear();
        for (int i = 0; i < n; i++) {
            long long a;
            cin >> a;
            v.push_back(a);
        }
        sort(v.begin(), v.end());
        long long mx = -2e18;
        mx = max(v[0] * v[1] * v[2] * v[3] * v[v.size() - 1], mx);
        mx = max(v[0] * v[1] * v[v.size() - 3] * v[v.size() - 2] * v[v.size() - 1], mx);
        mx = max(v[v.size() - 5] * v[v.size() - 4] * v[v.size() - 3] * v[v.size() - 2] * v[v.size() - 1], mx);
        cout << mx << endl;
    }
    return 0;
}




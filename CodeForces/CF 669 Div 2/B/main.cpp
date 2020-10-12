#include <bits/stdc++.h>

using namespace std;

vector<int> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a;
        for (int i = 0; i < n; i++) {
            cin >> a;
            v.push_back(a);
        }
        sort(v.begin(), v.end());
        vector<int> res;
        res.push_back(v.back());
        v.pop_back();
        int gc = res[0];
        while (res.size() != n) {
            int mx = 0, val = -1;
            for (auto i : v) {
                int curGc = __gcd(gc, i);
                if (curGc > mx) {
                    mx = curGc;
                    val = i;
                }
            }
            auto it = lower_bound(v.begin(), v.end(), val);
            v.erase(it);
            gc = mx;
            res.push_back(val);
        }
        for (auto i : res) cout << i << " ";
        cout << endl;
        v.clear();
    }
    return 0;
}



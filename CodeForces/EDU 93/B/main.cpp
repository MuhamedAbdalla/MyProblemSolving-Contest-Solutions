#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen("D.txt", "r", stdin);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = s.size();
        vector<int> v;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                int c = 0;
                while (s[i] == '1') {
                    i++;
                    c++;
                }
                i--;
                v.push_back(c);
            }
        }
        sort(v.begin(), v.end());
        int res = 0;
        while (v.size()) {
            res += v.back();
            v.pop_back();
            if (v.size()) v.pop_back();
        }
        cout << res << endl;
    }
    return 0;
}

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
        string s;
        cin >> s;
        map<int, int> p;
        long long res = 0, c = 0;
        p[0]++;
        for (int i = 0; i < n; i++) {
            c += (s[i] - '0');
            c--;
            res += p[c];
            p[c]++;
        }
        cout << res << endl;
    }
    return 0;
}

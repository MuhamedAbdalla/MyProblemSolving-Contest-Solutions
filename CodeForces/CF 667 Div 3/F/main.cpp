#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen("D.txt", "r", stdin);
    int t;
    cin >> t;
    while (t--) {
        int n, cnt[30], sum = 0;
        cin >> n;
        fill(cnt, cnt + 28, 0);
        string s;
        for (int i = 0; i < n; i++) {
            cin >> s;
            for (auto j : s) {
                cnt[j - 'a']++;
            }
            sum += s.size();
        }
        bool can = (sum % n == 0);
        for (int i = 0; i < 26; i++) {
            if(cnt[i] > 0)
                can &= (cnt[i] % n == 0);
        }
        if (can) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
    return 0;
}

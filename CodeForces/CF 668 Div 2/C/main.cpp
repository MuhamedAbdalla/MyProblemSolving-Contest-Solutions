#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        int o = 0, z = 0, q = 0;
        bool can = 1;
        string s1 = "", s2 = "";
        for (int i = 0; i + k < s.size(); i++) {
            if (s[i] == '?') {
                if (s[i + k] == '0' || s[i + k] == '1' || s[i + k] == '?') s[i] = s[i + k];
            }
            else if (s[i + k] == '?') {
                s[i + k] = s[i];
            }
            else if (s[i] == '0' && ('0' != s[i + k])) {
                can = 0;
                break;
            }
            else if (s[i] == '1' && ('1' != s[i + k])) {
                can = 0;
                break;
            }
        }
        reverse(s.begin(), s.end());
        for (int i = 0; i + k < s.size(); i++) {
            if (s[i] == '?') {
                if (s[i + k] == '0' || s[i + k] == '1' || s[i + k] == '?') s[i] = s[i + k];
            }
            else if (s[i + k] == '?') {
                s[i + k] = s[i];
            }
            else if (s[i] == '0' && ('0' != s[i + k])) {
                can = 0;
                break;
            }
            else if (s[i] == '1' && ('1' != s[i + k])) {
                can = 0;
                break;
            }
        }
        reverse(s.begin(), s.end());
        if (!can) {
            cout << "NO" << endl;
            continue;
        }
        for (int i = 0; i < k; i++) {
            if (s[i] == '0') z++;
            if (s[i] == '1') o++;
            if (s[i] == '?') q++;
        }
        can &= (q >= abs(o - z) && ((q - abs(o - z)) % 2 == 0));
        if (can) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}


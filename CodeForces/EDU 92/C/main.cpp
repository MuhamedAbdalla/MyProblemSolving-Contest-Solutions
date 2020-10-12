#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        map<string, int> p;
        for (int i = 0; i < s.size(); i++) {
            p[s.substr(i, 1)]++;
        }
        int mx = 0;
        for (char i = '0'; i <= '9'; i++) {
            for (char j = '0'; j <= '9'; j++) {
                int c = 0;
                for (int k = 0; k < s.size(); k++) {
                    if (c % 2 == 0 and s[k] == i) {
                        c++;
                    } else if (c % 2 and s[k] == j) {
                        c++;
                    }
                }
                if (i != j and c % 2) c--;
                mx = max(mx, c);
            }
        }
        for (auto i : p) {
            mx = max(mx, i.second);
        }
        cout << s.size() - mx << endl;
    }
    return 0;
}

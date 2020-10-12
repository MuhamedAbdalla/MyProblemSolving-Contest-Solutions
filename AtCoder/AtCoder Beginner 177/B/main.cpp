#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    string s, ss;
    cin >> s >> ss;
    int mn = 2e9;
    for (int i = 0; i <= s.size() - ss.size(); i++) {
        int c = 0;
        for (int j = i, k = 0; j < i + ss.size(); j++, k++) {
            c += (s[j] != ss[k]);
        }
        mn = min(mn, c);
    }
    cout << mn << endl;
    return 0;
}





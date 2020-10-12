#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen("D.txt", "r", stdin);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        string ss = "";
        for (int i  = 0; i < n; i++) ss += s[n - 1];
        cout << ss << endl;
    }
    return 0;
}

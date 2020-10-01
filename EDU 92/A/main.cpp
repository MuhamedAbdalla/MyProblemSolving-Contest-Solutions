#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        if (2 * n > m) {
            cout << -1 << " " << -1 << endl;
            continue;
        }
        cout << n << " " << n * 2 << endl;
    }
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    cin >> n;
    int a[n + 5], b[n + 5];
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    bool can = 0;
    for (int i = 2; i < n; i++) {
        if (a[i - 2] == b[i - 2] && a[i - 1] == b[i - 1] && a[i] == b[i]) {
            cout << "Yes" << endl;
            can = 1;
            break;
        }
    }
    if (!can) {
        cout << "No" << endl;
    }
    return 0;
}





#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a, z = 0, o = 0;
        for (int i = 0; i < n; i++) {
            cin >> a;
            z += (a == 0);
            o += (a == 1);
        }
        if (z >= o) {
            cout << z << endl;
            while (z--) cout << 0 << " ";
        }
        else {
            cout << (o / 2) * 2 << endl;
            while (o >= 2) {
                cout << 1 << " " << 1 << " ";
                o -= 2;
            }
        }
        cout << endl;
    }
    return 0;
}



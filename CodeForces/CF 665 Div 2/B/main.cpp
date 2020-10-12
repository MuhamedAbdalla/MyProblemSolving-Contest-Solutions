#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int x, y, z;
        int a, b, c;
        cin >> x >> y >> z >> a >> b >> c;
        int all = x + y + z;
        int sum = min(z, b) * 2;
        int m = min(z, b);
        z -= m;
        b -= m;
        all -= m;
        all -= y;
        m = min(all, c);
        c -= m;
        all -= m;
        sum -= c * 2;
        cout << sum << endl;
    }
    return 0;
}


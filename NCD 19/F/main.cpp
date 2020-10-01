#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen("D.txt", "r", stdin);
    int t;
    cin >> t;
    while (t--) {
        long long x, y;
        cin >> x >> y;
        x -= y;
        long long res = x / 6LL;
        if (x % 6 != 0) res++;
        cout << res << endl;
    }
    return 0;
}

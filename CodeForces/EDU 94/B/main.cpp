#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen("D.txt", "r", stdin);
    int t;
    cin >> t;
    while(t--) {
        long long p, f;
        cin >> p >> f;
        long long cx, cy;
        if(p < f) swap(p, f);
        cin >> cx >> cy;
        long long s, w;
        cin >> s >> w;
        if (s > w) {
            swap(s, w);
            swap(cx, cy);
        }
        long long mx = 0;
        for (long long i = 0; i <= cx; i++) {
            long long x = min(i, p / s), y = min(cx - i, f / s);
            long long res = 0;
            res += x + y;
            x *= s;
            y *= s;
            if(x <= p && y <= f) {
                x = p - x;
                y = f - y;
                if (x < y) swap(x, y);
                res += min(x / w,  cy);
                res += min((y / w), cy - min(x / w,  cy));
            }
            mx = max(mx, res);
        }
        cout << mx << endl;
    }
    return 0;
}

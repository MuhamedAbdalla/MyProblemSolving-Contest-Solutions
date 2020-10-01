#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int a[n + 1], b[n + 1];
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            b[i] = a[i];
        }
        sort(b, b + n);
        int gc = 0;
        for(int i = 0; i < n; i++) {
            if(a[i] != b[i]) {
                gc = __gcd(gc, a[i]);
            }
        }
        if(gc != 0 && gc != b[0]) {
            for(int i = 0; i < n; i++) {
                if(a[i] == b[i] && __gcd(gc, a[i]) == b[0]) {
                    gc = __gcd(gc, a[i]);
                    break;
                }
            }
        }
        if(gc == b[0] || gc == 0) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        if(k == 0) {
            if(n % 2 == 0) {
                cout << 0 << endl;
            }
            else {
                cout << 1 << endl;
            }
        }
        else {
            if(n >= k) {
                cout << (((n - k) % 2 == 0) ? 0 : 1) << endl;
            }
            else {
                cout << k - n << endl;
            }
        }
    }
    return 0;
}

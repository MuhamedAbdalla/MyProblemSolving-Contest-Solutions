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
        int a[105];
        int c[105];
        fill(c, c + n + 1, 0);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            c[a[i]]++;
        }
        int s = -1, ss = -1;
        for (int i = 0; i <= 100; i++) {
            if (c[i] > 1) {
                continue;
            }
            else if (c[i] == 1 && s == -1) {
                s = i;
            }
            else if (c[i] == 0) {
                if (s != -1) ss = i;
                else {
                    s = ss = i;
                }
                break;
            }
        }
        cout << s + ss << endl;
    }
    return 0;
}




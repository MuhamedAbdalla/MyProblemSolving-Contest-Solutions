#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen("D.txt", "r", stdin);
    int t;
    cin >> t;
    while (t--) {
    	int n;
    	cin >> n;
    	for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            int res = 0;
            while(a > 0) {
                if (a % 2 != 0) res++;
                a /= 2;
            }
            cout << res << " ";
        }
        cout << endl;
    }
    return 0;
}

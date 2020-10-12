#include <bits/stdc++.h>

using namespace std;

bool solve(int l, int r, long long acc[], int x) {
    return (acc[r] - (l == 0 ? 0 : acc[l - 1])) < x;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen("D.txt", "r", stdin);
    int t;
    cin >> t;
    while (t--) {
    	int n, x;
    	cin >> n >> x;
    	int a[n + 1];
    	long long acc[n + 1];
    	fill(acc, acc + n, 0);
    	for (int i = 0; i < n; i++) {
            cin >> a[i];
            acc[i] = a[i];
            if (i) acc[i] += acc[i - 1];
        }
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            int lo = i, hi = n - 1, mid;
            while (lo <= hi) {
                mid = (lo + hi) / 2;
                if (solve(i, mid, acc, x)) {
                    lo = mid + 1;
                }
                else {
                    hi = mid - 1;
                }
            }
            lo--;
            ans += max(0, lo - i + 1);
        }
        cout << ans << endl;
    }
    return 0;
}

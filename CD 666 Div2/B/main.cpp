#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen("D.txt", "r", stdin);
    int n;
    cin >> n;
    long long a[n + 1];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    long long mn = 2e18;
    for (int i = 1; i <= 1e5; i++) {
        int j = 0;
        long long sum = 0, pw = 1;
        for (; j < n; j++) {
            sum += abs(a[j] - pw);
            if (!((2e18 / i) >= pw))
                break;
            pw *= i;
        }
        if (j == n) {
            mn = min(mn, sum);
        }
    }
    cout << mn << endl;
    return 0;
}

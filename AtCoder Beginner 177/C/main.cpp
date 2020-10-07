#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    long long n;
    cin >> n;
    long long a[n + 5], res = 0, MOD = 1e9 + 7;
    for (int i = 0; i < n; i++) cin >> a[i];
    long long sum = a[0];
    for (int i = 1; i < n; i++) {
        res = (res % MOD + (sum % MOD * a[i] % MOD) % MOD) % MOD;
        sum += a[i];
    }
    cout << res << endl;
    return 0;
}





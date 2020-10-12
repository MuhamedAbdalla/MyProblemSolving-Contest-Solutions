#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    long long ans = 1LL, res = 1LL, rAns = 1LL, MOD = 1e9 + 7;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        ans = (ans * 9LL) % MOD;
        rAns = (rAns * 8LL) % MOD;
        res = (res * 10LL) % MOD;
    }
    cout << (((res - ans - ans + rAns) + MOD) % MOD + MOD) % MOD << endl;
    return 0;
}





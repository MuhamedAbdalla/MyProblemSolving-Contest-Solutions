#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1e9 + 7;
typedef long long mType;
typedef vector<vector<mType>> mat;
const mType N = 15;

mat init() {
    return vector<vector<mType> >(N, vector<mType>(N, 0));
}

void mul(mat &a, mat &b, mat &re) {
    for (int i = 0; i < 13; i++) {
        for (int j = 0; j < 13; j++) {
            re[i][j] = 0;
            for (int k = 0; k < 13; k++) {
                re[i][j] = (re[i][j] + (a[i][k] * b[k][j]) % MOD) % MOD;
            }
        }
    }
    swap(a, re);
}

mat mfp(mat &a, long long p) {
    mat re = init(), tmp = init();
    for (int i = 0; i < 13; i++) re[i][i] = 1;

    while (p) {
        if (p & 1) mul(re, a, tmp);
        p >>= 1;
        mul(a, a, tmp);
    }
    return re;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    long long k, n;
    cin >> n >> k;
    long long res[n + 5];
    fill(res, res + n + 5, 0);
    for (int i = 0; i < n; i++) {
        cin >> res[i];
    }
    res[n] = 1;
    res[n + 1] = n;
    res[n + 2] = n * n;
    mat t = init();
    for (int i = 0; i < n; i++) {
        cin >> t[n - i - 1][n - 1];
    }
    long long p, r, q;
    cin >> p >> q >> r;
    if (k < n) {
        cout << res[k] << endl;
        return 0;
    }
    for (int i = 1; i < n; i++) t[i][i - 1] = 1;
    t[n][n - 1] = p;
    t[n][n] = 1;
    t[n + 1][n + 2] = 2;
    t[n][n + 1] = 1;
    t[n + 1][n + 1] = 1;
    t[n + 1][n - 1] = q;
    t[n + 2][n - 1] = r;
    t[n + 2][n + 2] = 1;
    t[n][n + 2] = 1;
    t = mfp(t, k - n + 1);
    long long ans = 0;
    for (int i = 0; i < n + 3; i++) {
        ans = (ans + (res[i] * t[i][n - 1]) % MOD) % MOD;
    }
    cout << ans << endl;
    return 0;
}




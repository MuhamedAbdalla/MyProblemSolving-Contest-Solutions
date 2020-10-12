#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;
typedef long long mType;
typedef vector<vector<mType>> mat;
const mType N = 100;

mat init() {
    return vector<vector<mType> >(N, vector<mType>(N));
}

void mul(mat &a, mat &b, mat &re) {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            re[i][j] = 0;
            for (int k = 0; k < N; k++)
                re[i][j] = (re[i][j] + (a[i][k] * b[k][j] % MOD) % MOD) % MOD;
        }
    swap(a, re);
}

mat mfp(mat &a, long long p) {
    mat re = init(), tmp = init();
    for (int i = 0; i < N; i++)
        re[i][i] = 1;

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
    freopen("D.txt", "r", stdin);
    int n, m, k;
    cin >> n >> m >> k;
    mat t = init();
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        t[u - 1][v - 1] = 1;
    }
    t = mfp(t, k);
    long long out = 0;
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            out = (out + t[i][j]) % MOD;
        }
    }
    cout << out << endl;
    return 0;
}


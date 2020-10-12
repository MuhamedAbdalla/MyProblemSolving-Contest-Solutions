#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;
typedef long long mType;
typedef vector<vector<mType>> mat;
const mType N = 2;

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
    long long n;
    cin >> n;
    mat tx = init();
    tx[0][0] = 19;
    tx[0][1] = 7;
    tx[1][0] = 6;
    tx[1][1] = 20;
    tx = mfp(tx, n);
    cout << tx[0][0] << endl;
    return 0;
}

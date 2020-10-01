#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1e9 + 7;
typedef long long mType;
typedef vector<vector<mType>> mat;
const mType N = 101;

mat init() {
    return vector<vector<mType> >(N, vector<mType>(N));
}

void mul(mat &a, mat &b, mat &re) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            re[i][j] = 0;
            for (int k = 0; k < N; k++) {
                re[i][j] = (re[i][j] + (a[i][k] * b[k][j] % MOD) % MOD) % MOD;
            }
        }
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
    int n, l, m;
    cin >> n >> l >> m;
    int cOut[N], c[N], cIn[N];
    fill(c, c + N, 0);
    fill(cOut, cOut + N, 0);
    fill(cIn, cIn + N, 0);
    int a[N];
    for (int i = 0; i < n; i++) {
        int u;
        cin >> u;
        cIn[u % m]++;
    }
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        c[a[i] % m]++;
    }

    for (int i = 0; i < n; i++) {
        int u;
        cin >> u;
        cOut[(u + a[i]) % m]++;
    }
    mat res = init(), temp = init();
    for (int i = 0; i < m; i++) {
        temp[0][i] += cIn[i];
        for (int j = 0; j < m; j++) {
            res[i][(i + j) % m] += c[j];
        }
    }
    mat ans = init();
    if (l > 2) {
        res = mfp(res, l - 2);
        mul(temp, res, ans);
    }
    long long out = 0;
    for (int i = 0; i < m; i++) {
        if (i != 0) {
            out = (out + (temp[0][i] * cOut[m - i]) % MOD) % MOD;
        }
        else {
            out = (out + (temp[0][i] * cOut[i]) % MOD) % MOD;
        }
    }
    cout << out << endl;
    return 0;
}


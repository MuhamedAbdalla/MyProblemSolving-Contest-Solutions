#include <bits/stdc++.h>

using namespace std;

const long long oo = 2e18;
typedef long long mType;
typedef vector<vector<mType>> mat;
const mType N = 100;

mat init() {
    return vector<vector<mType> >(N, vector<mType>(N, oo));
}

void mul(mat &a, mat &b, mat &re) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            re[i][j] = oo;
            for (int k = 0; k < N; k++) {
                re[i][j] = min(re[i][j], (a[i][k] + b[k][j]));
            }
        }
    }
    swap(a, re);
}

mat mfp(mat &a, long long p) {
    mat re = init(), tmp = init();
    for (int i = 0; i < N; i++)
        re[i][i] = 0;

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
    long long k, n, m;
    cin >> n >> m >> k;
    mat t = init();
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        t[a - 1][b - 1] = c;
    }
    t = mfp(t, k);
    long long mn = 2e18;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            mn = min(mn, t[i][j]);
        }
    }
    if (mn > 1e18) cout << "IMPOSSIBLE" << endl;
    else cout << mn << endl;
    return 0;
}



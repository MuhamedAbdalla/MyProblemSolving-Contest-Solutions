#include <bits/stdc++.h>

using namespace std;

typedef double mType;
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
                re[i][j] = re[i][j] + a[i][k] * b[k][j];
        }
    swap(a, re);
}

mat mfp(mat &a, int p) {
    mat re = init(), tmp = init();
    for (int i = 0; i < N; i++)
        re[i][i] = 1.0;

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
    cout.precision(12);
    cout << fixed;
    int n;
    double p;
    cin >> n >> p;
    if (n == 1) {
        cout << 1 - p << endl;
        return 0;
    }
    mat tx = init();
    tx[0][1] = p;
    tx[0][0] = 1.0 - p;
    tx[1][0] = p;
    tx[1][1] = 1.0 - p;
    tx = mfp(tx, n);
    cout << tx[0][0] << endl;
    return 0;
}

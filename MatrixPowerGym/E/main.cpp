#include <bits/stdc++.h>

using namespace std;

const long long MOD = 4294967296;
typedef unsigned int mType;
typedef vector<vector<mType>> mat;
const mType N = 65;

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

int dx[] = {1, -1, 2, -2, 1, -1, 2, -2};
int dy[] = {2, 2, 1, 1, -2, -2, -1, -1};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen("D.txt", "r", stdin);
    long long k;
    cin >> k; k++;
    mat t = init();
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            for (int k = 0; k < 8; k++) {
                int x = i + dx[k], y = j + dy[k];
                if (x < 8 && x >= 0 && y < 8 && y >= 0) {
                    t[8 * i + j][8 * x + y]++;
                }
            }
        }
    }
    for (int i = 0; i < N; i++) {
        t[i][64] = 1;
    }
    t = mfp(t, k);
    cout << t[0][64] << endl;
    return 0;
}


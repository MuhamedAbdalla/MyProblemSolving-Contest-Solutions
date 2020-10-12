#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1e9 + 7;
typedef long long mType;
typedef vector<vector<mType>> mat;
const mType N = 201;

mat init() {
    return vector<vector<mType> >(N, vector<mType>(N, 0));
}

void mul(mat &a, mat &b, mat &re) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            re[i][j] = 0;
            for (int k = 0; k < N; k++) {
                re[i][j] = (re[i][j] + (a[i][k] * b[k][j]) % MOD) % MOD;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen("D.txt", "r", stdin);
    int n, q, m;
    cin >> n >> m >> q;
    mat a = init();
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        a[u][v] = 1;
    }
    vector<mat> v;
    v.push_back(a);
    for (long long p = 1; p <= 1e9; p *= 2) {
        mat cur = init();
        mul(v.back(), v.back(), cur);
        v.push_back(cur);
    }
    while (q--) {
        int s, t, k;
        cin >> s >> t >> k;
        vector<long long> res(n + 1);
        res[s]++;
        for (int i = 0; k - (1 << i) >= 0; i++) {
            if (((1 << i) & k) != 0) {
                vector<long long> Tres(n + 1);
                for (int j = 1; j <= n; j++) {
                    for (int p = 1; p <= n; p++) {
                        Tres[j] = (Tres[j] + (res[p] * v[i][p][j]) % MOD) % MOD;
                    }
                }
                res = Tres;
            }
        }
        cout << res[t] << endl;
    }
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1e9 + 7;
typedef long long mType;
const int N = 2;

struct mat {
    mType a[N][N];

    void init() {
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                a[i][j] = 0;
    }

    void matrixI() {
        for (int i = 0; i < N; i++) a[i][i] = 1;
    }

    void mul(mat &a, mat &b, mat &re) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                re.a[i][j] = 0;
                for (int k = 0; k < N; k++) {
                    re.a[i][j] = (re.a[i][j] + (a.a[i][k] * b.a[k][j]) % MOD) % MOD;
                }
            }
        }
    }
};



mat loadMatrix(char s) {
    mat ret;
    ret.init();
    string st = "AEIOU";
    for (char i = 'A'; i <= 'Z'; i++) {
        if (i == s || s == '?') {
            if (i == 'H') {
                ret.a[0][1]++;
                ret.a[1][1]++;
            }
            else if (i == 'S' || i == 'D') {
                ret.a[1][0]++;
                ret.a[0][0]++;
            }
            else if (st.find(i) != -1) {
                ret.a[0][1]++;
                ret.a[1][0]++;
            }
            else {
                ret.a[0][0]++;
                ret.a[1][1]++;
            }
        }
    }
    return ret;
}

struct SegmentTree {
    int NN;
    vector<mat> T;

    SegmentTree(int _N) {
        NN = _N;
        mat tmp;
        tmp.matrixI();
        for (int i = 0; i <= 4 * NN; i++) {
            T.push_back(tmp);
        }
    }

    void mrg(int i) {
        T[i].mul(T[i << 1], T[i << 1 | 1], T[i]);
    }

    void udt(int p, int s, int e, int i, mat val) {
        if (s == e) {
            T[i] = val;
            return;
        }

        int md = (s + e) >> 1;
        if (p > md) udt(p, md + 1, e, i << 1 | 1, val);
        else udt(p, s, md, i << 1, val);


        mrg(i);
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    SegmentTree segTree(n);
    for (int i = 0; i < n; i++) {
        segTree.udt(i + 1, 1, n, 1, loadMatrix(s[i]));
    }
    cout << segTree.T[1].a[1][1] << endl;
    while (q--) {
        int i;
        char c;
        cin >> i >> c;
        segTree.udt(i, 1, n, 1, loadMatrix(c));
        cout << segTree.T[1].a[1][1] << endl;
    }
    return 0;
}




#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, MOD = 1e9 + 7;
long long pw[2][N], segtree[2][2][(N + 5) * 4];
string s, ss;

void mrg(int indx, int pos) {
    segtree[indx][0][pos] = (segtree[indx][0][2 * pos] + segtree[indx][0][2 * pos + 1]) % MOD;
    segtree[indx][1][pos] = (segtree[indx][1][2 * pos] + segtree[indx][1][2 * pos + 1]) % MOD;
}

void udt(int l, int r, int pos, int indx, int pt, long long val) {
    if (l == r) {
        segtree[indx][0][pt] = (segtree[indx][0][pt] % MOD + (val * pw[0][pos] % MOD) % MOD) % MOD;
        segtree[indx][1][pt] = (segtree[indx][1][pt] % MOD + (val * pw[1][pos] % MOD) % MOD) % MOD;
        return;
    }

    int mid = (l + r) / 2;
    if(pos <= mid) udt(l, mid, pos, indx, pt * 2, val);
    else udt(mid + 1, r, pos, indx, pt * 2 + 1, val);

    mrg(indx, pt);
}

pair<long long, long long> qry(int l, int r, int s, int e, int indx, int pt) {
    if(s <= l && r <= e) {
        return {segtree[indx][0][pt], segtree[indx][1][pt]};
    }

    int mid = (l + r) / 2;

    pair<long long, long long> L = {0, 0};
    pair<long long, long long> R = {0, 0};

    if(s <= mid) L = qry(l, mid, s, e, indx, pt * 2);
    if(e > mid) R = qry(mid + 1, r, s, e, indx, pt * 2 + 1);

    L.first = (L.first + R.first) % MOD;
    L.second = (L.second + R.second) % MOD;

    return L;
}

bool valid(pair<long long, long long> L, pair<long long, long long> R) {
    return L.first == R.first && L.second == R.second;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen("D.txt", "r", stdin);
    int t;
    pw[0][0] = 1;
    pw[1][0] = 1;
    for (int i = 1; i <= 1e5; i++) {
        pw[0][i] = (pw[0][i - 1] % MOD * 13LL % MOD) % MOD;
        pw[1][i] = (pw[1][i - 1] % MOD * 31LL % MOD) % MOD;
    }
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        memset(segtree, 0, sizeof(segtree));
        cin >> s;
        ss = s;
        reverse(s.begin(), s.end());
        ss.push_back('%');
        s.push_back('%');
        reverse(s.begin(), s.end());
        reverse(ss.begin(), ss.end());
        for (int i = 1; i < ss.size(); i++) {
            udt(1, n, i, 0, 1, s[i] - 'a' + 1);
        }
        for (int i = 1; i < s.size(); i++) {
            udt(1, n, i, 1, 1, ss[i] - 'a' + 1);
        }
        while (q--) {
            int a, b;
            cin >> a >> b;
            if (a == 1) {
                char c;
                cin >> c;

                if(s[b] == c) {
                    continue;
                }

                long long diff = (c - s[b] + MOD) % MOD;

                s[b] = c;
                ss[n - b + 1] = c;

                udt(1, n, b, 0, 1, diff);
                udt(1, n, n - b + 1, 1, 1, diff);
            }
            else {
                int c;
                cin >> c;
                pair<long long, long long> L = qry(1, n, b, c, 0, 1);
                pair<long long, long long> R = qry(1, n, n - c + 1, n - b + 1, 1, 1);
                int Fst = b, Sst = n - c + 1;
                if (Fst <= Sst) L.first = (L.first % MOD * pw[0][abs(Fst - Sst)] % MOD) % MOD, L.second = (L.second % MOD * pw[1][abs(Fst - Sst)] % MOD) % MOD;
                else R.first = (R.first % MOD * pw[0][abs(Fst - Sst)] % MOD) % MOD, R.second = (R.second % MOD * pw[1][abs(Fst - Sst)] % MOD) % MOD;
                if (valid(L, R)) cout << "Adnan Wins" << endl;
                else cout << "ARCNCD!" << endl;
            }
        }
    }
    return 0;
}

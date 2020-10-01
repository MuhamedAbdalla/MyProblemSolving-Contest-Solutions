#include <bits/stdc++.h>
using namespace std;

const long long MAX = 3e5 + 5, oo = 1e18;
vector<long long> e[MAX], tout(MAX), tin(MAX);
long long timer = 1;


void dfs(long long n, long long pre) {
	tin[n] = timer;
	for(auto i : e[n]) {
		if(i != pre) {
			timer++;
			dfs(i, n);
		}
	}
	tout[n] = timer;
}

struct SegmentTree {
    long long N;
    vector<double> T, L;

    SegmentTree(long long _N) {
        N = _N;
        T = vector<double>((N + 5) << 2);
        L = vector<double>((N + 5) << 2);
    }

    void mrg(long long i) {
        T[i] = T[i << 1] + T[i << 1 | 1];
    }

    void bld(long long s, long long e, long long i) {
        if (s == e) return void(T[i] = 0.0);

        long long md = (s + e) >> 1;
        bld(s, md, i << 1);
        bld(md + 1, e, i << 1 | 1);

        mrg(i);

    }


    void push(long long i, long long s, long long e) {
        if (!L[i]) return;
        T[i] = double(e - s + 1) * L[i];
        if (s != e) {
            L[i << 1] = L[i];
            L[i << 1 | 1] = L[i];
        }
        L[i] = 0;
    }

    void udt(long long l, long long r, double val, long long s, long long e, long long i) {
        if (l > r) return;
        push(i, s, e);
        if (r < s || l > e) return;
        if (l <= s && r >= e) {
            L[i] = log2(double(val));
            push(i, s, e);
            return;
        }

        int md = (s + e) >> 1;
        udt(l, r, val, s, md, i << 1);
        udt(l, r, val, md + 1, e, i << 1 | 1);

        mrg(i);
    }


    double qry(long long l, long long r, long long s, long long e, long long i) {
        push(i, s, e);
        if (r < s || l > e) return 0.0;
        if (l <= s && r >= e) return T[i];

        long long md = (s + e) >> 1;

        return qry(l, r, s, md, i << 1) + qry(l, r, md + 1, e, i << 1 | 1);
    }
};

main() {
	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen("D.txt", "r", stdin);
    //cout.precision(12);
    //cout << fixed;
	long long n;
	cin >> n;
	SegmentTree seg(n);
	for(long long i = 1; i < n; i++) {
		long long u, v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(1, -1);
	seg.bld(1, n, 1);
	long long q;
	cin >> q;
	while(q--) {
        long long a, b, c;
        cin >> a >> b >> c;
        if(a == 1) {
            seg.udt(tin[b], tout[b], double(c), 1, n, 1);
        } else {
            long double l = seg.qry(tin[b], tout[b], 1, n, 1);
            long double r = seg.qry(tin[c], tout[c], 1, n, 1);
            if(l + r >= log2(oo)) {
                cout << -1 << endl;
            } else {
                cout << pow(2.0, l + r) * 1LL << endl;
            }
        }
    }
    return 0;
}

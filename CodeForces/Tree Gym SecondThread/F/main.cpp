#include <bits/stdc++.h>
using namespace std;

const int MAX = 3e5 + 5, LG = 21, oo = 1e9;
int dep[MAX];
vector<int> e[MAX], tout(MAX), tin(MAX);
int timer = 1;


void init(int n) {
    timer = 1;
    tin.clear(), tout.clear();
    for (int i = 0; i <= n; i++) {
        e[i].clear();
        dep[i] = 0;
    }
}

void dfs(int n, int pre) {
	tin[n] = timer;
	for(auto i : e[n]) {
		if(i != pre) {
			timer++;
			dep[i] = dep[n] + 1;
			dfs(i, n);
		}
	}
	tout[n] = timer;
}

struct SegmentTree {
    int N;
    vector<long long> T;

    SegmentTree(int _N) {
        N = _N;
        T = vector<long long>((N + 5) << 2);
    }

    void mrg(int i) {
        T[i] = T[i << 1] + T[i << 1 | 1];
    }

    void bld(int s, int e, int i) {
        if (s == e) return void(T[i] = 0);

        int md = (s + e) >> 1;
        bld(s, md, i << 1);
        bld(md + 1, e, i << 1 | 1);

        mrg(i);

    }


    void udt(int p, int s, int e, int i, long long val) {
        if (s == e) return void(T[i] += val);

        int md = (s + e) >> 1;
        if (p > md) udt(p, md + 1, e, i << 1 | 1, val);
        else udt(p, s, md, i << 1, val);

        mrg(i);
    }

    long long qry(int l, int r, int s, int e, int i) {
        if (r < s || l > e) return 0;
        if (l <= s && r >= e) return T[i];

        int md = (s + e) >> 1;

        return qry(l, r, s, md, i << 1) + qry(l, r, md + 1, e, i << 1 | 1);
    }
};

int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen("D.txt", "r", stdin);
    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        SegmentTree seg(n);
        for(int i = 1; i < n; i++) {
            int u, v;
            cin >> u >> v;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        dfs(1, -1);
        seg.bld(1, n, 1);
        while(q--) {
            int a, b, c;
            cin >> a >> b >> c;
            if(c == 0) {
                if (dep[a] < dep[b]) swap(a, b);
                long long l = abs(seg.qry(tin[a], tout[a], 1, n, 1));
                cout << l << endl;
            } else {
                seg.udt(tin[a], 1, n, 1, c);
                seg.udt(tin[b], 1, n, 1, -c);
            }
        }
        init(n);
    }
    return 0;
}

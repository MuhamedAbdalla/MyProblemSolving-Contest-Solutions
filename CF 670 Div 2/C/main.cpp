#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
int n, mx[N], dep[N], u, maxi;
map<pair<int, int>, bool> pq;
vector<int> e[N];

void init() {
    for (int i = 0; i <= n; i++) {
        e[i].clear();
    }
    fill(dep, dep + n + 1, 0);
    fill(mx, mx + n + 1, 0);
    pq.clear();
}

void rdfs(int c, int p, int lvl) {
    dep[c] = 1;
    for (auto i : e[c]) {
        if(i != p && !pq[{c, i}]) {
            rdfs(i, c, lvl + 1);
            dep[c] += dep[i];
        }
    }
    if (dep[c] == 1 && lvl < maxi) {
        u = c;
        maxi = lvl;
    }
}

void dfs(int c, int p) {
    dep[c] = 1;
    for (auto i : e[c]) {
        if(i != p) {
            dfs(i, c);
            dep[c] += dep[i];
            mx[c] = max(mx[c], dep[i]);
        }
    }
    mx[c] = max(mx[c], n - dep[c]);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n - 1; i++) {
            int x, y;
            cin >> x >> y;
            e[x].push_back(y);
            e[y].push_back(x);
        }
        dfs(1, 1);
        int mn = 1e9;
        vector<int> v;
        for (int i = 1; i <= n; i++) {
            if (mx[i] < mn) {
                mn = mx[i];
                v.clear();
                v.push_back(i);
            }
            else if (mx[i] == mn) {
                v.push_back(i);
            }
        }
        if (v.size() == 1) {
            cout << v[0] << " " << e[v[0]][0] << endl;
            cout << v[0] << " " << e[v[0]][0] << endl;
        }
        else {
            pq[{v[0], v[1]}] = 1;
            pq[{v[1], v[0]}] = 1;
            maxi = 2e18;
            rdfs(v[0], v[0], 0);
            cout << u << " " << e[u][0] << endl;
            cout << u << " " << v[1] << endl;
        }
        init();
    }
    return 0;
}




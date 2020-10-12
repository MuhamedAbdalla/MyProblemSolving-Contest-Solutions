#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int dep[N], low[N], timer, par[N], edge[N][5], scc[N], cnt, indx, mx, nd, dist[N];
stack<int> st;
vector<int> e[N], ee[N];

void init() {
    cnt = 0, indx = 0, timer = 0;
    fill(scc, scc + N, 0);
    fill(par, par + N, 0);
    fill(low, low + N, 0);
    fill(dist, dist + N, -1);
    fill(dep, dep + N, 0);
    for (int i = 0; i < N; i++) e[i].clear(), ee[i].clear();
}


void tarjan(int cur, int pre) {
    dep[cur] = low[cur] = timer++;
    st.push(cur);
    for(auto i : e[cur]) {
        if (i == pre) continue;
        if(dep[i] > 0) {
            low[cur] = min(low[cur], dep[i]);
        }
        else {
            tarjan(i, cur);
            par[i] = cur;
            low[cur] = min(low[cur], low[i]);
            if(low[i] > dep[cur]) {
                edge[++indx][0] = cur;
                edge[indx][1]= i;
            }
        }
    }
    if(dep[cur] == low[cur]) {
        cnt++;
        while(1) {
            int np = st.top();
            st.pop();
            scc[np] = cnt;
            if(np == cur || st.empty()) break;
        }
    }
}

void dfs(int cm,int lvl) {
    dist[cm] = lvl;
    if(dist[cm] > mx){
        mx = dist[cm];
        nd = cm;
    }
    for (auto i : ee[cm]) {
        if (dist[i] == -1) {
            dfs(i, lvl + 1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen("D.txt", "r", stdin);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        init();
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        for (int i = 1; i <= n; i++) {
            if (dep[i] == 0) {
                tarjan(i, 0);
            }
        }
        for(int i = 1; i <= indx; i++) {
            ee[scc[edge[i][0]]].push_back(scc[edge[i][1]]);
            ee[scc[edge[i][1]]].push_back(scc[edge[i][0]]);
        }
        mx = 0, nd = 1;
        dfs(1, 0);
        fill(dist, dist + N, -1);
        mx = 0;
        dfs(nd, 0);
        cout << indx - mx << endl;
    }
    return 0;
}

class Solution {
public:
    static const int N = 1e2 + 5;
    set<int> st[N];
    
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        for (auto i : roads) {
            st[i[0]].insert(i[1]);
            st[i[1]].insert(i[0]);
        }
        int mx = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int c = st[i].size() + st[j].size() - (st[i].find(j) != st[i].end());
                mx = max(mx, c);
            }
        }
        for (int i = 0; i <= n; i++) st[i].clear();
        return mx;
    }
};

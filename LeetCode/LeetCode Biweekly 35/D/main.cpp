class Solution {
public:
    bool isPrintable(vector<vector<int>>& targetGrid) {
        int n = targetGrid.size(), m = targetGrid[0].size();
        bool ans = 1;
        for (int kk = 1; kk <= 60; kk++) {
            pair<int, int> ul = {2e9, 2e9};
            pair<int, int> ur = {2e9, 0};
            pair<int, int> dl = {0, 2e9};
            pair<int, int> dr = {0, 0};
            bool aa = 1;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    bool f = 1;
                    for (int k = i; k < n; k++) {
                        if (targetGrid[k][j] < targetGrid[i][j]) f = 0;
                        if (targetGrid[k][j] == targetGrid[i][j] && !f) {
                            aa = 0;
                        }
                    }
                    f = 1;
                    for (int k = i; k >= 0; k--) {
                        if (targetGrid[k][j] < targetGrid[i][j]) f = 0;
                        if (targetGrid[k][j] == targetGrid[i][j] && !f) {
                            aa = 0;
                        }
                    }
                    f = 1;
                    for (int k = j; k < m; k++) {
                        if (targetGrid[i][k] < targetGrid[i][j]) f = 0;
                        if (targetGrid[i][k] == targetGrid[i][j] && !f) {
                            aa = 0;
                        }
                    }
                    f = 1;
                    for (int k = j; k >= 0; k--) {
                        if (targetGrid[i][k] < targetGrid[i][j]) f = 0;
                        if (targetGrid[i][k] == targetGrid[i][j] && !f) {
                            aa = 0;
                        }
                    }
                    if (targetGrid[i][j] == kk) {
                        if (i < ul.first || j < ul.second) {
                            ul = {i, j};
                        }
                        if (i < ur.first || j > ur.second) {
                            ur = {i, j};
                        }
                        if (i > dl.first || j < dl.second) {
                            dl = {i, j};
                        }
                        if (i > dr.first || j > dr.second) {
                            dr = {i, j};
                        }
                    }
                }
            }
            if (aa == 1) continue;
            if (ul.first != 2e9) {
                if (dr.second > ul.second && dr.second < ur.second) ans = 0;
                if (dl.second > ul.second && dl.second < ur.second) ans = 0;
                if (dr.first > ul.first && dr.first < dl.first) ans = 0;
                if (ur.first > ul.first && ur.first < dl.first) ans = 0;
                /////////////////////////////////////////////////////////////////
                if (ul.second > dl.second && ul.second < dr.second) ans = 0;
                if (ur.second > dl.second && ur.second < dr.second) ans = 0;
                if (dl.first > ur.first && dl.first < dr.first) ans = 0;
                if (ul.first > ur.first && ul.first < dr.first) ans = 0;
                if (ans == 0) {
                    goto l1;
                }
            }
        }
        l1:;
        return ans;
    }
};

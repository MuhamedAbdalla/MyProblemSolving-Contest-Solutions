class Solution {
public:
    static const int N = 1e5 + 5;
    bool va[N], vb[N];
    
    bool checkPalindromeFormation(string a, string b) {
        memset(va, 0, sizeof(va));
        memset(vb, 0, sizeof(vb));
        string s = a, ss = b;
        reverse(s.begin(), s.end());
        reverse(ss.begin(), ss.end());
        if (s == a || ss == b) {
            return true;
        }
        if (a.size() % 2) {
            va[a.size() / 2] = 1;
            vb[a.size() / 2] = 1;
        }
        int n = a.size();
        for (int i = a.size() / 2 - 1; i >= 0; i--) {
            if (a[i] != a[n - i - 1])
                break;
            va[i] = 1;
        }
        for (int i = a.size() / 2 - 1; i >= 0; i--) {
            if (b[i] != b[n - i - 1])
                break;
            vb[i] = 1;
        }
        //for (int i = 0; i < a.size(); i++) cout << va[i] << " ";
        //cout << endl;
        bool mx = 0;
        for (int i = 0, j = a.size() - 1; i < a.size() / 2; i++, j--) {
            if (a[i] != b[j])
                break;
            if (vb[i + 1] == 1 || va[i + 1] == 1 || 2 * (i + 1) == a.size()) {
                mx = 1;
                break;
            }
        }
        swap(b, a);
        for (int i = 0, j = a.size() - 1; i < a.size() / 2 && !mx; i++, j--) {
            if (a[i] != b[j])
                break;
            if (va[i + 1] == 1 || vb[i + 1] == 1 || 2 * (i + 1) == a.size()) {
                mx = 1;
                break;
            }
        }
        return mx;
    }
};

class Solution {
public:
    int maxDepth(string s) {
        stack<int> st;
        int mx = 0;
        for (auto i : s) {
            if (i == '(') {
                st.push(i);
            }
            else if (i == ')') {
                st.pop();
            }
            mx = max(mx, (int)st.size());
        }
        return mx;
    }
};

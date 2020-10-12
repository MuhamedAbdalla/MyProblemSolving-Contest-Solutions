class Solution {
public:
    static const long long MOD = 1e9 + 7;
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        vector<int> v(nums.size() + 5, 0);
        for (auto i : requests){
            v[i[0] + 1]++;
            v[i[1] + 2]--;
        }
        v[0] = 0;
        for (int i = 1; i <= nums.size() + 2; i++) {
            v[i] += v[i - 1];
        }
        priority_queue<int> q;
        for (int i = 1; i <= nums.size(); i++) {
            if (v[i] > 0) {
                q.push(v[i]);
            }
        }
        sort(nums.begin(), nums.end());
        long long res = 0;
        while (q.size()) {
            long long n = q.top(), val = nums.back();
            res += ((n * val) % MOD);
            res %= MOD;
            nums.pop_back(), q.pop();
        }
        return res;
    }
};

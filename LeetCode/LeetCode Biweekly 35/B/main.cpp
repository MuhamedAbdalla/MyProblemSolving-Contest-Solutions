class Solution {
public:
    map<long long, set<int>> v;
    
    int minSubarray(vector<int>& nums, int p) {
        long long pref = nums[0];
        int mn = 2e9;
            v[pref % p].insert(0);
        for (int i = 1; i < nums.size() - 1; i++) {
            if (pref % p == 0) {
                mn = min(mn, (int)nums.size() - i);
            }
            pref += nums[i];
            v[pref % p].insert(-i);
        }
        if ((pref + nums.back()) % p == 0) {
            mn = 0;
        }
        reverse(nums.begin(), nums.end());
        pref = nums[0];
        for (int i = 1; i < nums.size() - 1; i++) {
            if (pref % p == 0) {
                mn = min(mn, (int)nums.size() - i);
            }
            if (v[p - (pref % p)].size()) {
                int indx = nums.size() - i;
                indx *= -1;
                auto it = v[p - (pref % p)].upper_bound(indx);
                if (it != v[p - (pref % p)].end()) {
                    int l = (*it) * -1;
                    int r = indx * -1;
                    mn = min(mn, abs(l - r) - 1);
                }
            }
            pref += nums[i];
        }
        if (mn == 2e9) return -1;
        return mn;
    }
};

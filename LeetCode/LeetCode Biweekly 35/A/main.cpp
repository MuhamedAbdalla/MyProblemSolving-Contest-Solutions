class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int res = 0;
        for (int i = 0; i < arr.size(); i++) {
            int s = 0;
            for (int j = i; j < arr.size(); j++) {
                s += arr[j];
                if ((j - i + 1) % 2 != 0) res += s;
            }
        }
        return res;
    }
};

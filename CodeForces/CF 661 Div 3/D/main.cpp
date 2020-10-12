#include <bits/stdc++.h>

using namespace std;

const int MAX = 2e5 + 5;
int a[MAX];
set<int> zero, one;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    int t;
    cin >> t;
    while(t--) {
        int n;
        string s;
        cin >> n >> s;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '0') {
                zero.insert(i);
            }
            else {
                one.insert(i);
            }
        }
        int res = 1, last = -1;
        bool now = 0;
        now = (one.size() == 0 ? 0 : zero.size() == 0 ? 1 : (*one.begin() < *zero.begin()));
        while(one.size() || zero.size()) {
            if(!now) {
                auto it = zero.upper_bound(last);
                if(it != zero.end()) {
                    last = *it;
                    zero.erase(it);
                    a[last] = res;
                }
                else {
                    res++;
                    last = -1;
                    now = (one.size() == 0 ? 0 : zero.size() == 0 ? 1 : (*one.begin() < *zero.begin()));
                    now ^= 1;
                }
            }
            else {
                auto it = one.upper_bound(last);
                if(it != one.end()) {
                    last = *it;
                    one.erase(it);
                    a[last] = res;
                }
                else {
                    res++;
                    last = -1;
                    now = (one.size() == 0 ? 0 : zero.size() == 0 ? 1 : (*one.begin() < *zero.begin()));
                    now ^= 1;
                }
            }
            now ^= 1;
        }
        cout << res << endl;
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }
    return 0;
}

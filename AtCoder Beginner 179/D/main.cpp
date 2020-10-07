#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n,k;
    cin >> n >> k;
    int l[k],r[k];
    for(int i = 0; i < k; i++){
        cin >> l[i] >> r[i];
    }
    int dp[n + 5] = {};
    int pref[n + 5] = {};
    dp[1] = 1;
    pref[1] = 1;
    for(int i = 2; i <= n; i++){
        for(int j = 0; j < k; j++){
            if(i <= l[j])
                continue;
 
            int left = l[j];
            int right = min(r[j], i - 1);
            int val = (pref[i - left] - pref[i- right - 1] + mod) % mod;
            
            dp[i] = (dp[i] + val ) % mod;
        }
        pref[i] = (pref[i - 1] % mod + dp[i] % mod) % mod;
    }
    cout << dp[n] << endl;
    return 0;
}





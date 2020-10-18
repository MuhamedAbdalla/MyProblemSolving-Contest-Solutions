#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>

#define ll long long
#define ld double
#define oo 2e18
#define OS tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define rnd mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;

const int N = 2e4 + 5;
int nxt[N];
stack<ll> st;
string s;

pair<ll, ll> solve(ll l, ll r) {
    pair<ll, ll> re = {0, 0};
    for (int i = l + 1; i < r; i++) {
        if (s[i] == '(') {
            pair<ll, ll> pq = solve(i, nxt[i]);
            i = nxt[i];
            re.first += pq.first;
            re.second += pq.second;
        } else if (!(s[i] >= '1' && s[i] <= '9')) {
            if (s[i] == 'N') {
                re.first--;
            } else if (s[i] == 'S') {
                re.first++;
            } else if (s[i] == 'W') {
                re.second--;
            } else if (s[i] == 'E') {
                re.second++;
            }
        }
        re.first %= int(1e9);
        re.second %= int(1e9);
    }
    if (l - 1 >= 0 && (s[l - 1] >= '1' && s[l - 1] <= '9')) re.first *= (s[l - 1] - '0'), re.second *= (s[l - 1] - '0');
    re.first %= int(1e9);
    re.second %= int(1e9);
    return re;
}

void rec() {
    cin >> s;
    ll indx = 0, fn = -1;
    s.push_back(')');
    reverse(s.begin(), s.end());
    s.push_back('(');
    reverse(s.begin(), s.end());
    for (auto i : s) {
        if (i == '(') {
            if (fn == -1) fn = indx;
            st.push(indx);
        } else if (i == ')') {
            nxt[st.top()] = indx;
            st.pop();
        }
        indx++;
    }
    pair<ll, ll> pq;
    if (fn == -1)
        pq = solve(-1, s.size());
    else
        pq = solve(fn, nxt[fn]);
    if (fn - 1 >= 0 && (s[fn - 1] >= '1' && s[fn - 1] <= '9')) {
        pq.first *= (s[fn - 1] - '0');
        pq.second *= (s[fn - 1] - '0');
    }
    ll x = 1, y = 1;
    if (pq.first >= 0) {
        pq.first %= int(1e9);
        x = (pq.first + x);
    } else {
        pq.first = abs(pq.first);
        pq.first %= int(1e9);
        if (pq.first > 0) {
            x = 1e9;
            pq.first--;
            x -= pq.first;
        }
    }
    if (pq.second >= 0) {
        pq.second %= int(1e9);
        y = (pq.second + y);
    } else {
        pq.second = abs(pq.second);
        pq.second %= int(1e9);
        if (pq.second > 0) {
            y = 1e9;
            pq.second--;
            y -= pq.second;
        }
    }
    cout << y << " " << x << endl;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    int c = 1;
    while (t--) {
        cout << "Case #" << c << ": ";
        rec();
        c++;
    }
    return 0;
}

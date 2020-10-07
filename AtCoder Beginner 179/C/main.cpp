#include <bits/stdc++.h>

using namespace std;

int countDivisors(int n)
{
    int cnt = 0;
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            // If divisors are equal,
            // count only one
            if (n / i == i)
                cnt++;

            else // Otherwise count both
                cnt = cnt + 2;
        }
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    cin >> n;
    long long res = 0;
    for (int i = 1; i < n; i++) {
        res += countDivisors(n - i);
    }
    cout << res << endl;
    return 0;
}





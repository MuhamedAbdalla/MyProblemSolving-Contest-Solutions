#include <bits/stdc++.h>
#define MOD 998244353
#define MOD2 1000000007
typedef long long int ll;

using namespace std;


ll Lpow(ll a,ll b)
{
    ll ans = 1;
    while(b > 0)
    {
        if(b%2)
            ans = (ans*a);
        a = (a*a);
        b = b/2;
    }
    return ans;
}
 
ll Lpow(ll a,ll b,ll M)
{
	ll ans = 1;
	while(b > 0)
	{
		if(b%2)
			ans = (ans*a)%M;
		a = (a*a)%M;
		b = b/2;
	}
	return ans;
}
 
ll fact[4005];
ll invfact[4005];
 
void pre()
{
	fact[0] = 1;
	invfact[0] = 1;
	for(ll i = 1;i <= 4000;i++)
	{
		fact[i] = i*fact[i-1]%MOD2;
		invfact[i] = Lpow(fact[i],MOD2-2,MOD2);
	}
}
 
ll fun(ll i,ll ext)
{
	ll num = i + ext-1;
	ll de = i - 1;
	ll ans = ((fact[num] * invfact[num - de])%MOD2 * invfact[de])%MOD2;
	return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    ll n;
    cin >> n;

    pre();

    ll lim = n/3;
    ll ext = n%3;

    ll ans = 0;
    for(int i = lim;i>=1;i--) {	
	ll tmp = fun(i,ext);
	ans = (ans + tmp)%MOD2;
	ext += 3;
    }

    cout << ans << endl;
    return 0;
}





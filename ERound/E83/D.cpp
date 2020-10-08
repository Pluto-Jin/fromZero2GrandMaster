#include "bits/stdc++.h"
using namespace std;

#define fi first
#define se first
#define endl '\n'
#define pb push_back
#define mp make_pair
typedef pair<int,int> pii;
typedef long long ll;
const int mod=998244353;
int fpow(ll a,ll b)
{
	ll res=1;
	while (b) {
		if (b%2) {b--;res=res*a%mod;}
		a=a*a%mod;
		b/=2;
	}
	return res;
}
int comb(ll a,ll b)
{
	ll x=1;
	for (ll i=0;i<b;i++) x=x*(a-i)%mod;
	for (ll i=1;i<=b;i++) x=x*fpow(i,mod-2)%mod;
	return x;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
	ll n,m;
	cin>>n>>m;
	if (n==2) {cout<<0<<endl;return 0;}
	ll ans=comb(m,n-1)%mod*(n-2)%mod*fpow(2,n-3)%mod;
	cout<<ans<<endl;

}

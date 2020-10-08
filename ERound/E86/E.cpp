#include "bits/stdc++.h"
using namespace std;

#define fi first
#define se second
#define pb push_back
#define ppf pop_front
#define ppb pop_back
#define mp make_pair
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<vi> vvi;

const int MOD=998244353,N=2e5+1;
int fac[N],ifac[N];

ll fpow(ll a,ll b) {
	ll res=1;
	while (b) {
		if (b%2) res=res*a%MOD;
		b/=2;
		a=a*a%MOD;	
	}
	return res;
}
ll comb(ll a,ll b) {
	return 1ll*fac[a]*ifac[b]%MOD*ifac[a-b]%MOD;
}
ll S(ll n,ll m) {
	ll res=0;
	for (ll i=0;i<=m;i++) {
		if (i%2) res+=MOD-comb(m,i)*fpow(m-i,n)%MOD,res%=MOD;
		else res+=comb(m,i)*fpow(m-i,n)%MOD,res%=MOD;
	}
	return res;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	ll n,k; cin>>n>>k;
	fac[0]=1;
	for (int i=1;i<=n;i++) fac[i]=1ll*i*fac[i-1]%MOD;
	for (int i=0;i<=n;i++) ifac[i]=fpow(fac[i],MOD-2);
	if (k>n-1) cout<<0<<endl;
	else {
		ll res=comb(n,n-k)*S(n,n-k)%MOD;
		if (k) res=res*2%MOD;
		cout<<res<<endl;
	}
}


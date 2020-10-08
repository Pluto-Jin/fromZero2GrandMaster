#include "bits/stdc++.h"
using namespace std;

#define fi first
#define se second
#define endl '\n'
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

const int N=4e7,MOD=998244353;

ll fpow(ll a,ll b) {
	ll res=1;
	while (b) {
		if (b%2) res*=a,res%=MOD;
		b/=2;
		a*=a,a%=MOD;
	}
	return res;
} 

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	ll fac[60],frev[60],d; cin>>d;
	vector<ll> pr;
	for (ll i=2;i*i<=d;i++) {
		if (d%i) continue;
		else {
			pr.pb(i);
			while (d%i==0) d/=i;
		}
	}
	if (d>1) pr.pb(d);
	fac[0]=1;
	for (ll i=1;i<60;i++) fac[i]=i*fac[i-1]%MOD,frev[i]=fpow(fac[i],MOD-2);
	int cnt=pr.size(),q; cin>>q;
	while (q--) {
		ll u,v,a=0,b=0; cin>>u>>v;
		vi ar(cnt),br(cnt);
		for (int i=0;i<cnt;i++) {
			while (u%pr[i]==0) u/=pr[i],ar[i]++;
			while (v%pr[i]==0) v/=pr[i],br[i]++;
			int tmp=min(ar[i],br[i]);
			ar[i]-=tmp,br[i]-=tmp;
		}
		u=1,v=1;
		for (int i=0;i<cnt;i++) {
			if (ar[i]) a+=ar[i],u*=frev[ar[i]],u%=MOD;
			if (br[i]) b+=br[i],v*=frev[br[i]],v%=MOD;
		}
		if (a) u*=fac[a],u%=MOD;
		if (b) v*=fac[b],v%=MOD;
		cout<<u*v%MOD<<endl;
	}
}


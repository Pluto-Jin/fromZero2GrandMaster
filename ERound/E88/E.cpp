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

const int MOD=998244353,N=5e5+1;
int fac[N],ifac[N],inv[N];

ll fpow(ll a,ll b) {
	ll res=1;
	while (b) {
		if (b&1) res*=a,res%=MOD;
		b/=2;
		a*=a,a%=MOD;
	}
	return res;
}

ll comb(int a,int b) {return 1ll*fac[a]*ifac[b]%MOD*ifac[a-b]%MOD;}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int n,k; cin>>n>>k;
	fac[0]=ifac[0]=inv[1]=1;
	for (int i=1;i<=n;i++) fac[i]=1ll*fac[i-1]*i%MOD;
	for (int i=2;i<=n;i++) inv[i]=1ll*(MOD-MOD/i)*inv[MOD%i]%MOD;
	for (int i=1;i<=n;i++) ifac[i]=1ll*ifac[i-1]*inv[i]%MOD;

	int ans=0;
	for (int i=1;i<=n;i++) {
		int cnt=n/i-1;
		if (cnt<k-1) break;
		ans+=comb(cnt,k-1);
		ans%=MOD;
	}
	cout<<ans<<endl;
}


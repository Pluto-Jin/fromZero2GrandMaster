#include "bits/stdc++.h"
using namespace std;

#define fi first
#define se second
#define endl '\n'
#define pb push_back
#define ppf pop_front
#define ppb pop_back
#define mp make_pair
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef long long ll;

const int K=31,N=5e5+2,mod=998244353;
int n,m,k,l[N],r[N],x[N];
int ones[N],mx[N],sum[N];
ll ans=1;

void solve(int bit) {
	fill(ones,ones+N,0);
	fill(mx,mx+N,-1);
	for (int i=0;i<m;i++) {
		if (x[i]&(1<<bit)) ones[l[i]]++,ones[r[i]+1]--;
		else mx[r[i]]=max(mx[r[i]],l[i]);
	}
	int pre=-1;
	sum[0]=1;
	for (int i=1;i<=n;i++) {
		int cur=0;
		if (!ones[i]) cur=sum[i-1]-(pre==-1?0:sum[pre-1]);
		while (cur<0) cur+=mod;
		ones[i+1]+=ones[i];
		pre=max(pre,mx[i]);
		sum[i]=sum[i-1]+cur, sum[i]%=mod;
	}
	int cur=sum[n]-(pre==-1?0:sum[pre-1]);
	while (cur<0) cur+=mod;
	ans*=cur,ans%=mod;
}

ll fpow(ll a, ll b) {
	ll res=1;
	while (b) {
		if (b%2) res=res*a%mod;
		b/=2;
		a=a*a%mod;
	}
	return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	cin>>n>>k>>m;
	if (!m) {
		cout<<fpow(1<<k,n)<<endl;
		return 0;
	}
	for (int i=0;i<m;i++) cin>>l[i]>>r[i]>>x[i];
	for (int i=0;i<k;i++) solve(i);
	cout<<ans<<endl;
}


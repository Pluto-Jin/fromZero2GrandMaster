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

const int N=1e5+1,MOD=1e9+7;
vi edge[N];
vector<ll> cnt;

int dfs(int at=1,int par=-1) {
	int res=1;
	for (auto to:edge[at]) if (to!=par) {
		int tmp=dfs(to,at);
		cnt.pb(tmp);
		res+=tmp;
	}
	return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int t; cin>>t;
	while (t--) {
		int n; cin>>n;
		cnt.resize(0);
		for (int i=1;i<=n;i++) edge[i].resize(0);
		for (int i=1;i<n;i++) {
			int x,y; cin>>x>>y;
			edge[x].pb(y);
			edge[y].pb(x);
		}
		int m; cin>>m;
		vector<ll> pr(m);
		for (auto &i:pr) cin>>i;
		sort(pr.begin(),pr.end());
		if (m>n-1) {
			for (int i=n-1;i<m;i++) pr[n-2]*=pr[i],pr[n-2]%=MOD;
		} else {
			for (int i=0;i<n-1-m;i++) pr.pb(1);
			sort(pr.begin(),pr.end());
		}
		dfs();
		for (auto &i:cnt) i=i*(n-i);
		sort(cnt.begin(),cnt.end());
		ll ans=0;
		assert(cnt.size()==n-1);
		for (int i=0;i<n-1;i++) {
			ans+=cnt[i]%MOD*pr[i]%MOD;
			ans%=MOD;	
		}
		cout<<ans<<endl;

	}
}


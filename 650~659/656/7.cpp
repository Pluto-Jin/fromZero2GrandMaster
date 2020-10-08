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

const int N=2e5+1;
int vis[N];
vi ea[N],eb[N];

void dfs(int at,int &cnt,int &tot,vi &tmp1,vi &tmp2,int clr=1) {
	tot+=vis[at]=1;
	cnt+=clr;
	if (clr) tmp1.pb(at);
	else tmp2.pb(at);
	for (auto to:ea[at]) if (!vis[to]) dfs(to,cnt,tot,tmp1,tmp2,clr^1);
	for (auto to:eb[at]) if (!vis[to]) dfs(to,cnt,tot,tmp1,tmp2,clr);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int t; cin>>t;
	while (t--) {
		int n; cin>>n;
		vi pos(n+1),cnt(n+1);
		for (int i=1;i<=n;i++) vis[i]=0,ea[i].resize(0),eb[i].resize(0);
		for (int i=1;i<=n;i++) {
			int x; cin>>x; cnt[x]++;
			if (cnt[x]==1) pos[x]=i;
			if (cnt[x]==2) ea[pos[x]].pb(i),ea[i].pb(pos[x]);	
		}
		for (int i=1;i<=n;i++) {
			int x; cin>>x; cnt[x]++;
			if (cnt[x]==1) pos[x]=-i;
			if (cnt[x]==2) {
				if (pos[x]==i) vis[i]=1;
				else if (pos[x]>0) eb[pos[x]].pb(i),eb[i].pb(pos[x]);
				else if (pos[x]<0) ea[-pos[x]].pb(i),ea[i].pb(-pos[x]);
			}
		}
		int ok=1;
		for (int i=1;i<=n;i++) if (cnt[i]!=2) ok=0;
		if (!ok) cout<<-1<<endl;
		else {
			int ans=0;
			vi res;
			for (int i=1;i<=n;i++) if (!vis[i]) {
				int cnt=0,tot=0;
				vi tmp1,tmp2;
				dfs(i,cnt,tot,tmp1,tmp2);
				ans+=min(cnt,tot-cnt);
				if (cnt<=tot-cnt) for (auto i:tmp1) res.pb(i);
				else for (auto i:tmp2) res.pb(i);
			}
			cout<<ans<<endl;
			for (auto i:res) cout<<i<<' ';
			cout<<endl;
		}	
	}
}


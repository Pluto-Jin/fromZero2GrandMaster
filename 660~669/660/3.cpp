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

const int N=1e5+1;
int n,m,ar[N],cnt[N],h[N],okk;
vi edge[N];

int dfs(int at=1,int par=-1) {
	for (auto to:edge[at]) if (to!=par) cnt[at]+=dfs(to,at);
	return cnt[at];
}

int dfs2(int at=1,int par=-1) {
	if (at!=1 and edge[at].size()==1) return h[at];
	int tmp=0;
	for (auto to:edge[at]) if (to!=par) tmp+=dfs2(to,at);
	if (tmp-ar[at]>h[at]) okk=0;
	return h[at];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int t; cin>>t; 
	while (t--) {
		cin>>n>>m;
		okk=1;
		for (int i=1;i<=n;i++) edge[i].resize(0),cin>>cnt[i],ar[i]=cnt[i];
		for (int i=1;i<=n;i++) cin>>h[i];
		for (int i=1;i<n;i++) {
			int x,y; cin>>x>>y;
			edge[x].pb(y); edge[y].pb(x);
		}
		dfs();
		int ok=1;
		for (int i=1;ok and i<=n;i++) if ((cnt[i]-h[i])%2 or h[i]>cnt[i] or h[i]<-cnt[i]) ok=0;
		dfs2();
		if (!ok or !okk) cout<<"NO"<<endl;
		else cout<<"YES"<<endl;

	}
}


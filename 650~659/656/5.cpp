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
int n,m,deg[N],cnt;
vi edge[N],ud[N];

vii solve() {
	vector<bool> vis(n+1);
	vii ans;
	queue<int> q;
	for (int i=1;i<=n;i++) if (!deg[i]) q.push(i);
	while (q.size()) {
		int at=q.front(); q.pop();
		vis[at]=1;
		cnt++;
		for (auto to:ud[at]) if (!vis[to]) ans.pb(mp(at,to));
		for (auto to:edge[at]) if (!--deg[to]) q.push(to);
	}
	return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int t; cin>>t;
	while (t--) {
		cin>>n>>m;
		for (int i=0;i<m;i++) {
			int t,x,y; cin>>t>>x>>y;
			if (t) edge[x].pb(y),deg[y]++;
			else ud[x].pb(y),ud[y].pb(x);
		}
		vii ans=solve();
		if (cnt!=n) cout<<"NO"<<endl;
		else {
			cout<<"YES"<<endl;
			for (auto i:ans) cout<<i.fi<<' '<<i.se<<endl;
			for (int i=1;i<=n;i++) for (auto to:edge[i]) cout<<i<<' '<<to<<endl;
		}	
		for (int i=1;i<=n;i++) edge[i].resize(0),ud[i].resize(0),deg[i]=0;
		cnt=0;
	}
}


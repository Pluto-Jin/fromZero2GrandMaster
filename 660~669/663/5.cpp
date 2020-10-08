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

const int N=5e5+1;
int n,m,fa[N],vis[N],ans;
vi edge[N],d[N];

void dfs(int at=1,int dep=0) {
	if (dep>=(n+1)/2) {ans=at;return;}
	vis[at]=1;
	d[dep].pb(at);
	for (auto to:edge[at]) if (!vis[to]) {
		fa[to]=at;
		dfs(to,dep+1);
		if (ans) return;
	}	
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int t; cin>>t;
	while (t--) {
		cin>>n>>m;
		ans=0;
		for (int i=0;i<=n;i++) vis[i]=0,edge[i].resize(0),d[i].resize(0);
		for (int i=0;i<m;i++) {
			int x,y; cin>>x>>y;
			edge[x].pb(y);
			edge[y].pb(x);
		}
		dfs();
		if (ans) {
			cout<<"PATH"<<endl;
			vi path;
			for (int at=ans;at;at=fa[at]) path.pb(at);
			cout<<path.size()<<endl;
			for (auto i:path) cout<<i<<' '; cout<<endl;
		} else {
			cout<<"PAIRING"<<endl;
			vii pir;
			for (int i=0;d[i].size();i++) 
				for (int j=0;j+1<d[i].size();j+=2) pir.pb(mp(d[i][j],d[i][j+1]));
			cout<<pir.size()<<endl;
			for (auto [a,b]:pir) cout<<a<<' '<<b<<endl;
		}
	}
}


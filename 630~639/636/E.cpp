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

const int N=2e5+1;
int d[3][N], n,m;
bool vis[N];
vi edge[N];

void bfs(int ind, int root, int x) 
{
	memset(vis,0,sizeof(vis));
	auto &dep=d[ind];
	dep[root]=0;
	vis[root]=true;
	queue<int> q;
	q.push(root);
	while (!q.empty()) {
		int at=q.front(); q.pop();
		for (auto to:edge[at]) {
			if (vis[to]) continue;
			vis[to]=true;
			dep[to]=dep[at]+1;
			q.push(to);
		}
	}
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int t; cin>>t;
	while (t--) {
		int a,b,c; cin>>n>>m>>a>>b>>c;
		vector<ll> ar(m+1),sum(m+1);
		for (int i=1;i<=m;i++) cin>>ar[i];
		sort(ar.begin(),ar.end());
		for (int i=1;i<=m;i++) sum[i]=sum[i-1]+ar[i];
		for (int i=1;i<=m;i++) {
			int x,y; cin>>x>>y;
			edge[x].pb(y);
			edge[y].pb(x);
		}
		bfs(0,a,b);
		bfs(1,c,b);
		bfs(2,b,-1);
		ll ans=1e15;
		for (int i=1;i<=n;i++) {
			if (d[0][i]==-1 or d[1][i]==-1) continue;
			int fb=d[2][i],fac=d[0][i]+d[1][i];
			if (fb+fac>m) continue;
			ans=min(ans,sum[fb]+sum[fb+fac]);
		}
		cout<<ans<<endl;
		for (int i=1;i<=n;i++) edge[i].resize(0);
	}
}


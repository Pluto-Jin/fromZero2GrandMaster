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
int n,m,a,b,vis[N]; 
ll ans;
vi edge[N];

pii dfs(int at,int rt) {
	vis[at]=1;
	int ok=(at==a+b-rt),cnt=0;
	for (auto to:edge[at]) if (!vis[to]) {
		auto [x,y]=dfs(to,rt);
		if (x) ok=1;
		else cnt+=y;
	}
	if (at==rt) ans*=cnt;
	return mp(ok,cnt+1);
}  

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int t; cin>>t;
	while (t--) {
		cin>>n>>m>>a>>b;
		ans=1;
		for (int i=1;i<=n;i++) edge[i].resize(0);
		for (int i=0;i<m;i++) {
			int x,y; cin>>x>>y;
			edge[x].pb(y);
			edge[y].pb(x);
		}
		for (int i=1;i<=n;i++) vis[i]=0;
		dfs(a,a);
		for (int i=1;i<=n;i++) vis[i]=0;
		dfs(b,b);
		cout<<ans<<endl;
	}
}


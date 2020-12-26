#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<set>
#include<map>
#include<bitset>
#include<string>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<iomanip>

#define fi first
#define se second
#define endl '\n'
#define pb push_back
#define ppf pop_front
#define ppb pop_back
#define mp make_pair
typedef long long ll;
typedef std::pair<int,int> pii;
typedef std::pair<ll,ll> pll;
typedef std::vector<int> vi;
typedef std::vector<pii> vii;
typedef std::vector<std::vector<int>> vvi;

using namespace std;

template<class T,class T2>
inline bool chkmax(T &x,const T2 &y){return x<y?(x=y,1):0;}
template<class T,class T2>
inline bool chkmin(T &x,const T2 &y){return x>y?(x=y,1):0;}

const int N=1e5+1;
int n,m,up[N][21],dep[N],dif[N];
vi edge[N];

void dfs(int at=1,int par=1) {
	up[at][0]=par; dep[at]=dep[par]+1;
	for (int i=1;i<21;i++) up[at][i]=up[up[at][i-1]][i-1];
	for (auto to:edge[at]) if (to!=par) dfs(to,at);
}

int lca(int u,int v) {
	if (dep[u]<dep[v]) swap(u,v);
	for (int i=20;~i;i--) if (dep[up[u][i]]>=dep[v]) u=up[u][i];
	if (u==v) return u;
	for (int i=20;~i;i--) if (up[u][i]!=up[v][i]) u=up[u][i],v=up[v][i];
	return up[u][0];
}

int dfs2(int at=1,int par=-1) {
	for (auto to:edge[at]) if (to!=par) dif[at]+=dfs2(to,at);
	return dif[at];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	cin>>n>>m;
	for (int i=1;i<n;i++) {
		int x,y; cin>>x>>y;
		edge[x].pb(y);
		edge[y].pb(x);
	}
	dfs();
	for (int i=0;i<m;i++) {
		int x,y; cin>>x>>y;
		dif[x]++,dif[y]++;
		dif[lca(x,y)]-=2;
	} 
	dfs2();
	int ans=0;
	for (int i=2;i<=n;i++) {
		if (dif[i]==0) ans+=m;
		if (dif[i]==1) ans++;
	}
	cout<<ans<<endl;
	
	return 0;
}

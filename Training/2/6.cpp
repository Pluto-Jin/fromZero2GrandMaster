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
#include<numeric>
#include<cstdlib>
#include<ctime>
#include<iomanip>

#define fi first
#define se second
#define endl '\n'
#define pb push_back
#define eb emplace_back
#define ppf pop_front
#define ppb pop_back
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
int n,m,up[N][21],dep[N],dp[N][4],f[N][21][2];
vi edge[N];

void pass(int x,int at) {
	if (x>=dp[at][1]) dp[at][3]=dp[at][2],dp[at][2]=dp[at][1],dp[at][1]=x;
	else if (x>=dp[at][2]) dp[at][3]=dp[at][2],dp[at][2]=x;
	else if (x>=dp[at][3]) dp[at][3]=x;
}

void dfs(int at=1,int par=1,int d=0) {
	dep[at]=d; up[at][0]=par;
	for (int i=1;i<21;i++) up[at][i]=up[up[at][i-1]][i-1];
	for (auto to:edge[at]) if (to!=par)
		dfs(to,at,d+1),pass(dp[to][1]+1,at);
} 

void dfs2(int at=1,int par=1,int d=0) {
	dp[at][0]=d;
	for (auto to:edge[at]) if (to!=par) {
		if (dp[to][1]+1==dp[at][1]) dfs2(to,at,max(d,dp[at][2])+1);
		else dfs2(to,at,max(d,dp[at][1])+1);
	}
}

int lca(int u,int v) {
	if (dep[u]<dep[v]) swap(u,v);
	for (int i=20;~i;i--) if (dep[up[u][i]]>=dep[v]) u=up[u][i];
	if (u==v) return v;
	for (int i=20;~i;i--) if (up[u][i]!=up[v][i]) u=up[u][i],v=up[v][i];
	return up[u][0];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int n; cin>>n;
	for (int i=1;i<n;i++) {
		int x,y; cin>>x>>y;
		edge[x].pb(y),edge[y].pb(x);
	}
	dfs(); dfs2();
	for (int k=0;k<21;k++) for (int i=1;i<=n;i++) {
		int par=up[i][k];
		if (!k) f[i][k][0]=(dp[i][1]+1==dp[par][1]?dp[par][2]+1:dp[par][1]+1);
		else f[i][k][0]=max(f[i][k-1][0],f[up[i][k-1]][k-1][0]+(1<<k-1));
		if (!k) f[i][k][1]=(dp[par][1]-1==dp[i][1]?dp[par][2]:dp[par][1]);
		else f[i][k][1]=max(f[up[i][k-1]][k-1][1],f[i][k-1][1]+(1<<k-1));
	}
	int m; cin>>m;
	while (m--) {
		int x,y; cin>>x>>y;
		if (x==y) {
			cout<<max(dp[x][1],dp[x][0])<<endl;
			continue;
		}
		if (dep[x]<dep[y]) swap(x,y);
		int fa=lca(x,y),sx=dep[x]-dep[fa],sy=dep[y]-dep[fa],ans=dp[fa][0]+sy,mid=sx+sy>>1;
		chkmax(ans,max(dp[x][1],fa==y?0:dp[y][1]));
		for (int k=20,tmp=0;~k;k--) if (min(mid,sx-1)>>k&1) chkmax(ans,tmp+f[x][k][0]),x=up[x][k],tmp+=1<<k;
		for (int k=20,tmp=sx-mid;~k;k--) if (max(sx-mid-1,0)>>k&1) tmp-=1<<k,chkmax(ans,tmp+f[x][k][1]+sy),x=up[x][k];
		for (int k=20,tmp=0;~k;k--) if (max(sy-1,0)>>k&1) chkmax(ans,tmp+f[y][k][0]),y=up[y][k],tmp+=1<<k;
		if (fa==y) {
			if (dp[fa][1]!=1+dp[x][1]) chkmax(ans,dp[fa][1]+sy);
			else chkmax(ans,dp[fa][2]+sy);
		} else { 
			int a=1+dp[x][1],b=1+dp[y][1];
			if (a<b) swap(a,b);
			if (dp[fa][1]!=a) chkmax(ans,dp[fa][1]+sy);
			else if (dp[fa][2]!=b) chkmax(ans,dp[fa][2]+sy);
			else chkmax(ans,dp[fa][3]+sy);
		}
		cout<<ans<<endl;
	}

	
	return 0;
}

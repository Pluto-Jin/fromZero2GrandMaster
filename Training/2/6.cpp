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
int n,m,up[N][21],dep[N],dp[N][4];
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

int lca(int u,int v,int &sx,int &sy) {
	if (dep[u]<dep[v]) swap(u,v);
	for (int i=20;~i;i--) if (dep[up[u][i]]>dep[v]) u=up[u][i],sx+=1<<i;
	u=up[u][0],sx++;
	if (u==v) return v;
	for (int i=20;~i;i--) if (up[u][i]!=up[v][i]) u=up[u][i],v=up[v][i],sx+=1<<i,sy+=1<<i;
	sx++,sy++;
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
	int m; cin>>m;
	while (m--) {
		int x,y; cin>>x>>y;
		if (dep[x]<dep[y]) swap(x,y);
		int sx=0,sy=0,fa=lca(x,y,sx,sy),ans=0;
		cout<<fa<<' '<<sx<<' '<<sy<<endl;
		for (auto j:{x,y,fa}) {
			for (int i=0;i<4;i++) cout<<dp[j][i]<<' ';
			cout<<endl;
		}
		chkmax(ans,max(dp[fa][0]+sy,sx+sy>>1));
		if (fa==y) {
			chkmax(ans,dp[x][0]);
			if (dp[y][1]!=sx+dp[x][1]) chkmax(ans,dp[y][1]);
			else chkmax(ans,dp[y][2]);
		} else {
			chkmax(ans,max(dp[x][0],dp[y][0]));
		if (dp[fa][1]!=sx+dp[x][1] and dp[fa][1]!=sy+dp[y][0]) chkmax(ans,dp[fa][1]+sy);
		else if (dp[fa][2]!=sx+dp[x][0] and dp[fa][2]!=sy+dp[y][0]) chkmax(ans,dp[fa][2]+sy);
		else chkmax(ans,dp[fa][3]+sy);
		cout<<ans<<endl;
	}

	
	return 0;
}

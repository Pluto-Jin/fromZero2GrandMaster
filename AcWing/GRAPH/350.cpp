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
int n,k,ma[N],zj,dp[N][2];
vii edge[N];

int dfs(int at,int par=-1,int dep=0) {
	chkmax(zj,ma[at]=dep);
	for (auto [to,w]:edge[at]) if (to!=par) chkmax(ma[at],dfs(to,at,dep+1));	
	return ma[at];
}

void dfs2(int at,int par=-1) {
	for (auto &[to,w]:edge[at]) if (to!=par and ma[to]==zj) {
		w=-1; dfs2(to,at);
		return;
	}
}

void dfs3(int at,int par=-1) {
	int m1=-1e9,m2=-1e9;
	for (auto [to,w]:edge[at]) if (to!=par) {
		dfs3(to,at);
		chkmax(dp[at][0],dp[to][0]);
		int x=dp[to][1]+w;
		if (x>=m1) m2=m1,m1=x;
		else if (x>m2) m2=x;
	}
	chkmax(dp[at][1],m1);
	chkmax(dp[at][0],max(m1,m1+m2));
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	cin>>n>>k;
	for (int i=1;i<n;i++) {
		int x,y; cin>>x>>y;
		edge[x].pb({y,1});
		edge[y].pb({x,1});
	}
	queue<pii> q; q.push({1,-1});
	int rt;
	while (q.size()) {
		auto [at,par]=q.front(); q.pop();
		for (auto [to,w]:edge[at]) if (to!=par) q.push({to,at});
		if (q.empty()) rt=at;
	}
	dfs(rt),dfs2(rt),dfs3(rt);
	if (k==1) cout<<2*n-1-zj<<endl;
	else cout<<2*n-zj-dp[rt][0]<<endl;
	
	return 0;
}

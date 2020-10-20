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

const int N=2e5+1;
int n,dp[N],ans[N];
vii edge[N];

void dfs(int at,int par=0) {
	for (auto [to,w]:edge[at]) if (to!=par) {
		dfs(to,at);
		int cur=min(dp[to],w);
		dp[at]+=cur;
	}
}

void dfs2(int at,int par=0,int w=0) {
	ans[at]=min(w,ans[par]-min(w,dp[at]))+(edge[at].size()==1?0:dp[at]);
	for (auto [to,we]:edge[at]) if (to!=par) dfs2(to,at,we);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int t; cin>>t;
	while (t--) {
		cin>>n;
		for (int i=1;i<=n;i++) edge[i].resize(0),dp[i]=ans[i]=0;
		for (int i=1;i<n;i++) {
			int x,y,w; cin>>x>>y>>w;
			edge[x].pb(mp(y,w));
			edge[y].pb(mp(x,w));
		}
		if (n==2) {cout<<edge[1][0].se<<endl;continue;}
		int rt;
		for (int i=1;i<=n;i++) {
			if (edge[i].size()==1) dp[i]=(1ll<<31)-1;
			else rt=i;
		}
		dfs(rt);
		dfs2(rt);
		int ma=0;
		for (int i=1;i<=n;i++) ma=max(ma,ans[i]);
		cout<<ma<<endl;
	}
	
	return 0;
}

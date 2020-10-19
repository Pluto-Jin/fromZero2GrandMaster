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

const int N=301;
int n,m,a[N],sz[N],dp[N][N];
vi edge[N];

void dfs(int at=0) {
	for (auto to:edge[at]) {
		dfs(to);
		for (int i=sz[to]+sz[at];i>0;i--)
			for (int j=max(0,i-sz[at]);j<=min(i,sz[to]);j++) chkmax(dp[at][i],dp[at][i-j]+dp[to][j]);
		sz[at]+=sz[to];
	}
	for (int i=++sz[at];i>0;i--) dp[at][i]=dp[at][i-1]+a[at];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	cin>>n>>m;
	for (int i=1;i<=n;i++) {
		int x; cin>>x>>a[i];
		edge[x].pb(i);
	}
	dfs();
	cout<<dp[0][m+1]<<endl;
	
	return 0;
}

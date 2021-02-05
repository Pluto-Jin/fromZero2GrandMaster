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

const int MOD=998244353;
int n,m,self,pre[101],cnt[1<<20],dp[1<<20];
pii fa[21];
vii edge[21];

void dfs(int at=1,int par=0,int id=0) {
	fa[at]={par,id};
	for (auto [to,ind]:edge[at]) if (to!=par) dfs(to,at,ind);
}

void solve() {
	for (int i=n;i<=m;i++) if (pre[i]) 
		for (int j=pre[i];j<1<<n-1;j++,j|=pre[i]) cnt[j]++;
	dp[0]=1;
	for (int i=1;i<1<<n-1;i++) {
		for (int j=0;j<n-1;j++) if (i>>j&1) {
			int tmp=i^1<<j;
			ll cur=dp[tmp];
			for (int k=cnt[tmp];k<cnt[i];k++) cur*=m-self-__builtin_popcount(i)-k,cur%=MOD;
			dp[i]+=cur,dp[i]%=MOD;
		}
	}
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	cin>>n>>m;
	for (int i=1;i<n;i++) {
		int x,y; cin>>x>>y;
		edge[x].eb(y,i),edge[y].eb(x,i);
	}
	dfs();
	for (int i=n;i<=m;i++) {
		int x,y; cin>>x>>y;
		if (x==y) self++;
		else {
			for (auto j:{x,y}) while (fa[j].fi) {
				pre[i]^=1<<fa[j].se-1;
				j=fa[j].fi; 
			}
		}
	}
	solve();
	ll ans=dp[(1<<n-1)-1];
	for (int i=m;i>m-self;i--) ans*=i,ans%=MOD;
	cout<<ans<<endl;
	
	return 0;
}

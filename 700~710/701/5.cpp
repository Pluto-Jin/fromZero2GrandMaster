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

const int N=2e5+1;
int n,a[N],mi[N],ma[N],dep[N];
ll dp[N];
vi edge[N];

void dfs(int at=1,int par=-1,int d=0) {
	dep[at]=d;
	chkmin(mi[d],a[at]);
	chkmax(ma[d],a[at]);
	for (auto to:edge[at]) if (to!=par) dfs(to,at,d+1);
}

ll bfs() {
	ll ans=0;
	queue<pii> q; q.emplace(1,-1);
	for (int cnt=0;cnt<n;) {
		vii tmp;
		ll zh=0,fu=-1e18;
		while (q.size()) {
			auto [at,par]=q.front(); q.pop(); tmp.eb(at,par); cnt++;
			for (auto to:edge[at]) if (to!=par) {
				chkmax(dp[to],dp[at]+max(abs(a[to]-mi[dep[to]]),abs(a[to]-ma[dep[to]])));
				chkmax(zh,dp[at]+a[to]); chkmax(fu,dp[at]-a[to]);
			}
		}
		for (auto [at,par]:tmp) {
			for (auto to:edge[at]) if (to!=par) {
				q.emplace(to,at);
				chkmax(dp[to],max(zh-a[to],fu+a[to]));
				if (edge[to].size()==1) chkmax(ans,dp[to]);
			}
		} 
	}
	return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int tc; cin>>tc;
	while (tc--) {
		cin>>n;
		for (int i=1;i<=n;i++) edge[i].resize(0),mi[i]=1e9,ma[i]=dp[i]=0;
		for (int i=2;i<=n;i++) {
			int x; cin>>x;
			edge[i].pb(x),edge[x].pb(i);
		}
		for (int i=2;i<=n;i++) cin>>a[i];
		dfs();
		cout<<bfs()<<endl;
	}
	
	return 0;
}

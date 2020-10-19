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

const int N=6001;
int n,a[N],dp[N][2],f[N];
vi edge[N];

void dfs(int at=1,int par=-1) {
	dp[at][1]=a[at];
	for (auto to:edge[at]) if (to!=par) {
		dfs(to,at);
		dp[at][0]+=max(dp[to][0],dp[to][1]);
		dp[at][1]+=dp[to][0];
	}
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=1;i<n;i++) {
		int x,y; cin>>x>>y;
		f[x]=1;
		edge[x].pb(y); edge[y].pb(x);
	}	
	int rt;
	for (int i=1;i<=n;i++) if (!f[i]) rt=i;
	dfs(rt,-1);
	cout<<max(dp[rt][0],dp[rt][1])<<endl;
	
	return 0;
}
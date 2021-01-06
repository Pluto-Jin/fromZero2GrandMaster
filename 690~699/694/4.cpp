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

const int N=3e5+1;
int n,m,cnt,vis[N];
vi edge[N],tr[N],ans;

void dfs(int at=1) {
	vis[at]=1,cnt++;
	for (auto to:edge[at]) if (!vis[to]) tr[at].pb(to),dfs(to);
} 

void dfs2(int at=1) {
	if (!vis[at]) {
		vis[at]=1,ans.pb(at);
		for (auto to:edge[at]) if (!vis[to]) vis[to]=1;
	}
	for (auto to:tr[at]) dfs2(to);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int t; cin>>t;
	while (t--) {
		cin>>n>>m;
		for (int i=1;i<=n;i++) edge[i].resize(0),tr[i].resize(0),vis[i]=0;
		for (int i=0;i<m;i++) {
			int x,y; cin>>x>>y;
			edge[x].pb(y);
			edge[y].pb(x);
		}
		cnt=0; dfs();
		if (cnt<n) cout<<"NO"<<endl;
		else {
			for (int i=1;i<=n;i++) vis[i]=0;
			dfs2();
			cout<<"YES"<<endl<<ans.size()<<endl;
			for (auto i:ans) cout<<i<<' ';
			cout<<endl; ans.resize(0);
		}
	}
	
	return 0;
}

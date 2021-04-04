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

const int N=1e6+1;
int to[N];
bool vis[N];
vi ans;

int dfs(int at=0) {
	vis[at]=1;
	if (vis[to[at]]) {
		ans.pb(at);
		if (to[at]==at) return -1;
		return to[at];
	}
	int x=dfs(to[at]);
	if (x==-1) return x;

	ans.pb(at);
	if (x==at) return -1;
	return x;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int t; cin>>t;
	while (t--) {
		int n; cin>>n;
		for (int i=1;i<=n;i++) vis[i]=0;
		ans.resize(0);
		for (int i=0;i<n;i++) {
			int x; cin>>x;
			to[i]=i-x;
		}
		dfs();
		cout<<ans.size()<<endl;
		for (auto i:ans) cout<<i+1<<' '; cout<<endl;
	}
	
	return 0;
}

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
int fa[N];
double a[N],b[N],ans;
vi edge[N];

void dfs(int at=1,int par=0) {
	fa[at]=par;
	for (auto to:edge[at]) if (to!=par) b[at]+=a[to],dfs(to,at);
	ans-=b[at]*a[at];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int n; cin>>n;
	ans=n;
	for (int i=1;i<=n;i++) cin>>a[i],ans-=a[i],a[i]=1-a[i];
	for (int i=1;i<n;i++) {
		int x,y; cin>>x>>y; ++x,++y;
		edge[x].pb(y),edge[y].pb(x);
	}
	dfs();
	int q; cin>>q;
	while (q--) {
		int x; cin>>x; ++x;
		double p; cin>>p;
		p=1-p;
		ans+=p-a[x];
		if (x!=1) ans+=(a[x]-p)*a[fa[x]],b[fa[x]]+=p-a[x];
		ans+=(a[x]-p)*b[x];
		a[x]=p;
		cout<<fixed<<setprecision(6)<<ans<<endl;
	}


	
	return 0;
}

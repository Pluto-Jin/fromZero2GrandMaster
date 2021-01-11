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

const int N=5e5+1;
int n,m,k,a[N],fa[N],rk[N];
bool bad[N],val[N];
struct node {
	int x,y,z;
	bool operator<(const node &tmp) const {
		return a[x]==a[tmp.x]?a[y]<a[tmp.y]:a[x]<a[tmp.x];
	}
};
vector<node> edge;
stack<node> stk;

int gf(int x) {return fa[x]==x?x:gf(fa[x]);}
bool gv(int x) {return fa[x]==x?0:gv(fa[x])^val[x];}
bool unite(int x,int y) {
	int fx=gf(x),fy=gf(y),vx=gv(x),vy=gv(y);
	if (fx==fy) return vx^vy;
	if (rk[fx]<rk[fy]) swap(x,y),swap(fx,fy);
	stk.push({fx,fy,rk[fx]});
	fa[fy]=fx,val[fy]=vx^vy^1,chkmax(rk[fx],rk[fy]+1);
	return 1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	cin>>n>>m>>k;
	for (int i=1;i<=n;i++) cin>>a[i],fa[i]=i;
	for (int i=0;i<m;i++) {
		int x,y; cin>>x>>y;
		if (a[x]>a[y]) swap(x,y);
		if (a[x]==a[y] and !unite(x,y)) bad[a[x]]=1;
		if (a[x]!=a[y]) edge.pb({x,y,0});
	}
	while (stk.size()) stk.pop();
	ll ans=0;
	for (int i=1;i<=k;i++) if (!bad[i]) ans++;
	ans=ans*(ans-1)/2;
	sort(edge.begin(),edge.end());
	for (int p=0,q=0;p<edge.size();p=q) {
		auto [x,y,z]=edge[p]; x=a[x],y=a[y];
		if (bad[x] or bad[y]) {q++;continue;}
		while (q<edge.size() and x==a[edge[q].x] and y==a[edge[q].y]) q++;
		while (p<q) {
			auto [x,y,z]=edge[p];
			if (!unite(x,y)) break; p++;
		}
		if (p<q) ans--;
		while (stk.size()) {
			auto [x,y,z]=stk.top(); stk.pop();
			fa[y]=y,val[y]=0,rk[x]=z;
		}
	}
	cout<<ans<<endl;
	
	return 0;
}

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

map<string,int> dic;
int cnt,k,cc[30],ccnt,a[30],fa[30],ans,del[30][30];
struct bian{
	int x,y,w;
	bool operator<(const bian &tmp) const {return w<tmp.w;}
} ma[30];
vector<bian> e[30];
vii edge[30],mst[30];
int gf(int x) {return fa[x]==x?x:fa[x]=gf(fa[x]);}

void bfs(int rt) {
	ccnt++;
	queue<int> q; q.push(rt); cc[rt]=ccnt;
	while (q.size()) {
		int at=q.front(); q.pop();
		for (auto [to,w]:edge[at]) if (!cc[to]) q.push(to),cc[to]=ccnt;
	}
	if (edge[rt].empty()) ans+=a[rt];
} 

void kruskal() {
	for (int i=1;i<=cnt;i++) fa[i]=i;
	for (int i=1;i<=ccnt;i++) if (e[i].size()) {
		sort(e[i].begin(),e[i].end());
		int mi=1e9,p;
		for (auto [x,y,w]:e[i]) {
			if (chkmin(mi,a[x])) p=x;
			if (chkmin(mi,a[y])) p=y;
			int fx=gf(x),fy=gf(y);
			if (fx==fy) continue;
			fa[fx]=fy,mst[x].pb(mp(y,w)),mst[y].pb(mp(x,w));
			ans+=w;
		}
		mst[0].pb(mp(p,a[p]));
		ans+=a[p];
	}
}

void dfs(int at=0,int par=-1) {
	for (auto [to,w]:mst[at]) if (to!=par and !del[at][to]) {
		ma[to]=ma[at];
		if (w>ma[at].w) ma[to]={at,to,w};
		dfs(to,at);
	}
} 

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int n; cin>>n;
	dic["Park"]=0;
	memset(a,0x3f,sizeof a);
	for (int i=0;i<n;i++) {
		string sx,sy; 
		int x,y,w; cin>>sx>>sy>>w;
		if (!dic.count(sx)) dic[sx]=++cnt;
		if (!dic.count(sy)) dic[sy]=++cnt;
		x=dic[sx],y=dic[sy];
		if (y) edge[x].pb(mp(y,w));
		else a[x]=w;
		if (x) edge[y].pb(mp(x,w));
		else a[y]=w;
	}
	cin>>k;
	for (int i=1;i<=cnt;i++) if (!cc[i]) bfs(i);
	for (int i=1;i<=cnt;i++) {
		for (auto [j,w]:edge[i]) if (i<j) 
			e[cc[i]].pb({i,j,w});
	}
	kruskal();
	int t=k-ccnt;
	while (t) {
		dfs();
		vector<pair<bian,int>> tmp;
		for (int i=1;i<=cnt;i++) {
			bian ea={0,i,a[i]};
			if (ea<ma[i]) tmp.pb(mp(ma[i],i));
		}
		sort(tmp.begin(),tmp.end());
		if (tmp.empty()) break;
		t--;
		auto [ea,i]=tmp.back();
		auto [x,y,w]=ea;
		ans+=a[i]-w;	
		del[x][y]=del[y][x]=1;
		mst[0].pb(mp(i,a[i]));
	}
	cout<<"Total miles driven: "<<ans<<endl;
	
	return 0;
}

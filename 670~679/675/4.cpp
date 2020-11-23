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

#define pf push_front

const int N=1e5+5;
int n,m,bx,by,ex,ey;
ll d[N];
pii a[N];
pair<pii,int> tmp[N];
vii edge[N];
bool vis[N];

bool cmp(const pair<pii,int> &t1, const pair<pii,int> &t2) {return t1.fi.se<t2.fi.se;}

int dist(int x,int y,int x1,int y1) {return min(abs(x1-x),abs(y1-y));}
int dist(int x,int y,int id) {return dist(x,y,a[id].fi,a[id].se);}
int dist(int x,int y) {return dist(a[x].fi,a[x].se,y);}

int yuan(int x,int y,int x1,int y1) {return abs(x1-x)+abs(y1-y);}
int yuan(int x,int y,int id) {return yuan(x,y,a[id].fi,a[id].se);}

void dijkstra() {
	memset(d,0x3f,sizeof d);
	d[0]=0;
	priority_queue<pair<ll,int>> pq;
	for (int i=1;i<=m;i++) d[i]=dist(bx,by,i),pq.push(mp(-d[i],i));
	while (pq.size()) {
		auto [_,at]=pq.top(); pq.pop();
		if (vis[at]) continue;
		vis[at]=1;
		for (auto [to,w]:edge[at]) if (!vis[to] and chkmin(d[to],d[at]+w)) pq.push(mp(-d[to],to));
		chkmin(d[m+1],d[at]+yuan(ex,ey,at));
	}
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	cin>>n>>m;
	cin>>bx>>by>>ex>>ey;
	for (int i=1;i<=m;i++) {
		cin>>a[i].fi>>a[i].se;
		tmp[i]={mp(a[i].fi,a[i].se),i};
	}
	sort(tmp+1,tmp+m+1);
	for (int i=1;i<m;i++) {
		int a=tmp[i].se,b=tmp[i+1].se;
		edge[a].pb(mp(b,dist(a,b)));
		edge[b].pb(mp(a,dist(a,b)));
	}
	sort(tmp+1,tmp+m+1,cmp);
	for (int i=1;i<m;i++) {
		int a=tmp[i].se,b=tmp[i+1].se;
		edge[a].pb(mp(b,dist(a,b)));
		edge[b].pb(mp(a,dist(a,b)));
	}
	dijkstra();
	cout<<min(1ll*yuan(bx,by,ex,ey),d[m+1])<<endl;
	
	return 0;
}

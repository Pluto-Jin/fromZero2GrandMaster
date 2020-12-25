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
int n,s,d[N];
pii pre[N];
vii edge[N];
vi zhi,cha,dis;

void dfs(int at=1,int par=-1) {
	pre[at].fi=par; d[at]=0;
	queue<int> q; q.push(at);
	while (q.size()) {
		int at=q.front(); q.pop();
		for (auto [to,w]:edge[at]) if (to!=pre[at].fi) {
			d[to]=d[at]+w;
			pre[to]={at,w}; q.push(to);
		}
	}	
}

int dfs2(int at,int x,int y,int par=-1) {
	int res=0; pre[at].fi=par;
	queue<pii> q; q.push({at,0});
	while (q.size()) {
		auto [at,cur]=q.front(); q.pop(); chkmax(res,cur);
		for (auto [to,w]:edge[at]) if (to!=x and to!=y and to!=pre[at].fi) 
			pre[to].fi=at,q.push({to,cur+w});
	}
	return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	cin>>n>>s;
	for (int i=1;i<n;i++) {
		int x,y,w; cin>>x>>y>>w;
		edge[x].pb({y,w});
		edge[y].pb({x,w});
	}

	dfs();
	int ma=0,rt,rr;
	for (int i=1;i<=n;i++) if (chkmax(ma,d[i])) rt=i;

	memset(pre,0,sizeof pre);
	d[rt]=0; dfs(rt);
	ma=0;
	for (int i=1;i<=n;i++) if (chkmax(ma,d[i])) rr=i;

	cha.pb(0); zhi.pb(rr);
	while (rr!=-1) cha.pb(pre[rr].se),zhi.pb(rr=pre[rr].fi);
	for (int i=1;i<cha.size();i++) cha[i]+=cha[i-1];

	memset(pre,0,sizeof pre);
	for (int i=0;i<zhi.size();i++) dis.pb(dfs2(zhi[i],i?zhi[i-1]:-1,i+1<zhi.size()?zhi[i+1]:-1));

	deque<pii> q;
	int ans=2e9;
	for (int bg=0,i=0;i<zhi.size();i++) {
		while (q.size() and q.back().se<=dis[i]) q.ppb(); 
		q.pb({i,dis[i]});
		while (cha[i]-cha[q.front().fi]>s) q.ppf(); 
		while (cha[i]-cha[bg]>s) bg++;
		chkmin(ans,max(dis[q.front().fi],max(cha[bg],cha.back()-cha[i])));
	}
	cout<<ans<<endl;
	
	return 0;
}

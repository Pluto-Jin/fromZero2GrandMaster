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

const int N=1001,M=1e4+1;
int n,m,k,d[N],vis[N],a[M],tot;
vii edge[N];

bool check(int mid) {
	memset(d,0x3f,sizeof d);
	memset(vis,0,sizeof vis);
	deque<int> q; q.pb(1); d[1]=0;
	while (q.size()) {
		int at=q.front(); q.ppf();
		if (vis[at]) continue;
		else vis[at]=1;
		for (auto [to,w]:edge[at]) if (!vis[to]) {
			if (w>mid) {
				if (chkmin(d[to],d[at]+1)) q.pb(to);
			} else {
				if (chkmin(d[to],d[at])) q.pf(to);
			}
		}
	}
	if (d[n]==0x3f3f3f3f) {
		cout<<-1<<endl;
		exit(0);
	} 
	return d[n]<=k; 
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	cin>>n>>m>>k;
	for (int i=0;i<m;i++) {
		int x,y,w; cin>>x>>y>>w;
		edge[x].pb(mp(y,w));
		edge[y].pb(mp(x,w));
		a[i+1]=w;
	}
	sort(a,a+m+1);
	tot=unique(a,a+m+1)-a;
	int lo=-1,hi=tot;
	while (lo<hi-1) {
		int mid=lo+hi>>1;
		if (check(a[mid])) hi=mid;
		else lo=mid;
	}
	cout<<a[hi]<<endl;
	
	return 0;
}

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

const int N=25001;
int n,r,p,s,d[N],vis[N];
vii edge[N];

void spfa(int s) {
	memset(d,0x3f,sizeof d);
	deque<int> q;
	q.pb(s); vis[s]=1; d[s]=0;
	while (q.size()) {
		int at=q.front(); q.ppf();
		vis[at]=0;
		for (auto [to,w]:edge[at]) 
			if (chkmin(d[to],d[at]+w) and !vis[to]) {
				vis[to]=1;
				if (q.size() and d[to]<d[q.front()]) q.pf(to);
				else q.pb(to);
			}
	}
} 

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	cin>>n>>r>>p>>s;
	for (int i=0;i<r;i++) {
		int x,y,w; cin>>x>>y>>w;
		edge[x].pb(mp(y,w));
		edge[y].pb(mp(x,w));
	}
	for (int i=0;i<p;i++) {
		int x,y,w; cin>>x>>y>>w;
		edge[x].pb(mp(y,w));
	}
	spfa(s);
	for (int i=1;i<=n;i++) {
		if (d[i]==0x3f3f3f3f) cout<<"NO PATH"<<endl;
		else cout<<d[i]<<endl;
	} 
	
	return 0;
}

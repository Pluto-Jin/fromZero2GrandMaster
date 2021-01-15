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
#define eb emplace_back 
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

const int N=2e5+1;
ll d[N<<2];
bool vis[N<<2];
vii edge[N<<2];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int n,m; cin>>n>>m;
	for (int i=0;i<m;i++) {
		int x,y,w; cin>>x>>y>>w;
		for (int k=0;k<2;k++) {
			edge[x].eb(y,w);
			edge[x].eb(y+n,0);
			edge[x].eb(y+2*n,2*w);
			edge[x].eb(y+3*n,w);
			edge[x+n].eb(y+n,w);
			edge[x+n].eb(y+3*n,2*w);
			edge[x+2*n].eb(y+2*n,w);
			edge[x+2*n].eb(y+3*n,0);
			edge[x+3*n].eb(y+3*n,w);
			swap(x,y);
		}
	}
	memset(d,0x3f,sizeof d); d[1]=0;
	priority_queue<pair<ll,int>> pq; pq.emplace(0,1);
	while (pq.size()) {
		auto [w,at]=pq.top(); pq.pop();
		if (vis[at]) continue; vis[at]=1;
		for (auto [to,w]:edge[at]) if (chkmin(d[to],d[at]+w)) pq.emplace(-d[to],to);
	}
	for (int i=2;i<=n;i++) cout<<d[i+3*n]<<' ';
	cout<<endl;
	
	return 0;
}

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
int n,m,d[N],mi[N];
vii edge[N];
bool vis[N];

int sqr(int x) {return x*x;}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	cin>>n>>m;
	while (m--) {
		int x,y,w; cin>>x>>y>>w;
		edge[x].eb(y,w),edge[y].eb(x,w);
	}
	for (int i=2;i<=n;i++) d[i]=2e9;
	memset(mi,0x3f,sizeof mi);
	priority_queue<pii> pq;
	pq.emplace(0,1);
	while (pq.size()) {
		auto [tmp,at]=pq.top(); pq.pop(); tmp=-tmp;
		if (tmp!=d[at]) continue;
		vis[at]=1;
		for (auto [to,w]:edge[at]) if (chkmin(mi[to],w)) {
			for (auto [too,ww]:edge[to]) if (!vis[too] and chkmin(d[too],tmp+sqr(w+ww)))
				pq.emplace(-d[too],too);
		}
	}
	for (int i=1;i<=n;i++) cout<<(d[i]==2e9?-1:d[i])<<' ';
	cout<<endl;
	
	return 0;
}

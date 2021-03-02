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
int n,m;
ll d[N][51];
vii edge[N];
bool vis[N][51];

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
	memset(d,0x3f,sizeof d); d[1][0]=0;
	priority_queue<tuple<ll,int,int>> pq;
	pq.emplace(0,1,0);
	while (pq.size()) {
		auto [tmp,at,k]=pq.top(); pq.pop(); tmp=-tmp;
		if (tmp!=d[at][k]) continue;
		if (!k) { 
			for (auto [to,w]:edge[at]) if (!vis[to][w] and chkmin(d[to][w],tmp))
				pq.emplace(-tmp,to,w);
		} else {
			vis[at][k]=1;
			for (auto [to,w]:edge[at]) if (chkmin(d[to][0],tmp+sqr(w+k)))
				pq.emplace(-d[to][0],to,0);
		}
	}
	for (int i=1;i<=n;i++) cout<<(d[i][0]==0x3f3f3f3f3f3f3f3f?-1ll:d[i][0])<<' ';
	cout<<endl;
	
	return 0;
}

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

const int N=2e5+1,MOD=998244353;
int n,m,vis[N][22];
vi edge[N][2];
struct node{
	int at,x,y;
	bool operator<(const node &tmp) const {
		if (x==tmp.x) return y>tmp.y;
		if (x>=20 or tmp.x>=20) return x>tmp.x;
		return (1<<x)+y>(1<<tmp.x)+tmp.y;
	}
};

ll fpow(ll a,ll b) {
	ll res=1;
	while (b) {
		if (b&1) res=res*a%MOD;
		b>>=1,a=a*a%MOD;
	}
	return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	cin>>n>>m;
	for (int i=0;i<m;i++) {
		int x,y; cin>>x>>y;
		edge[x][0].pb(y);
		edge[y][1].pb(x);
	}
	priority_queue<node> pq; pq.push({1,0,0});
	while (1) {
		auto [at,x,y]=pq.top(); pq.pop();
		int k=x>=20?20+(x&1):x;
		if (vis[at][k]) continue; vis[at][k]=1;
		if (at==n) {
			cout<<(fpow(2,x)+y+MOD-1)%MOD<<endl;
			break;
		}
		for (auto to:edge[at][x&1]) pq.push({to,x,y+1});
		pq.push({at,x+1,y});	
	}
	
	return 0;
}

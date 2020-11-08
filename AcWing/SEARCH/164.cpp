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

const int N=3e4+1;
int n,m,d[N];
bool vis[N];
bitset<30001> a[N];
vi edge[N],tp;

bitset<30001> solve(int at) {
	if (vis[at]) return a[at]; vis[at]=1;
	for (auto to:edge[at]) a[at]|=solve(to);
	return a[at];
}

void topo() {
	queue<int> q;
	for (int i=1;i<=n;i++) if (!d[i]) q.push(i);
	while (q.size()) {
		int at=q.front(); q.pop(); solve(at);
		for (auto to:edge[at]) {
			d[to]--;
			if (!d[to]) q.push(to);
		}
	}
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	cin>>n>>m;
	for (int i=0;i<m;i++) {
		int x,y; cin>>x>>y;
		edge[x].pb(y);
		d[y]++;
	}
	for (int i=1;i<=n;i++) a[i][i]=1;
	topo();
	for (int i=1;i<=n;i++) cout<<a[i].count()<<endl;
	
	return 0;
}

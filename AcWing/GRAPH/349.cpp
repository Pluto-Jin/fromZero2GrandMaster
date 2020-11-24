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

const int N=1001,MOD=(1ll<<31)-1;
int n,m,g[N][N],d[N];
bool vis[N];

void dijkstra() {
	d[1]=0;
	for (int i=1;i<=n;i++) {
		int cur=-1,mi=1e9;
		for (int j=1;j<=n;j++) if (!vis[j] and chkmin(mi,d[j])) cur=j;
		vis[cur]=1;
		for (int j=1;j<=n;j++) chkmin(d[j],d[cur]+g[cur][j]);
	}
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	cin>>n>>m;
	memset(g,0x3f,sizeof g);
	memset(d,0x3f,sizeof d);
	for (int i=0;i<m;i++) {
		int x,y,w; cin>>x>>y>>w;
		g[x][y]=g[y][x]=w;
	}
	dijkstra();
	ll ans=1;
	for (int i=2;i<=n;i++) {
		int cnt=0;
		for (int j=1;j<=n;j++) if (d[j]+g[j][i]==d[i]) cnt++;
		ans*=cnt,ans%=MOD;
	}
	cout<<ans<<endl;
	
	return 0;
}

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

const int INF=0x3f3f3f3f;
int n,m,d[101][101],a[101][101],path[101][101],ans=INF,bg,ed;
vi cyc;

void dfs(int i,int j) {
	if (!path[i][j]) return;
	int k=path[i][j];
	dfs(i,k);
	cyc.pb(k);
	dfs(k,j);
}

void get(int i,int j,int k) {
	cyc.resize(0);
	cyc.pb(i);
	dfs(i,j);
	cyc.pb(j);
	cyc.pb(k);
}

void floyd() {
	for (int k=1;k<=n;k++) {
		for (int i=1;i<k;i++) for (int j=i+1;j<k;j++) {
			if (d[i][j]!=INF and a[i][k] and a[j][k]) 
				if (chkmin(ans,0ll+d[i][j]+a[i][k]+a[j][k])) bg=i,ed=j,get(i,j,k);
	    }
		for (int i=1;i<=n;i++) for (int j=1;j<=n;j++) 
			if (chkmin(d[i][j],d[i][k]+d[k][j])) path[i][j]=k;
	}
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	cin>>n>>m;
	memset(a,0x3f,sizeof a);
	for (int i=0;i<m;i++) {
		int x,y,w; cin>>x>>y>>w;
		a[x][y]=a[y][x]=min(a[x][y],w);
	}
	for (int i=1;i<=n;i++) a[i][i]=0;
	memcpy(d,a,sizeof d);

	floyd();
	if (cyc.size()) for (auto i:cyc) cout<<i<<' ';	
	else cout<<"No solution.";
	cout<<endl;
	
	return 0;
}

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

const int N=1001;
int n,t,s,e,cnt,g[N][N],d[N][N],tmp[N][N];
map<int,int> id;

void floyd(int res[][N],int a[][N],int b[][N]) {
	memset(tmp,0x3f,sizeof tmp);
	for (int k=1;k<=cnt;k++)
		for (int i=1;i<=cnt;i++) 
			for (int j=1;j<=cnt;j++) 
				chkmin(tmp[i][j],a[i][k]+b[k][j]);
	memcpy(res,tmp,sizeof tmp); //!!!cannot use 'sizeof res',pointer!=arrayname when compile
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	cin>>n>>t>>s>>e;
	memset(g,0x3f,sizeof g);
	memset(d,0x3f,sizeof d);
	for (int i=0;i<t;i++) {
		int w,x,y; cin>>w>>x>>y;
		if (!id[x]) id[x]=++cnt;
		if (!id[y]) id[y]=++cnt;
		x=id[x],y=id[y];
		g[x][y]=g[y][x]=w;
	}
	for (int i=1;i<=cnt;i++) d[i][i]=0;
	while (n) {
		if (n&1) floyd(d,d,g);
		floyd(g,g,g);
		n>>=1;
	}
	cout<<d[id[s]][id[e]]<<endl;
	
	return 0;
}

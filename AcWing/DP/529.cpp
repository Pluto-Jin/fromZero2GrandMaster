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

int n,m,g[13][13],dp[1<<12][13];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	memset(g,0x3f,sizeof g);
	memset(dp,0x3f,sizeof dp);

	cin>>n>>m;
	for (int i=0;i<m;i++) {
		int x,y,w; cin>>x>>y>>w;
		chkmin(g[x][y],w);
		chkmin(g[y][x],w);
	}
	for (int i=0;i<n;i++) dp[1<<i][1]=0;
	for (int i=3;i<1<<n;i++) {
		for (int j=i-1&i;j;j=j-1&i) {
			int sum=0,ok=1;
			for (int x=1;ok and x<=n;x++) if (i>>x-1&1 and !(j>>x-1&1)) {
				int tmp=0x3f3f3f3f;
				for (int y=1;ok and y<=n;y++) if (j>>y-1&1) 
					chkmin(tmp,g[x][y]);
				if (tmp==0x3f3f3f3f) ok=0;
				else sum+=tmp;
			}
			if (ok) for (int k=1;k<__builtin_popcount(i);k++) 
				chkmin(dp[i][k+1],dp[j][k]+k*sum);
		}
	}
	int ans=1e9;
	for (int i=1;i<=n;i++) chkmin(ans,dp[(1<<n)-1][i]);
	cout<<ans<<endl;
	
	return 0;
}

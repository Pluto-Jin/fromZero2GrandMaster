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

const int N=41;
int n,m,a[351],cnt[5],dp[N][N][N][N];

int dfs(int i,int j,int x,int y) {
	int &u=dp[i][j][x][y]; if (~u) return u;
	int cur=1+i+2*j+3*x+4*y; 
	if (i) chkmax(u,dfs(i-1,j,x,y)+(cur>n?0:a[cur]));
	if (j) chkmax(u,dfs(i,j-1,x,y)+(cur>n?0:a[cur]));
	if (x) chkmax(u,dfs(i,j,x-1,y)+(cur>n?0:a[cur]));
	if (y) chkmax(u,dfs(i,j,x,y-1)+(cur>n?0:a[cur]));
	return u;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=1;i<=m;i++) {
		int x; cin>>x;
		cnt[x]++;
	}
	memset(dp,-1,sizeof dp);
	dp[0][0][0][0]=a[1];
	cout<<dfs(cnt[1],cnt[2],cnt[3],cnt[4])<<endl;
	
	return 0;
}

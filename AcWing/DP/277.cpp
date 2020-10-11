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

pll g[31];
ll dp[31][5001],pre[31];
pii from[31][5001];
int ans[31];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int n,m; cin>>n>>m;
	for (int i=1;i<=n;i++) {
		cin>>g[i].fi;
		g[i].se=i;
	}
	sort(g+1,g+1+n,greater<>());
	for (int i=1;i<=n;i++) pre[i]+=pre[i-1]+g[i].fi;

	memset(dp,0x3f,sizeof(dp));
	dp[0][0]=0;
	for (int i=1;i<=n;i++) for (int j=i;j<=m;j++) for (int k=0;k<=i;k++) 
		if (chkmin(dp[i][j],dp[i-k][j-i]+(pre[i]-pre[i-k])*(i-k)))
			from[i][j]=mp(i-k,j-i);

	cout<<dp[n][m]<<endl;
	int i=n,j=m,tmp=0;
	while (i) {
		auto [x,y]=from[i][j];
		for (;i>x;i--) ans[g[i].se]=tmp+1;
		tmp++,i=x,j=y;
	}
	for (int i=1;i<=n;i++) cout<<ans[i]<<' ';
	cout<<endl;
	
	return 0;
}

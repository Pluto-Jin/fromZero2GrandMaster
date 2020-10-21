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

const int N=4000;
ll dp[N][N][2],a[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int n,k; cin>>n>>k;
	for (int i=1;i<=n;i++) cin>>a[i],a[i]+=a[i-1];

	for (int i=2;i<=n;i++) for (int j=1;j<=min(i,k);j++) {
		dp[i][j][0]=max(dp[i-1][j][1],dp[i-1][j][0]);
		dp[i][j][1]=max(j-1?dp[i-1][j-1][1]+a[i]-a[i-1]:0,dp[i-1][j-1][0]);
		cout<<i<<' '<<j<<' '<<dp[i][j][0]<<' '<<dp[i][j][1]<<endl;
	}

	ll ans=dp[n][n][0];
	for (int i=1;i<=n;i++) ans=max(ans,dp[n][i][1]+a[n-i]); 
	cout<<ans<<endl;
	
	return 0;
}

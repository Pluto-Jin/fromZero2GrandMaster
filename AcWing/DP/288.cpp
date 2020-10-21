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
int dp[N][2],a[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int n,k; cin>>n>>k;
	for (int i=1;i<=n;i++) cin>>a[i],a[i]+=a[i-1];

	for (int i=2;i<=n;i++) for (int j=min(i,k);j;j--) {
		dp[j][0]=max(dp[j][1],dp[j][0]);
		dp[j][1]=max(j-1?dp[j-1][1]+a[i]-a[i-1]:0,dp[j-1][0]);
	}

	int ans=dp[k][0];
	memset(dp,0,sizeof dp);

	for (int i=1;i<n;i++) for (int j=min(i,k-1);j;j--) {
		dp[j][0]=max(dp[j][1],dp[j][0]);
		if (i==1) dp[j][1]=a[1];
		else dp[j][1]=max(j-1?dp[j-1][1]+a[i]-a[i-1]:0,dp[j-1][0]);
	}
	chkmax(ans,max(dp[k-1][1]+a[n]-a[n-1],dp[k-1][0]));
	cout<<ans<<endl;
	
	return 0;
}

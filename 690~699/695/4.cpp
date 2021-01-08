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

const int N=5005,MOD=1e9+7;
ll f[N][N],dp[N],a[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int n,k,q; cin>>n>>k>>q; k++;
	for (int i=1;i<=n;i++) f[1][i]=1;
	for (int i=2;i<=k;i++) for (int j=1;j<=n;j++)
		f[i][j]=f[i-1][j-1]+f[i-1][j+1],f[i][j]%=MOD;
	for (int i=1;i<=n;i++) for (int j=1;j<=k;j++) 
		dp[i]+=f[j][i]*f[k+1-j][i]%MOD,dp[i]%=MOD;	
	ll ans=0;
	for (int i=1;i<=n;i++) cin>>a[i],ans+=a[i]*dp[i]%MOD,ans%=MOD;
	while (q--) {
		int x,y; cin>>x>>y;
		ans-=a[x]*dp[x]%MOD;
		a[x]=y;
		ans+=a[x]*dp[x]%MOD;
		ans+=MOD,ans%=MOD;
		cout<<ans<<endl;
	}

	
	
	return 0;
}

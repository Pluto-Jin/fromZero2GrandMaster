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

const int N=2e5+1,MOD=1e9+7;
int h,w,n,dp[2002];
pii a[2002];
int fac[N],inv[N],ifac[N];

void build(int n) {
	inv[1]=fac[0]=ifac[0]=1;
	for (int i=2;i<=n;i++) inv[i]=1ll*(MOD-MOD/i)*inv[MOD%i]%MOD;
	for (int i=1;i<=n;i++) fac[i]=1ll*fac[i-1]*i%MOD;
	for (int i=1;i<=n;i++) ifac[i]=1ll*ifac[i-1]*inv[i]%MOD;
}
int comb(int a,int b) {return a<b?0:1ll*fac[a]*ifac[b]%MOD*ifac[a-b]%MOD;}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	build(2e5);
	cin>>h>>w>>n;
	for (int i=1;i<=n;i++) cin>>a[i].fi>>a[i].se;
	a[++n]={h,w};
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++) {
		auto [x,y]=a[i];
		for (int j=1;j<i;j++) {
			auto [xx,yy]=a[j];
			if (x>=xx and y>=yy) dp[i]+=1ll*dp[j]*comb(x-xx+y-yy,x-xx)%MOD,dp[i]%=MOD;
		}
		dp[i]=(comb(x-1+y-1,x-1)-dp[i])%MOD+MOD,dp[i]%=MOD;
	}
	cout<<dp[n]<<endl;
	
	return 0;
}

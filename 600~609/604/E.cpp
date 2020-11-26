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

const int N=2e5+1,MOD=998244353;
int a[N];
ll inv[N],fac[N],ifac[N];

void build(int n) {
	inv[1]=fac[0]=ifac[0]=1;
	for (int i=2;i<=n;i++) inv[i]=(MOD-MOD/i)*inv[MOD%i]%MOD;
	for (int i=1;i<=n;i++) fac[i]=fac[i-1]*i%MOD;
	for (int i=1;i<=n;i++) ifac[i]=ifac[i-1]*inv[i]%MOD;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
	
	int n; cin>>n;
	for (int i=0;i<n;i++) cin>>a[n-i-1];
	ll ans=0,cur=1;
	build(100);
	for (int i=0;i<n;i++) {
		cur=cur*100%MOD*inv[a[i]]%MOD;
		ans=(ans+cur)%MOD;	
	}
	cout<<ans<<endl;
	
	return 0;
}

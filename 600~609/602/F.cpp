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
int a[N],mi[N];
ll fac[N],inv[N],ifac[N];

ll fpow(ll a,ll b) {
	ll res=1;
	while (b) {
		if (b&1) res=res*a%MOD;
		b>>=1,a=a*a%MOD;
	}
	return res;
} 

void build(int n) {
	inv[1]=fac[0]=ifac[0]=1;
	for (int i=2;i<=n;i++) inv[i]=(MOD-MOD/i)*inv[MOD%i]%MOD;
	for (int i=1;i<=n;i++) fac[i]=fac[i-1]*i%MOD;
	for (int i=1;i<=n;i++) ifac[i]=ifac[i-1]*inv[i]%MOD;
}

ll comb(ll a,ll b) {return a<b?0:fac[a]*ifac[b]%MOD*ifac[a-b]%MOD;}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int n,k; cin>>n>>k;
	for (int i=0;i<n;i++) cin>>a[i]; a[n]=a[0];
	if (k==1) {
		cout<<0<<endl;
		return 0;
	}
	build(n);
	int cnt=0;
	for (int i=0;i<n;i++) if (a[i]==a[i+1]) cnt++;
	n=n-cnt;
	ll ans=fpow(k,cnt);
	mi[0]=1;
	for (int i=1;i<=n;i++) mi[i]=1ll*mi[i-1]*(k-2)%MOD;
	ll tmp=0;
	for (int i=0;i<=n/2;i++) tmp+=comb(n,2*i)*comb(2*i,i)%MOD*mi[n-2*i]%MOD,tmp%=MOD;
	cout<<((fpow(k,n)+MOD-tmp)%MOD*fpow(2,MOD-2)%MOD*ans%MOD)<<endl;
	
	return 0;
}

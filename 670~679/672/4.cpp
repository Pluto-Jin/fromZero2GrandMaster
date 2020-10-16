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

const int N=3e5+1,MOD=998244353;
ll fac[N],inv[N],ifac[N];
int n,l[N],r[N],dif[N<<1],lsh[N<<1],cnt[N<<1];
bool vis[N<<1];

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

	int k; cin>>n>>k;
	build(n);
	for (int i=0;i<n;i++) cin>>l[i]>>r[i],lsh[i]=l[i],lsh[i+n]=r[i];
	sort(lsh,lsh+2*n);
	int tot=unique(lsh,lsh+2*n)-lsh;
	for (int i=0;i<n;i++) {
		l[i]=lower_bound(lsh,lsh+tot,l[i])-lsh+1;
		r[i]=lower_bound(lsh,lsh+tot,r[i])-lsh+1;
		cnt[l[i]]++;
	}
	for (int i=0;i<n;i++) dif[l[i]]++,dif[r[i]+1]--;
	for (int i=1;i<=2*n;i++) dif[i]+=dif[i-1];
	ll ans=0;
	for (int i=0;i<n;i++) if (!vis[l[i]]) {
		vis[l[i]]=1;
		int cur=dif[l[i]];
		ans+=(comb(cur,k)-comb(cur-cnt[l[i]],k)+MOD)%MOD;
		ans%=MOD;
	}
	cout<<ans<<endl;
	
	return 0;
}

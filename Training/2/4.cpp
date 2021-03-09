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

struct ren {
	ll x; int k,m;
	bool operator<(const ren &tmp) const {return k<tmp.k;}
} a[101];
ll dp[1<<20];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	ll n,m,b; cin>>n>>m>>b;
	for (int i=1;i<=n;i++) {
		int q,tmp=0; cin>>a[i].x>>a[i].k>>q;
		while (q--) {
			int x; cin>>x;
			tmp|=(1<<x-1);
		} 
		a[i].m=tmp;
	}
	sort(a+1,a+n+1);

	ll ans=8e18;
	for (int i=1;i<1<<m;i++) dp[i]=8e18;
	dp[0]=0;
	for (int i=1;i<=n;i++) {
		for (int j=0;j<1<<m;j++) {
			chkmin(dp[j|a[i].m],dp[j]+a[i].x);
			if ((j|a[i].m)==((1<<m)-1)) chkmin(ans,dp[(1<<m)-1]+b*a[i].k);
		}
	}
	cout<<(ans==8e18?-1:ans)<<endl;
	
	return 0;
}

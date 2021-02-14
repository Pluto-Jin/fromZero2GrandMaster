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

const int N=2e5+5;
int d[N],f[N];
pii a[N];
ll pre[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int t; cin>>t;
	while (t--) {
		int n,p,q; cin>>n;
		for (int i=1;i<=n;i++) cin>>a[i].fi,a[i].se=i,f[i]=pre[i]=d[i]=0;
		cin>>p>>q;
		sort(a+1,a+n+1);
		for (int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i].fi;
		int lo=1,hi=n+1;
		while (lo<hi-1) {
			int mid=lo+hi>>1,ok=0;
			for (int i=1;i+mid-1<=n;i++) 
				if ((pre[i+mid-1]-pre[i-1])*p>=1ll*q*mid*a[i+mid-1].fi) ok=1,f[i]=mid;
			if (ok) lo=mid;
			else hi=mid;
		}
		int ma=lo;
		for (int i=1;i+ma-1<=n;i++) if (ma==1 or f[i]==ma) {
			lo=0,hi=i;
			while (lo<hi-1) {
				int mid=lo+hi>>1;
				if ((pre[i+ma-1]-pre[i]+a[mid].fi)*p>=1ll*q*ma*a[i+ma-1].fi) hi=mid;
				else lo=mid;
			}
			d[hi]++,d[i+ma]--;
		}
		vi ans;
		for (int i=1;i<=n;i++) if (!(d[i]+=d[i-1])) ans.pb(a[i].se);
		sort(ans.begin(),ans.end());
		cout<<ans.size()<<endl;
		for (auto i:ans) cout<<i<<' ';
		cout<<endl;
	}
	
	return 0;
}

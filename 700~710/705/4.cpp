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
vi pr;
int mip[N],a[N];
map<int,multiset<int>> xd;
map<int,int> cnt;

void sieve(int n) {
	for (int i=2;i<=n;i++) {
		if (!mip[i]) pr.pb(i),mip[i]=i;
		for (auto j:pr) {
			if (i*j>n) break;
			mip[i*j]=j;
			if (i%j==0) break;
		}
	}
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	sieve(2e5);
	int tmp=1; 

	int n,q; cin>>n>>q;
	ll g=0;
	for (int i=1;i<=n;i++) cin>>a[i],g=gcd(g,a[i]);
	for (int i=1;i<=n;i++) {
		a[i]/=g;
		while (a[i]>1) {
			int u=mip[a[i]]; cnt[u]++;
			while (a[i]%u==0) xd[u].insert(i),a[i]/=u;
		}
	}

	while (q--) {
		int x,y; cin>>x>>y;
		while(y>1) {
			int u=mip[y];
			if (cnt[u]==n-1 and !xd[u].count(x)) {
				for (int i=1;i<=n;i++) {
					if (i==x) continue;
					xd[u].erase(xd[u].find(i));
					if (!xd[u].count(i)) cnt[u]--;
				}
				g=g*u%MOD;
			} else {
				if (!xd[u].count(x)) cnt[u]++;
				xd[u].insert(x);
			}
			y/=u;
		}
		cout<<g<<endl;
	}
	
	return 0;
}

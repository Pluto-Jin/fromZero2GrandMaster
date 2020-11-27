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

const int N=1e4+1;
pii a[N];
int fa[N];
int gf(int x) {return fa[x]==x?x:fa[x]=gf(fa[x]);}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int n;
	while (cin>>n) {
		for (int i=1;i<=N;i++) fa[i]=i;
		for (int i=1;i<=n;i++) cin>>a[i].fi>>a[i].se;
		sort(a+1,a+n+1,greater<>());
		ll ans=0;
		for (int i=1;i<=n;i++) {
			int f=gf(a[i].se);
			if (!f) continue;
			ans+=a[i].fi;
			fa[f]=gf(f-1);
		}
		cout<<ans<<endl;
	}
	
	return 0;
}

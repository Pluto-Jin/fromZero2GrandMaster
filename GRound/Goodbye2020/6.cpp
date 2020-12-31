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

const int N=5e5+1,MOD=1e9+7;
int n,m,fa[N];
int gf(int x) {return fa[x]==x?x:fa[x]=gf(fa[x]);}

ll fpow(ll a,ll b) {
	ll res=1;
	while (b) {
		if (b&1) res=res*a%MOD;
		b/=2;
		a=a*a%MOD;
	}
	return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	cin>>n>>m;
	vi ans;
	for (int i=1;i<=m;i++) fa[i]=i;
	for (int i=1;i<=n;i++) {
		int x,y,z; cin>>x;
		if (x==1) cin>>y,z=0;
		else cin>>y>>z;
		int a=gf(y),b=gf(z);
		if (a!=b) ans.pb(i),fa[a]=b; 
	}
	cout<<fpow(2,ans.size())<<' '<<ans.size()<<endl;
	for (auto i:ans) cout<<i<<' '; cout<<endl;
	
	return 0;
}

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

const int N=1e6+1;
int a[N<<1],fa[N<<1],tot;
pii ar[N],br[N];

int gf(int x) {return fa[x]==x?x:fa[x]=gf(fa[x]);}
int id(int x) {return lower_bound(a,a+tot,x)-a;}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int t; cin>>t;
	while (t--) {
		int n; cin>>n;
		int cnt=0;
		for (int i=0;i<n;i++) {
			int x,y,e; cin>>x>>y>>e;
			if (e) ar[cnt].fi=x,ar[cnt].se=y,cnt++;
			else br[i-cnt].fi=x,br[i-cnt].se=y;
			a[i]=x,a[i+n]=y;
		}	
		sort(a,a+2*n);
		tot=unique(a,a+2*n)-a;
		for (int i=0;i<tot;i++) fa[i]=i;

		for (int i=0;i<cnt;i++) {
			auto [x,y]=ar[i];
			x=id(x),y=id(y);
			if (gf(x)!=gf(y)) fa[gf(x)]=gf(y);
		}
		int ok=1;
		for (int i=0;ok and i<n-cnt;i++) {
			auto [x,y]=br[i];
			x=id(x),y=id(y);
			if (gf(x)==gf(y)) ok=0;
		}
		cout<<(ok?"YES":"NO")<<endl;
	}
	
	return 0;
}

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

vi val,fa;
vii edge[5001],ans;

int gf(int x) {return fa[x]==x?x:fa[x]=gf(fa[x]);}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int n; cin>>n;
	val.resize(n+1),fa.resize(n+1);
	for (int i=1;i<=n;i++) fa[i]=i;
	for (int i=1;i<=n;i++) for (int j=1;j<=n;j++) {
		int x; cin>>x;
		if (i==j) val[i]=x;
		else if (i<j) edge[x].eb(i,j);
	}
	for (int i=1;i<=5000;i++) {
		for (auto [x,y]:edge[i]) {
			int fx=gf(x),fy=gf(y);
			if (fx==fy) continue;
			if (val[fx]==i) fa[fy]=fx,ans.eb(fy,fx);
			else if (val[fy]==i) fa[fx]=fy,ans.eb(fx,fy);
			else {
				val.pb(i),fa.pb(++n);
				fa[fx]=fa[fy]=n;
				ans.eb(fx,n),ans.eb(fy,n);
			}
		}
	}
	cout<<n<<endl;
	for (int i=1;i<=n;i++) cout<<val[i]<<' ';
	cout<<endl<<n<<endl;
	for (auto [i,j]:ans) cout<<i<<' '<<j<<endl;
	
	return 0;
}

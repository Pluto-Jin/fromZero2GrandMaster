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

const int N=2e5+1;
pii a[N];
map<int,vi> b;
int n,m,fen[N];
bool vis[N];

void update(int x,int v) {for(;x<=n;x+=x&-x)fen[x]+=v;}
int query(int x) {int res=0;for(;x;x-=x&-x)res+=fen[x];return res;}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int w; cin>>n>>m>>w;
	int nn=n+1,mm=m+1;
	for (int i=1;i<=w;i++) {
		cin>>a[i].fi>>a[i].se;
		if (a[i].fi==1) chkmin(mm,a[i].se);
		if (a[i].se==1) chkmin(nn,a[i].fi);
	}
	for (int i=1;i<=w;i++) b[a[i].se].pb(a[i].fi);
	for (auto &[i,j]:b) sort(j.begin(),j.end());
	ll ans=0;
	for (int i=1;i<=m;i++) {
		if (i<mm) {
			if (!b.count(i)) ans+=n;
			else if (b[i][0]>=nn) ans+=b[i][0]-1;
			else {
				for (auto j:b[i]) if (!vis[j]) vis[j]=1,update(j,1);
				ans+=b[i][0]-1+nn-b[i][0]-1-(query(nn-1)-query(b[i][0]));
			}
		} else {
			for (auto j:b[i]) if (!vis[j]) vis[j]=1,update(j,1);
			ans+=nn-2-(query(nn-1)-query(1));
		}
	}
	cout<<ans<<endl;
	
	return 0;
}

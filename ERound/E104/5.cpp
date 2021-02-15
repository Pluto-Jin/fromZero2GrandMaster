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
int n[4];
pll a[4][N];
vi edge[4][N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	for (int i=0;i<4;i++) cin>>n[i];
	for (int i=0;i<4;i++) for (int j=1;j<=n[i];j++) cin>>a[i][j].fi,a[i][j].se=j;
	for (int i=0;i<3;i++) {
		int m; cin>>m;
		while (m--) {
			int x,y; cin>>x>>y;
			edge[i][x].pb(y);
		}
	}
	sort(a[0]+1,a[0]+n[0]+1);
	ll ans=1e18;
	for (int i=1;i<=3;i++) {
		set<int> s,tmp;
		for (int j=1;j<=n[i];j++) s.insert(j);
		for (int j=1;j<=n[i-1];j++) {
			for (auto to:edge[i-1][a[i-1][j].se]) if (s.count(to)) 
				s.erase(to),tmp.insert(to);
			for (auto to:s) {
				a[i][to].fi+=a[i-1][j].fi;
				if (i==3) chkmin(ans,a[i][to].fi);
			}
			s.clear();
			swap(tmp,s);
		}
		for (auto j:s) a[i][j].fi=1e10;
		sort(a[i]+1,a[i]+n[i]+1);
	}
	if (ans>=1e10) cout<<-1<<endl;
	else cout<<ans<<endl;
	
	return 0;
}

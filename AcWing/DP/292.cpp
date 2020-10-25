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

int a[102],dp[102][62][62];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int n,m; cin>>n>>m;
	for (int i=2;i<n+2;i++) {
		string s; cin>>s;
		bitset<10> tmp(s,0,m,'P','H');
		a[i]=tmp.to_ulong();
	}
	a[0]=a[1]=-1;
	vi g;
	for (int i=0;i<1<<m;i++) {
		int mi=2;
		for (int j=0,cur=2;mi>=2 and j<m;j++) {
			if (i>>j&1) mi=min(cur,mi),cur=0;
			else cur++;
		}
		if (mi>=2) g.pb(i);
	}
	int cnt=g.size();

	for (int i=2;i<n+2;i++) 
		for (int l1=0;l1<cnt;l1++) if (!(g[l1]&a[i-2]))
			for (int l2=0;l2<cnt;l2++) if (!(g[l2]&a[i-1]) and !(g[l1]&g[l2]))
				for (int j=0;j<cnt;j++) if (!(g[j]&a[i]) and !(g[j]&g[l1]) and !(g[j]&g[l2])) 
					chkmax(dp[i][l2][j],dp[i-1][l1][l2]+__builtin_popcount(g[j]));

	int ans=0;
	for (int i=0;i<cnt;i++) for (int j=0;j<cnt;j++) chkmax(ans,dp[n+1][i][j]);
	cout<<ans<<endl;

	return 0;
}

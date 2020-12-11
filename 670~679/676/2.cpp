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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int t; cin>>t;
	while (t--) {
		int n,a,b,c,d,e; cin>>n;
		for (int i=1;i<=n;i++) {
			string s; cin>>s;
			if (i==n-2) c=s[n-1];
			if (i==n-1) d=s[n-2],a=s[n-1];
			if (i==n) e=s[n-3],b=s[n-2];
		}
		vii ans;
		if (c==d and c==e) {
			if (a==c) ans.pb(mp(n-1,n));
			if (b==c) ans.pb(mp(n,n-1));
		} else if (a==b) {
			if (c==a) ans.pb(mp(n-2,n));
			if (d==a) ans.pb(mp(n-1,n-1));
			if (e==a) ans.pb(mp(n,n-2));
		} else {
			if (c==d) ans.pb(mp(n,n-2)),e=c;
			else if (c==e) ans.pb(mp(n-1,n-1)),d=c;
			else if (e==d) ans.pb(mp(n-2,n)),c=e;
			if (a==c) ans.pb(mp(n-1,n));
			if (b==c) ans.pb(mp(n,n-1));
		}
		cout<<ans.size()<<endl;
		for (auto [i,j]:ans) cout<<i<<' '<<j<<endl; 
	}

	
	return 0;
}

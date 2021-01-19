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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int t; cin>>t;
	while (t--) {
		ll n,m; cin>>n>>m;
		vector<pair<ll,int>> a(n);	
		for (int i=0;i<n;i++) cin>>a[i].fi,a[i].se=i+1;
		sort(a.begin(),a.end(),greater<>());
		ll cur=0;
		vi ans;
		for (auto [w,id]:a) if (w+cur<=m) ans.pb(id),cur+=w;
		if (cur<(m+1)/2) cout<<-1<<endl;
		else {
			cout<<ans.size()<<endl;
			for (auto i:ans) cout<<i<<' ';
			cout<<endl;
		}
	}
	
	return 0;
}

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
		ll n; cin>>n;
		vi a(n+1); 
		for (int i=1;i<=n;i++) a[i]=i;
		ll res=(n-1)*(n-1);
		vii ans; ans.eb(1,n); 
		swap(a[1],a[n]);
		for (int i=2;i<=n/2;i++) {
			ans.eb(i,n); swap(a[i],a[n]);
			ans.eb(1+n-i,1); swap(a[1+n-i],a[1]);
			res+=2*(n-i)*(n-i);
		}
		if (n%2) ans.eb(n/2+1,n),swap(a[n/2+1],a[n]),res+=(n/2)*(n/2);
		reverse(ans.begin(),ans.end());
		cout<<res<<endl;
		for (int i=1;i<=n;i++) cout<<a[i]<<' ';
		cout<<endl<<ans.size()<<endl;
		for (auto [i,j]:ans) cout<<i<<' '<<j<<endl;
	}
	
	return 0;
}

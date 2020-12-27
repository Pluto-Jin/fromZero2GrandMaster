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

const int N=1e5+1;
pii a[N<<1];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int n; cin>>n;
	for (int i=1;i<=2*n;i++) {
		char c; cin>>c;
		a[i].fi=c=='+';
		if (!a[i].fi) cin>>a[i].se;
	}
	stack<int> s;
	vi ans;
	int ok=1;
	for (int i=2*n;ok and i;i--) {
		if (a[i].fi) {
			if (s.empty()) ok=0;
			else ans.pb(s.top()),s.pop();
		} else {
			if (s.size() and a[i].se>s.top()) ok=0;
			else s.push(a[i].se);
		}
	}
	cout<<(ok?"YES":"NO")<<endl;
	if (ok) {
		for (int i=n-1;~i;i--) cout<<ans[i]<<' ';
		cout<<endl;
	}
	
	return 0;
}

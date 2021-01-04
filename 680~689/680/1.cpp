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
		ll p,q; cin>>p>>q;
		if (p%q) cout<<p<<endl;
		else {
			vii a;
			for (int i=2;i*i<=q;i++) {
				int cnt=0;
				while (q%i==0) q/=i,cnt++;
				if (cnt) a.pb({i,cnt});
			}
			if (q>1) a.pb({q,1});
			ll ans=0;
			for (auto [x,y]:a) {
				ll tmp=p;
				while (tmp%x==0) tmp/=x;
				for (int i=1;i<y;i++) tmp*=x;
				chkmax(ans,tmp);
			}
			cout<<ans<<endl;
		}
	}
	
	return 0;
}

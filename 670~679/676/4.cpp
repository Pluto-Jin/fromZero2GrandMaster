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
		ll x,y,a[6]; cin>>x>>y;
		for (int i=0;i<6;i++) cin>>a[i];
		int ok=1;
		while (ok) {
			ok=0;
			for (int i=0;i<6;i++) if (chkmin(a[i],a[(i+5)%6]+a[(i+1)%6])) ok=1;
		} 
		ll ans;
		if (x<0) {
			if (y>=0) ans=a[2]*(-x)+y*a[1];
			else if (x>=y) ans=a[3]*(-x)+(x-y)*a[4];
			else ans=a[2]*(y-x)+(-y)*a[3];
		} else if (x>0) {
			if (y<=0) ans=a[5]*(x)+(-y)*a[4];
			else if (x<=y) ans=a[0]*(x)+(y-x)*a[1];
			else ans=a[5]*(x-y)+(y)*a[0];
		} else {
			if (y>=0) ans=a[1]*y;
			else ans=a[4]*(-y);
		}
		cout<<ans<<endl;
	}
	
	return 0;
}

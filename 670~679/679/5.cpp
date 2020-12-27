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

ll a,b,c,d;

ll cal(ll x) {return a*(x+1)-(1+x)*x/2*d*b;}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int t; cin>>t;
	while (t--) {
		cin>>a>>b>>c>>d;
		if (d>c) {
			if (a>b*c) cout<<-1<<endl;
			else cout<<a<<endl;
		} else {
			if (a<=b*d) cout<<a<<endl;
			else if (a>b*c) cout<<-1<<endl;
			else {
				ll lo=0,hi=c/d;
				while (lo<hi-1) {
					ll m1=lo+hi>>1,m2=m1+hi>>1;
					if (cal(m1)>cal(m2)) hi=m2;
					else lo=m1;
				}
				cout<<max(cal(lo),cal(hi))<<endl;
			}
		}
	}
	
	return 0;
}

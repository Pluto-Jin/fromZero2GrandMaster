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
		int n,u,r,d,l; cin>>n>>u>>r>>d>>l;
		int ok=0;
		for (int i=0;!ok and i<1<<4;i++) {
			int s=u,x=d,z=l,y=r;
			if (i>>0&1) s--,z--;
			if (i>>1&1) s--,y--;
			if (i>>2&1) x--,z--;
			if (i>>3&1) x--,y--;
			int okk=1;
			for (auto j:{s,x,z,y}) if (j<0 or j>n-2) okk=0;
			ok=okk;
		}
		cout<<(ok?"YES":"NO")<<endl;
	}
	
	return 0;
}

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
pii a[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int n,x,y; cin>>n>>x>>y;
	for (int i=1;i<=n;i++) cin>>a[i].fi>>a[i].se;
	pii tmp[]={{x,y-1},{x-1,y},{x+1,y},{x,y+1}};
	int ma=-1;
	pii ans;
	for (auto [i,j]:tmp) {
		int cnt=0;
		for (int t=1;t<=n;t++) {
			auto [xx,yy]=a[t];
			if (1ll*(xx-i)*(i-x)>=0) 
				if (1ll*(yy-j)*(j-y)>=0) cnt++;
		}	
		if (chkmax(ma,cnt)) ans={i,j};
	}
	cout<<ma<<endl;
	cout<<ans.fi<<' '<<ans.se<<endl;
	
	return 0;
}

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

const int N=25001;
pii a[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int n,t; cin>>n>>t;
	for (int i=1;i<=n;i++) cin>>a[i].fi>>a[i].se;
	sort(a+1,a+n+1);
	int ans=0,cur=0,ma=0;
	for (int i=1;i<=n;i++) {
		auto [x,y]=a[i];
		if (x>cur+1) ans++,cur=ma;
		if (x>cur+1) break;
		if (x<=cur+1) chkmax(ma,y);
		if (ma==t) {cur=t;ans++;break;}
	}
	cout<<(cur==t?ans:-1)<<endl;
	
	return 0;
}

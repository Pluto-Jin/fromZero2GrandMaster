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

const int N=1e5+1;
int a[N],b[N];

double dist(ll i,ll j) {
	return sqrt(i*i+j*j);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int t; cin>>t;
	while (t--) {
		int n; cin>>n;
		for (int i=0,j=0;i+j<n+n;) {
			int x,y; cin>>x>>y;
			if (!x) a[i++]=abs(y);
			if (!y) b[j++]=abs(x);
		}
		sort(a,a+n);
		sort(b,b+n);
		double ans=0;
		for (int j=n-1;~j;j--) {
			ans+=dist(a[j],b[j]);
		}
		cout<<fixed<<setprecision(12)<<ans<<endl;
	}	

	return 0;
}

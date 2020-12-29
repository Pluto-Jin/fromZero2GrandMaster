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
		int ans=0;
		int n; cin>>n;
		vi a(n+1); for (int i=1;i<=n;i++) cin>>a[n+1-i],ans+=a[n+1-i];
		int m; cin>>m;
		vi b(m+1); for (int i=1;i<=m;i++) cin>>b[m+1-i],ans+=b[m+1-i];
		for (int i=1;i<=n;i++) a[i]+=a[i-1];
		for (int i=1;i<=m;i++) b[i]+=b[i-1];
		int mi=1e9;
		for (int i=0;i<=n;i++) for (int j=0;j<=m;j++) chkmin(mi,a[i]+b[j]);
		cout<<max(ans,ans-mi)<<endl;
	}
	
	return 0;
}

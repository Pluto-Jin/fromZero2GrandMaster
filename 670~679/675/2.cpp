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

int a[101][101];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int t; cin>>t;
	while (t--) {
		int n,m; cin>>n>>m;
		for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) cin>>a[i][j];
		ll ans=0;
		for (int i=1;i<=(n+1)/2;i++) for (int j=1;j<=(m+1)/2;j++) {
			ll b[4]={a[i][j],a[n+1-i][j],a[i][m+1-j],a[n+1-i][m+1-j]};
			sort(b,b+4);
			if (i==n+1-i or j==m+1-j) ans+=b[2]-b[1];
			else ans+=b[3]-b[0]+b[2]-b[1];
		}
		cout<<ans<<endl;
	}
	
	return 0;
}

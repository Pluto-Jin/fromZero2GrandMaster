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

const int N=5001;
int dp[N][N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int n,m; cin>>n>>m;
	string a,b; cin>>a>>b;
	int ans=0;
	for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) {
		if (a[i-1]==b[j-1]) chkmax(dp[i][j],dp[i-1][j-1]+2);
		chkmax(dp[i][j],dp[i-1][j]-1);
		chkmax(dp[i][j],dp[i][j-1]-1);
		chkmax(ans,dp[i][j]);
	}
	cout<<ans<<endl;
	
	return 0;
}

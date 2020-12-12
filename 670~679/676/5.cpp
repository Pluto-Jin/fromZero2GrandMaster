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

const int N=2e5+1;
int n;
ll dp[N][3][2][2],a[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	if (n==1) {cout<<abs(a[1])<<endl;return 0;}
	memset(dp,0xc0,sizeof dp);
	dp[1][1][1][0]=-a[1];
	dp[1][0][1][1]=a[1];
	for (int i=2;i<=n;i++) for (int j=0;j<3;j++) {
		dp[i][j][0][0]=-a[i]+max(max(dp[i-1][(j+2)%3][0][0],dp[i-1][(j+2)%3][0][1]),dp[i-1][(j+2)%3][1][0]);
		dp[i][j][0][1]=a[i]+max(max(dp[i-1][j][0][0],dp[i-1][j][0][1]),dp[i-1][j][1][1]);
		dp[i][j][1][0]=-a[i]+dp[i-1][(j+2)%3][1][1];
		dp[i][j][1][1]=a[i]+dp[i-1][j][1][0];
	}
	cout<<max(dp[n][(4-n%3)%3][0][0],dp[n][(4-n%3)%3][0][1])<<endl;

	return 0;
}

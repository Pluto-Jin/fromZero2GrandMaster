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

const int N=1e6+1,MOD=998244353;
int dp[N],pre[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int n; cin>>n;
	dp[1]=1,dp[2]=2,pre[1]=1,pre[2]=3;
	for (int i=3;i<=n;i++) {
		int j=20; while ((i>>j&1)==0) j--;
		dp[i]=1;
		if (i-1>>j&1) dp[i]+=(pre[i-1]-pre[(1<<j)-1]+MOD)%MOD;
		for (j=j-1;~j;j--) if ((i>>j&1)==0) 
			dp[i]+=(pre[(1<<j+1)-1]-pre[(1<<j)-1]+MOD)%MOD,dp[i]%=MOD;
		pre[i]=pre[i-1]+dp[i],pre[i]%=MOD;
	}
	cout<<pre[n]<<endl;
	
	return 0;
}

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
ll n,s,t[N],c[N],dp[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	memset(dp,0x3f,sizeof dp);
	cin>>n>>s;
	for (int i=1;i<=n;i++) cin>>t[i]>>c[i],t[i]+=t[i-1],c[i]+=c[i-1];
	dp[0]=0;
	for (int i=1;i<=n;i++) for(int j=0;j<i;j++) 
		chkmin(dp[i],dp[j]+t[i]*(c[i]-c[j])+s*(c[n]-c[j]));
	cout<<dp[n]<<endl;
	
	return 0;
}

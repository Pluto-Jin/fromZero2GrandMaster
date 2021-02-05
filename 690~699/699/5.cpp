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

const int N=5e5+5;
int n,a[N],l[N],r[N],cnt[N],ma[N],dp[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	cin>>n;
	for (int i=1;i<=n;i++) {
		cin>>a[i];
		if (!l[a[i]]) l[a[i]]=i;
		r[a[i]]=i;
	}
	for (int i=n;i;i--) ma[i]=max(ma[i+1],++cnt[a[i]]);
	int ans=1e9;
	for (int i=1;i<=n;i++) {
		dp[i]=dp[i-1];
		if (i==r[a[i]]) chkmax(dp[i],dp[l[a[i]]-1]+cnt[a[i]]);
		chkmin(ans,n-dp[i]-ma[i+1]);
	}
	cout<<ans<<endl;
	
	return 0;
}

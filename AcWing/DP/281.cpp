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

const int N=1e5+1;
int a[101],c[101],cnt[N];
bool dp[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	while (1) {
		int n,m; cin>>n>>m;
		if (!n and !m) break;
		for (int i=1;i<=n;i++) cin>>a[i];
		for (int i=1;i<=n;i++) cin>>c[i];
		dp[0]=1;
		for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) {
			cnt[j]=0;
			if (!dp[j] and j>=a[i] and dp[j-a[i]] and cnt[j-a[i]]<c[i]) 
				dp[j]=1,cnt[j]=cnt[j-a[i]]+1;
		}
		int ans=0;
		for (int i=1;i<=m;i++) if (dp[i]) ans++,dp[i]=0;
		cout<<ans<<endl;
	} 
	
	return 0;
}

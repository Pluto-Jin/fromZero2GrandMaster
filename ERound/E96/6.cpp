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

const int N=2005;
int l[N],r[N],a[N];
ll dp[N],pre[N],f[N][N];
bool ok[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int n,k; cin>>n>>k;
	for (int i=1;i<=n;i++) cin>>l[i]>>r[i]>>a[i],pre[i]=pre[i-1]+a[i];
	memset(f,-1,sizeof f);
	for (int i=1;i<=n;i++) {
		int bg=k;
		for (int j=i;j<=n;j++) {
			int t=(max(0,a[j]-bg)+k-1)/k;
			if (r[j]-l[j]<t) break;
			bg+=t*k-a[j];
			if (j==n) ok[i]=1;
			else if (l[j+1]-l[j]>t) f[i][j]=bg;
		}
	}

	memset(dp,0x3f,sizeof dp);
	dp[1]=0;
	for (int i=2;i<=n;i++) for (int j=1;j<i;j++) 
		if (f[j][i-1]!=-1) chkmin(dp[i],dp[j]+pre[i-1]-pre[j-1]+f[j][i-1]);

	ll ans=1e18;
	for (int i=1;i<=n;i++) if (ok[i]) chkmin(ans,dp[i]+pre[n]-pre[i-1]);

	cout<<(ans==1e18?-1:ans)<<endl;
		
	
	return 0;
}

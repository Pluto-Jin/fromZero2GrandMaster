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
inline bool chkmin(T &x,const T2 &y){return x>=y?(x=y,1):0;}

const int N=2e5+1,M=1e7+1;
int n,k,mip[M],dp[N][21],l[N],f[N][21];
vi pr;

void sieve(int n=M) {
	for (int i=2;i<=n;i++) {
		if (!mip[i]) mip[i]=i,pr.pb(i);
		for (auto j:pr) {
			if (1ll*i*j>n) break;
			mip[i*j]=j;
			if (i%j==0) break;	
		}
	}
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	sieve();
	int t; cin>>t;
	while (t--) {
		int n,k; cin>>n>>k;
		int ans=0;
		set<int> s;
		map<int,int> pos;
		for (int i=0;i<=k;i++) dp[1][i]=f[1][i]=1;

		for (int i=1;i<=n;i++) {
			int x; cin>>x; int tmp=1;
			while (1) { 
				while (x>1 and x%(1ll*mip[x]*mip[x])==0) x/=1ll*mip[x]*mip[x];
				if (x==1) break; 
				tmp*=mip[x],x/=mip[x];
			}
			if (s.count(tmp)) s.clear();
			s.insert(tmp);
			l[i]=pos[tmp],pos[tmp]=i;
		}
		for (int j=0;j<=k;j++) {
			for (int i=2;i<=n;i++) {
				if (j) dp[i][j]=dp[i-1][j-1],f[i][j]=f[i-1][j-1];
				else dp[i][0]=1e9;
				if (l[i]>=f[i-1][j]) {
					if (chkmin(dp[i][j],dp[i-1][j]+1)) f[i][j]=i;
				} else {
					if (chkmin(dp[i][j],dp[i-1][j])) f[i][j]=f[i-1][j];
				}
			}
		}
		cout<<dp[n][k]<<endl;
	}
	
	return 0;
}

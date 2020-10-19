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

int dp[50][50][2];
char e[50];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int n; cin>>n;
	for (int i=0;i<n;i++) for (int j=0;j<n;j++) dp[i][j][0]=1e9,dp[i][j][1]=-1e9;
	for (int i=0,x;i<2*n;i++) if (i%2) cin>>x,dp[i/2][i/2][0]=dp[i/2][i/2][1]=x; else cin>>e[i/2];
	int ma=0;
	for (int len=2;len<=n;len++) for (int i=0;i<n;i++) {
		int j=(i+len-1)%n;
		for (int k=i;k<i+len-1;k++) {
			int lmi=dp[i][k%n][0],lma=dp[i][k%n][1],rmi=dp[(k+1)%n][j][0],rma=dp[(k+1)%n][j][1],l=1e9,r=-1e9;
			if (e[(k+1)%n]=='t') l=lmi+rmi,r=lma+rma; 
			else {
				chkmin(l,lmi*rmi),chkmax(r,lmi*rmi);
				chkmin(l,lmi*rma),chkmax(r,lmi*rma);
				chkmin(l,lma*rmi),chkmax(r,lma*rmi);
				chkmin(l,lma*rma),chkmax(r,lma*rma);
			}
			chkmin(dp[i][j][0],l);
			chkmax(dp[i][j][1],r);
		}
		if (len==n) chkmax(ma,dp[i][j][1]);
	}
	vi ans;
	for (int i=0;i<n;i++) {
		int j=(i+n-1)%n;
		if (dp[i][j][1]==ma) ans.pb(i+1);
	}
	cout<<ma<<endl;
	sort(ans.begin(),ans.end());
	for (auto i:ans) cout<<i<<' ';
	cout<<endl;
	
	return 0;
}

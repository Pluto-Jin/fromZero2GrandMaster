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

const int N=1001;
double dp[N],f[N][N];

void init(int m) {
	f[1][1]=f[m][m]=2./3; f[1][2]=f[m][m-1]=-1./3;
	dp[1]=1./3*dp[1]+1; dp[m]=1./3*dp[m]+1;
	for (int i=2;i<m;i++) f[i][i-1]=f[i][i+1]=-1./4,f[i][i]=3./4,dp[i]/=4,dp[i]+=1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
	
	int n,m,a,b; cin>>n>>m>>a>>b;
	cout.precision(4);
	cout<<fixed;
	if (n==1) {cout<<0.<<endl; return 0;}	
	if (m==1) {cout<<2.*n-2.*a<<endl; return 0;}

	for (int i=n-1;i>=a;i--) {
		init(m);
		for (int j=1;j<m;j++) {
			double tmp=-f[j+1][j]/f[j][j];
			f[j+1][j]=0;
			f[j+1][j+1]+=tmp*f[j][j+1];
			dp[j+1]+=tmp*dp[j];
		}
		for (int j=m;j>=1;j--) {
			dp[j]/=f[j][j];
			f[j][j]=1;
			dp[j-1]-=f[j-1][j]*dp[j];
			f[j-1][j]=0;
		}
	}
	cout<<dp[b]<<endl;
	
	return 0;
}

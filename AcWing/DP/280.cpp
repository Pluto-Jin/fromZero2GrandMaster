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

int dp[201][21][851],p[201],s[201],dif[201];
bool xuan[201][21][801];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int tc=0;
	while (1) {
		tc++;
		int n,m; cin>>n>>m;
		if (!n and !m) break;
		for (int i=1;i<=n;i++) {
			int x,y; cin>>x>>y;
			dif[i]=x-y,p[i]=x,s[i]=x+y;
		}
		memset(dp,-1,sizeof(dp));
		memset(xuan,0,sizeof(xuan));
		dp[0][0][400]=0;
		for (int i=1;i<=n;i++) {
			dp[i][0][400]=0;
			for (int j=1;j<=min(i,m);j++) for (int k=400-20*j;k<=400+20*j;k++) {
				int a=dp[i-1][j][k],b=dp[i-1][j-1][k-dif[i]];
				dp[i][j][k]=a;
				if (~b and b+s[i]>a) dp[i][j][k]=b+s[i],xuan[i][j][k]=1;
			}
		}
		int cur=0;
		for (int i=0;i<=400;i++) {
			int a=dp[n][m][400+i],b=dp[n][m][400-i];
			if (~a or ~b) {
				if (a>b) cur=400+i;
				else cur=400-i;
				break;
			}
		}
		vi ans(m+1);
		for (int i=m,p=n;i;p--) if (xuan[p][i][cur]) ans[i--]=p,cur-=dif[p]; 
		int a=0,b=0;
		for (int i=1;i<=m;i++) a+=p[ans[i]],b+=s[ans[i]];
		cout<<"Jury #"<<tc<<endl;
		cout<<"Best jury has value "<<a<<" for prosecution and value "<<b-a<<" for defence:"<<endl;
		for (int i=1;i<=m;i++) cout<<' '<<ans[i];
		cout<<endl<<endl;
	}
	
	return 0;
}

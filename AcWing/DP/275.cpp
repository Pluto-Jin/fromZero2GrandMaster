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
inline bool chkmax(T &x,const T2 &y){if(x<y)x=y;return x<y;}
template<class T,class T2>
inline bool chkmin(T &x,const T2 &y){if(x>y)x=y;return x>y;}

int a[51][51],dp[102][51][51];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int n,m; cin>>n>>m;
	for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) cin>>a[i][j];
	for (int k=3;k<=n+m;k++) 
		for (int i=1,yi=k-i;i<=n and yi>0;i++,yi=k-i) 
			for (int j=1,yj=k-j;j<=n and yj>0;j++,yj=k-j) 
				if (yi<=m and yj<=m and (i!=j or k==n+m)) { 
					int cur=a[i][yi]+a[j][yj];
					chkmax(dp[k][i][j],cur+dp[k-1][i][j]);
					chkmax(dp[k][i][j],cur+dp[k-1][i-1][j]);
					chkmax(dp[k][i][j],cur+dp[k-1][i][j-1]);
					chkmax(dp[k][i][j],cur+dp[k-1][i-1][j-1]);
				}
	cout<<dp[n+m][n][n]<<endl;
	
	return 0;
}

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
using namespace std;

#define fi first
#define se second
#define endl '\n'
#define pb push_back
#define ppf pop_front
#define ppb pop_back
#define mp make_pair
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<vi> vvi;

const int N=20,M=1<<20;
int g[N][N],dp[M][N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int n; cin>>n;
	for (int i=0;i<n;i++) for (int j=0;j<n;j++) cin>>g[i][j];

	memset(dp,0x3f,sizeof(dp));
	dp[1][0]=0;

	for (int i=0;i<1<<n;i++) for (int j=0;j<n;j++) if (i&(1<<j))
		for (int k=0,tmp=1<<j^i;k<n;k++) if (tmp&1<<k) dp[i][j]=min(dp[i][j],dp[tmp][k]+g[k][j]);

	cout<<dp[(1<<n)-1][n-1]<<endl;
	return 0;
}

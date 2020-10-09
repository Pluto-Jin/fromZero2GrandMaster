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

int dp[1001][201][201],c[201][201],a[1001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int n,q; cin>>n>>q;
	for (int i=1;i<=n;i++) for (int j=1;j<=n;j++) cin>>c[i][j];
	for (int i=1;i<=q;i++) cin>>a[i];
	memset(dp,0x3f,sizeof(dp));
	a[0]=3; dp[0][1][2]=0;

	for (int t=0;t<q;t++) for (int i=1;i<=n;i++) for (int j=1;j<=n;j++) {
		if (i!=j and i!=a[t] and j!=a[t] and dp[t][i][j]!=0x3f3f3f3f) {
			int cur=dp[t][i][j],k=a[t],u=a[t+1];
			dp[t+1][i][j]=min(dp[t+1][i][j],cur+c[k][u]);
			dp[t+1][i][k]=min(dp[t+1][i][k],cur+c[j][u]);
			dp[t+1][j][k]=min(dp[t+1][j][k],cur+c[i][u]);
		}
	}
	int ans=1e9;
	for (int i=1;i<=n;i++) for (int j=1;j<=n;j++) ans=min(ans,dp[q][i][j]);
	cout<<ans<<endl;

	return 0;
}

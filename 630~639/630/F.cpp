#include "bits/stdc++.h"
using namespace std;

#define fi first
#define se second
#define endl '\n'
#define pb push_back
#define ppf pop_front
#define ppb pop_back
#define mp make_pair
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef long long ll;

const int N=3e5+1,MOD=998244353;
int n,vis[N];
ll dp[3][N];
vi edge[N];

ll fpow(int a,int b) {
	ll res=1;
	while (b) {
		if (b%2) res*=a;
		b/=2;
		a*=a;
	}
	return res;
}
ll solve(int at,int p) {
	if (vis[at]) return (dp[0][at]+dp[1][at])%MOD;
	dp[0][at]=1,dp[1][at]=1,dp[2][at]=1;
	ll tmp=1;
	for (auto to:edge[at]) {
		if (to==p) continue;
		solve(to,at);
		dp[0][at]*=(2*dp[0][to]+2*dp[1][to]+dp[2][to]+3)%MOD,dp[0][at]%=MOD;
		dp[1][at]*=(2*dp[0][to]+dp[1][to]+2)%MOD,dp[1][at]%=MOD;
		dp[2][at]*=dp[0][to]+dp[1][to]+1,dp[2][at]%=MOD;
		tmp*=dp[0][to]+dp[1][to]+1,tmp%=MOD;
	}
	vis[at]=1;
	dp[0][at]--,dp[0][at]%=MOD;
	dp[1][at]+=MOD-tmp,dp[1][at]%=MOD;
	dp[2][at]--,dp[2][at]%=MOD;
	return (dp[0][at]+dp[1][at])%MOD;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	cin>>n;
	for (int i=1;i<n;i++) {
		int x,y; cin>>x>>y;
		edge[x].pb(y);
		edge[y].pb(x);	
	}
	cout<<solve(1,-1)<<endl;
}


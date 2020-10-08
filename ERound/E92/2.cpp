#include "bits/stdc++.h"
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

const int N=1e5+1;
int dp[N][6];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int t; cin>>t;
	while (t--) {
		int n,k,z; cin>>n>>k>>z;
		vi ar(n+1);
		for (int i=1;i<=n;i++) cin>>ar[i];
		dp[1][0]=ar[1];
		for (int i=2;i<=n;i++) {
			dp[i][0]=dp[i-1][0]+ar[i];
			for (int j=1;j<=z;j++) {
				dp[i][j]=max(dp[i][j-1]+ar[i]+ar[i-1],dp[i-1][j]+ar[i]);
			}
		}
		int ans=0;
		for (int i=1;i<=n;i++) for (int j=0;j<=z;j++) {
			if (i-1+j*2<=k) ans=max(ans,dp[i][j]);
			if (i>1 and j<z and i-1+j*2<k) ans=max(ans,dp[i][j]+ar[i-1]);
		}
		cout<<ans<<endl;
		for (int i=1;i<=n;i++) for (int j=0;j<=z;j++) dp[i][j]=0;
	}
}


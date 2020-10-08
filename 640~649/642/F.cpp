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

const int N=101;
const ll INF=2e18;
int n,m;
ll ar[N][N],dp[N][N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int t; cin>>t;
	while (t--) {
		cin>>n>>m;
		ll ans=2e18;
		for (int i=0;i<n;i++) for (int j=0;j<m;j++) cin>>ar[i][j];		
		for (int i=0;i<n;i++) {
			for (int j=0;j<m;j++) {
				ll bg=ar[i][j]-i-j;
				if (bg>ar[0][0]) continue;
				dp[0][0]=ar[0][0]-bg;
				for (int x=0;x<n;x++) {
					for (int y=0;y<m;y++) {
						if (x or y) dp[x][y]=INF;
						if (bg+x+y<=ar[x][y]) {
							ll tmp=ar[x][y]-bg-x-y;
							if (x) dp[x][y]=min(dp[x][y],tmp+dp[x-1][y]);
							if (y) dp[x][y]=min(dp[x][y],tmp+dp[x][y-1]);
							dp[x][y]=min(dp[x][y],INF);
						}
					}
				}
				ans=min(ans,dp[n-1][m-1]);
			}
		}
		cout<<ans<<endl;
	}
}


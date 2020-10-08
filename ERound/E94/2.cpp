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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int t; cin>>t;
	while (t--) {
		int n; cin>>n;
		vvi cnt(n+1,vi(n+2));
		vector<vector<ll>> dp(n+1,vector<ll>(n+2));
		vi ar(n+1);
		for (int i=1;i<=n;i++) cin>>ar[i];
		for (int i=1;i<=n;i++) for (int j=n;j>=1;j--) 
			cnt[i][j]=cnt[i][j+1]+(ar[j]==i);
		for (int j=n-1;j>=3;j--) for (int i=j-2;i>=1;i--) {
			int tmp=ar[i+1];
			dp[i][j]=dp[i+1][j]+cnt[tmp][j+1];	
		}

		ll ans=0;
		for (int i=1;i<=n-3;i++) for (int j=i+2;j<=n-1;j++)  
			if (ar[i]==ar[j]) ans+=dp[i][j];
		cout<<ans<<endl;
	}
}


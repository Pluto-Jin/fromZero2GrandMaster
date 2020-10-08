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
		vi ar(n+1),dp(n+1);
		for (int i=1;i<=n;i++) cin>>ar[i],dp[i]=1;
		int ans=1;
		for (int i=2;i<=n;i++) {
			for (int j=1;j<=sqrt(i);j++) {
				if (i%j==0) {
					if (ar[i]>ar[j]) dp[i]=max(dp[i],dp[j]+1);
					if (i/j!=j and ar[i]>ar[i/j]) dp[i]=max(dp[i],dp[i/j]+1);
					ans=max(ans,dp[i]); 
				}
			}
		}
		cout<<ans<<endl;
	}
}


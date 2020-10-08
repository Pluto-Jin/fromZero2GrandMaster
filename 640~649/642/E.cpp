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
		int n,k; cin>>n>>k;
		string s; cin>>s;
		vi dp(n),cnt(n);
		int ccnt=0,ans=1e6;
		for (int i=0;i<n;i++) {
			if (i) cnt[i]=cnt[i-1];
			if (s[i]=='1') cnt[i]++,ccnt++;
		}
		for (int i=0;i<n;i++) {
			if (i) dp[i]=cnt[i-1];
			if (i-k>=0) dp[i]=min(dp[i],dp[i-k]+cnt[i-1]-cnt[i-k]);
			dp[i]+=s[i]=='0';
			ans=min(ans,dp[i]+ccnt-cnt[i]);
		}
		cout<<min(ans,ccnt)<<endl;
	}
}


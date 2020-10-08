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

const int N=2e6+1,MOD=1e9+7;
int dp[N];
bool use[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	dp[3]=use[3]=1;
	for (int x=4;x<N;x++) {
		dp[x]=(1ll*dp[x-1]+2ll*dp[x-2])%MOD;
		if (!use[x-1] and !use[x-2]) dp[x]++,use[x]=1;
	}
	int t; cin>>t;
	while (t--) {
		int n; cin>>n;
		cout<<dp[n]*4ll%MOD<<endl;
	}
}


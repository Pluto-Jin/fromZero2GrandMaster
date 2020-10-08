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

const int N=2000,INF=0x3f3f3f3f;
int dp[N][N];

int solve (int m,int n) {
	if (dp[m][n]<INF) return dp[m][n]; 

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int n; cin>>n;
	vi ar(n+1),p(n+1);
	for (int i=0;i<n;i++) cin>>ar[i+1];
	for (int i=0;i<n;i++) cin>>p[i+1];
	int m; cin>>m;
	vi br(m+1);
	for (int i=0;i<n;i++) cin>>br[i+1];

	memset(dp,0x3f,sizeof(dp));

	cout<<solve(m,n);
}


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

const int N=2001;
int a[N],b[N];
ll dp[N][N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int n; cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i],b[i]=a[i];
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++) {
		dp[i][1]=dp[i-1][1]+abs(a[1]-b[i]);
		for (int j=2;j<=n;j++) 
			dp[i][j]=min(dp[i][j-1],dp[i-1][j]+abs(a[j]-b[i]));
	}
	ll ans=dp[n][n];
	sort(a+1,a+n+1,greater<>());
	for (int i=1;i<=n;i++) {
		dp[i][1]=dp[i-1][1]+abs(a[1]-b[i]);
		for (int j=2;j<=n;j++) 
			dp[i][j]=min(dp[i][j-1],dp[i-1][j]+abs(a[j]-b[i]));
	}

	cout<<min(ans,dp[n][n])<<endl;

	return 0;
}

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

const int N=3001;
int a[N],b[N],dp[N][N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int n; cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=1;i<=n;i++) cin>>b[i];

	for (int i=1;i<=n;i++) {
		int ma=0;
		for (int j=1;j<=n;j++) {
			if (a[i]!=b[j]) dp[i][j]=dp[i-1][j];
			else dp[i][j]=ma+1;
			if (b[j]<a[i]) ma=max(ma,dp[i][j]);
		}
	} 
	int ans=0;
	for (int i=1;i<=n;i++) ans=max(ans,dp[n][i]);
	cout<<ans<<endl;

	return 0;
}

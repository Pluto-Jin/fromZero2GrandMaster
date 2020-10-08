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

const int N=1e6+1;
ll a[N];
ll dp[N][2];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	ll n,r1,r2,r3,d; cin>>n>>r1>>r2>>r3>>d;
	r3=min(r1+d+d+r1,r3);
	for (int i=1;i<=n;i++) cin>>a[i];
	dp[1][0]=a[1]*r1+r3;
	dp[1][1]=min(r2,(a[1]+1)*r1);
	for (int i=2;i<=n;i++) {
		dp[i][0]=dp[i-1][0]+d+a[i]*r1+r3;
		dp[i][0]=min(dp[i][0],dp[i-1][1]+d+min((a[i]+1)*r1+d+r1+d+r1,a[i]*r1+r3+d+r1+d));
		dp[i][0]=min(dp[i][0],dp[i-1][1]+d+r2+d+r1+d+r1);
		dp[i][1]=min(dp[i-1][0],dp[i-1][1]+d+r1+d)+d+min((a[i]+1)*r1,r2);
	}
	cout<<min(dp[n][0],dp[n-1][1]+d+r1*a[n]+r3+d+r1)<<endl;
}

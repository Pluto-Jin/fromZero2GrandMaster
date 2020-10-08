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

const int N=2e5+1;
int a[N],dp[2][N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int t; cin>>t;
	while (t--) {
		int n; cin>>n;
		for (int i=1;i<=n;i++) cin>>a[i],dp[0][i]=dp[1][i]=1e9;
		dp[0][1]=a[1];
		if (n==1) {cout<<a[1]<<endl;continue;}
		dp[0][2]=a[1]+a[2];
		dp[1][2]=a[1];
		if (n==2) {cout<<min(dp[0][2],dp[1][2])<<endl;continue;}
		for (int i=3;i<=n;i++) {
			dp[0][i]=min(dp[1][i-1],dp[1][i-2]+a[i-1])+a[i];
			dp[1][i]=min(dp[0][i-1],dp[0][i-2]);
		}
		cout<<min(dp[0][n],dp[1][n])<<endl;
	}
}

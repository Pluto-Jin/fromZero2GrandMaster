#include "bits/stdc++.h"
using namespace std;

#define fi first
#define se first
#define endl '\n'
#define pb push_back
#define mp make_pair
typedef pair<int,int> pii;
typedef long long ll;

const int N=2001;
int dp[N][N],ok[N][N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int n,h,l,r; cin>>n>>h>>l>>r;
	vector<int> ar; ar.resize(n);
	for (auto &i:ar) cin>>i;

	ok[0][ar[0]]=1; ok[0][ar[0]-1]=1;
	dp[0][ar[0]]=(l<=ar[0] and ar[0]<=r); 
	dp[0][ar[0]-1]=(l<=ar[0]-1 and ar[0]-1<=r); 
	for (int i=1;i<n;i++) {
		for (int j=0;j<h;j++) 
			if (ok[i-1][j]) {
				int tmp=(j+ar[i]-1)%h;
				ok[i][tmp]=1;
				dp[i][tmp]=max(dp[i][tmp],dp[i-1][j]+(l<=tmp and tmp<=r));
				tmp=(tmp+1)%h;
				ok[i][tmp]=1;
				dp[i][tmp]=max(dp[i][tmp],dp[i-1][j]+(l<=tmp and tmp<=r));
			}
	}
	int ans=0;
	for (int i=0;i<h;i++) ans=max(ans,dp[n-1][i]);
	cout<<ans<<endl;
}

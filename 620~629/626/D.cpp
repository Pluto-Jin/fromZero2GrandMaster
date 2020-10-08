#include "bits/stdc++.h"
using namespace std;

#define fi first
#define se first
#define endl '\n'
#define pb push_back
#define mp make_pair
typedef pair<int,int> pii;
typedef long long ll;

ll dp[32],ans[32];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int n;
	cin>>n;
	vector<int> ar;
	ar.resize(n);
	for (auto &i:ar) {
		cin>>i;
		for (int j=0;j<32;j++) if (i&(1<<j)) dp[j]++;
	}
	ans[0]=(dp[0]*(n-dp[0]))%2;
	dp[1]+=(dp[0]*(dp[0]-1)/2);
	for (int i=1;i<31;i++) {ans[i]=(dp[i]*(n-dp[i]));dp[i+1]+=(dp[i]*(dp[i]-1)/2);}	
	for (auto i:ans) cout<<i<<endl;

}

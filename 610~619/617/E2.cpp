#include "bits/stdc++.h"
using namespace std;

int main()
{
	int n;
	cin>>n;
	string s;
	cin>>s;

	int dp[26]={0};
	vector<int> ddp;
	ddp.resize(n);
	for (int i=0;s[i];i++) {
		int tmp=s[i]-'a';
		if (!dp[tmp]) dp[tmp]=1;
		for (int j=tmp+1;j<26;j++) dp[tmp]=max(dp[tmp],dp[j]+1);
		ddp[i]=dp[tmp];
	}
	int ans=0;
	for (int i=0;i<26;i++) ans=max(ans,dp[i]);
	cout<<ans<<endl;
	for (int i=0;i<n;i++) cout<<ddp[i]<<" ";
	cout<<endl;
}


#include "bits/stdc++.h"
using namespace std;

int t,n,p,k;
vector<int> ar;
vector<int> sum;
vector<int> ans;
int tmp;
int res;

int main()
{
	cin>>t;
	while (t--)
	{
		cin>>n>>p>>k;
		ar.clear();
		ar.resize(n);
		sum.clear();
		sum.resize(k);
		ans.clear();
		ans.resize(k);
		res=0;

		for (auto &i:ar) cin>>i;

		sort(ar.begin(),ar.end());
		if (p<ar[0]) 
		{
			cout<<0<<endl;
			continue;
		}
		for (int i=0;i<n;i++)
		{
			tmp=i%k;
			sum[tmp]+=ar[i];
			if (sum[tmp]<=p and (i>=k-1 or i==0)) ans[tmp]+=min(k,i+1);
			res=max(res,ans[tmp]);
		}
		sum[0]=ar[0];
		ans[0]=1;
		for (int i=1;i<n;i++)
		{
			tmp=i%k;
			if (i<k)
			{
				if (i==k-1) 
				{
					sum[i]=ar[i];
					if (sum[i]<=p) ans[i]=1;
				}
				else sum[i]=sum[i-1]+ar[i];
				if (sum[i]<=p) ans[i]=ans[i-1]+1;
				else
				{
					sum[i]=ar[i];
					if (sum[i]<=p) ans[i]=1;
				}
			}
			else
			{
				sum[tmp]+=ar[i];
				if (sum[tmp]<=p) ans[tmp]+=k;
				res=max(res,ans[tmp]);
			}
		}
		for (int i=0;i<k;i++) res=max(res,ans[i]);
		cout<<res<<endl;

	}
}

#include "bits/stdc++.h"
using namespace std;

int t,n,s;
int ind;
long long sum;
vector<int> ar;

int main()
{
	cin>>t;
	while (t--)
	{
		cin>>n>>s;
		ar.resize(n);
		for (auto &i:ar) cin>>i;

		sum=0;
		for (int i=0;i<n;i++) sum+=ar[i];
		if (sum<=s) cout<<0<<endl;
		else
		{
			ind=0;
			sum=0;
			for (int i=1;i<n;i++)
			{
				if (ar[i]>=ar[ind])
				{
					sum+=ar[ind];
					if (sum>s) break;
					ind=i;
				}
				else sum+=ar[i];
				if (sum>s) break;
			}
			cout<<ind+1<<endl;
		}
	}
}

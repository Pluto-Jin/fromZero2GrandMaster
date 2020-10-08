#include "bits/stdc++.h"
using namespace std;

int t,n,i;
int b;
vector<int> ar;

int main()
{
	cin>>t;
	while (t--)
	{
		b=0;
		cin>>n;
		ar.clear();
		ar.resize(n);
		for (i=0;i<n;i++) cin>>ar[i];

		if (n%2)
		{
			for (i=0;i<n/2+1;i++)
			{
				if (ar[i]<i)
				{
					b=1;
					break;
				}
			}
			for (i=n/2+1;i<n;i++)
			{
				if (i+ar[i]<n-1)
				{
					b=1;
					break;
				}
			}
		}
		else
		{
			for (i=0;i<n/2-1;i++)
			{
				if (ar[i]<i)
				{
					b=1;
					break;
				}
			}
			for (i=n/2+1;i<n;i++)
			{
				if (i+ar[i]<n-1)
				{
					b=1;
					break;
				}
			}
			for (i=n/2-1;i<n/2+1;i++)
			{
				if (i!=n/2 and i!=n/2-1 and i+ar[i]<n-1)
				{
					b=1;
					break;
				}
				if (i==n/2)
				{
					if (ar[i-1]<n/2-1 or ar[i]<n/2-1 or ar[i-1]==n/2-1 and ar[i]<n/2 or ar[i]==n/2-1 and ar[i-1]<n/2)
					{
						b=1;
						break;
					}
				}
			}
		}
		if (b) cout<<"NO"<<endl;
		else cout<<"YES"<<endl;

	}
}

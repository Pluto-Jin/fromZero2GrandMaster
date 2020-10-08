#include "bits/stdc++.h"
using namespace std;

int t,n,i,fg;
long long tmp,ma,sum;
vector<int> a,ans;

int main()
{
	cin>>t;
	while (t--)
	{
		cin>>n;
		a.clear();
		i=n;
		while (i--)
		{
			cin>>tmp;
			a.push_back(tmp);
		}

		tmp=0;
		fg=0;
		for (i=0;i<n;i++)
		{
			tmp+=a[i];
			if (tmp<=0)
			{
				fg=1;
				break;
			}
		}
		tmp=0;
		for (i=n-1;i>=0;i--)
		{
			tmp+=a[i];
			if (tmp<=0)
			{
				fg=1;
				break;
			}
		}
		if (!fg)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;	
	}
}

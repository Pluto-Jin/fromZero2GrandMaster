#include "bits/stdc++.h"
using namespace std;

int t,n,d;
vector<int> ans;

int main()
{
	cin>>t;
	while (t--)
	{
		cin>>n>>d;
		if (d<=n)
			ans.push_back(1);
		else
		{
			for (int i=sqrt(d)-1;;i++)
			{
				if (i*(i+1)<=d<(i+1)*(i+2))
				{
					ans.push_back((i+ceil(1.0*d/(i+1)))<=n);
					break;
				}
			}
		}
	}

	for (auto i:ans)
		if (i)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
}

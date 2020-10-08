#include "bits/stdc++.h"
using namespace std;

int t,k,st;
int ans;
int tmp;
string s;

int main()
{
	cin>>t;
	while (t--)
	{
		cin>>k;
		cin>>s;
		ans=0;
		tmp=0;
		st=0;
		for (auto i:s)
		{
			if (i=='A')
			{
				ans=max(ans,tmp);
				tmp=0;
				st=1;
			}
			else if (st)
				tmp+=1;
		}
		cout<<max(ans,tmp)<<endl;
	}
}

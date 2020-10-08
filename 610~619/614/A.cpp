#include "bits/stdc++.h"
using namespace std;

int t,n,s,k;
int i,j,tmp,up,dw;
set<int> a;
vector<int> ans;

int main()
{
	cin>>t;
	for (i=0;i<t;i++)
	{
		a.clear();
		cin>>n>>s>>k;
		for (j=0;j<k;j++) 
		{
			cin>>tmp;	
			a.insert(tmp);
		}
		up=s;
		dw=s;
		while (up<=n or dw>=1)
		{
			if (up<=n and !a.count(up) or dw>=1 and !a.count(dw))
			{
				ans.push_back(up-s);
				break;
			}
			up++;
			dw--;
		}
	}
	for (auto i:ans)
		cout<<i<<endl;
}

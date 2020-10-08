#include "bits/stdc++.h"
using namespace std;

int main()
{
	int t;
	cin>>t;
	while (t--)
	{
		int n;
		cin>>n;
		vector<int> p;
		p.resize(n);
		map<int,int> dic;
		for (int i=0;i<n;i++)
		{
			cin>>p[i];
			dic[p[i]]=i;
		}
		string s="";
		int mi=dic[1],ma=dic[1];
		for (int i=1;i<n+1;i++)
		{
			int pos=dic[i];
			mi=min(mi,pos);
			ma=max(ma,pos);
			if (ma-mi+1==i) s+='1';
			else s+='0';
		}
		cout<<s<<endl;
	}
}

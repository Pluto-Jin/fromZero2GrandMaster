#include "bits/stdc++.h"
using namespace std;

int solve(map<char,int> dic, string s)
{
	for (auto i:s)
	{
		dic[i]--;
		if (dic[i]<0) 
			return 0;
	}
	return 1;
}
int main()
{
	int t;
	cin>>t;
	string p;
	string h;
	while (t--)
	{
		int i;
		cin>>p;
		map<char,int> dic;
		dic.clear();
		for (auto i:p) dic[i]+=1;
		cin>>h;
		int lh=h.length();
		int lp=p.length();
		if (lh<lp) cout<<"NO"<<endl;
		else 
		{
			for (i=0;i<lh-lp+1;i++) 
				if (solve(dic,h.substr(i,lp)))
				{
					cout<<"YES"<<endl;
					i=-1;
					break;
				}
			if (i!=-1) cout<<"NO"<<endl;
		}	
	}
}

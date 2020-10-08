#include "bits/stdc++.h"
using namespace std;

int compare(string s,string c)
{
	for (int i=0;i<min(s.length(),c.length());i++)
	{
		if (s[i]<c[i]) return -1;
		if (s[i]>c[i]) return 1;
	}
	if (s.length()==c.length()) return 0;
	if (s.length()>c.length()) return 1;
	return -1;
}
int main()
{
	int t;
	cin>>t;
	while (t--)
	{
		string x;
		string s="",c="";
		cin>>s>>c;
		if (compare(s,c)<0) {cout<<s<<endl;continue;}
		
		int posi,posj;
		int i,j,flag=0;
		char tmp;
		for (i=0;i<s.length();i++)
		{
			tmp=s[i];
			for (j=i+1;j<s.length();j++)
				if (s[j]<s[i] and s[j]<=tmp)
				{
					tmp=s[j];
					posj=j;
					posi=i;
					flag=1;
				}
			if (flag) break;
		}
		if (i==s.length()) {cout<<"---"<<endl;continue;}
		tmp=s[posi];
		s[posi]=s[posj];
		s[posj]=tmp;
		if (compare(s,c)<0) cout<<s<<endl;
		else cout<<"---"<<endl;
	}
}

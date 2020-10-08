#include "bits/stdc++.h"
using namespace std;

int main()
{
	int t;
	cin>>t;
	while (t--)
	{
		string s;
		cin>>s;
		char tmp=0;
		int flag=0;
		for (int i=0;i<s.length();i++)
		{
			if (s[i]==tmp) 
			{
				flag=1;
				break;
			}
			else if (s[i]!='?') tmp=s[i];
			else
			{
				s[i]='a';
				if (s[i]==tmp or (i!=s.length()-1 and s[i]==s[i+1])) s[i]='b';
				if (s[i]==tmp or (i!=s.length()-1 and s[i]==s[i+1])) s[i]='c';
				tmp=s[i];
			}
		}
		if (flag) cout<<-1<<endl;
		else cout<<s<<endl;	
		
	}
}

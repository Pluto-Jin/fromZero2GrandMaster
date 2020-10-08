#include "bits/stdc++.h"
using namespace std;

int main()
{
	int n;
	string s;
	cin>>n;
	cin>>s;
	int b=0,w=0;
	char c;
	for (auto i:s)
		if (i=='B') b++;
		else w++;
	if (b*w==0)
	{
		cout<<0<<endl;
		return 0;
	}
	if (b%2) 
	{
		if (w%2 or n%2==0)
		{
			cout<<-1<<endl;
			return 0;
		}
		else c='B';
	}
	else 
	{
		if (w%2!=n%2)
		{
			cout<<-1<<endl;
			return 0;
		}
		else c='W';
	}
	vector<int> ans;
	for (int i=0;i<s.length();i++)
	{
		if (s[i]!=c)
		{
			ans.push_back(i);
			s.replace(i+1,1,1,char('B'+'W'-s[i+1]));
		}
	}
	cout<<ans.size()<<endl;
	for (auto i:ans) cout<<i+1<<" ";
	cout<<endl;

}

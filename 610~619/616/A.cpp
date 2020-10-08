#include "bits/stdc++.h"
using namespace std;

int t,n,tmp;
string s;
int odd;

int main()
{
	cin>>t;
	while (t--)
	{

		odd=0;
		cin>>n;
		cin>>s;
		for (int i=0;i<s.length();i++)
		{
			tmp=int(s[i])-int('0');
			if (tmp%2)
			{
				odd+=1;
			}
		}
		tmp=0;
		if (odd==0 or odd==1)
			cout<<-1<<endl;
		else
		{
			for (int i=0;i<s.length();i++)
			{
				if (!((int(s[i])-int('0'))%2))
					cout<<s[i];
				else
				{
					cout<<s[i];
					tmp+=1;
					if (tmp==2)
					{
						cout<<endl;
						break;
					}
				}
							
			}
		}
		
	}
}

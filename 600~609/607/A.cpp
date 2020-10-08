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
		char c=s[s.length()-1];
		if (c=='o') cout<<"FILIPINO"<<endl;
		else if (c=='u') cout<<"JAPANESE"<<endl;
		else cout<<"KOREAN"<<endl;
	}
}

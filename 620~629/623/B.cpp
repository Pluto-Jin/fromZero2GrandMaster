#include "bits/stdc++.h"
using namespace std;

int main()
{
	int t;
	cin>>t;
	while (t--) {
		int a,b,p;
		cin>>a>>b>>p;
		string s;
		cin>>s;
		int n=s.size();
		char c=s[n-2];
		int pos=n;
		for (int i=n-2;i>=0;i--) {
			if (s[i]==c) continue;
			p-=(c=='A'?a:b);
			c=s[i];
			if (p<0) break;
			else pos=i+2;
		}
		p-=(c=='A'?a:b);
		if (p>=0) pos=1;
		cout<<pos<<endl;
	}
}

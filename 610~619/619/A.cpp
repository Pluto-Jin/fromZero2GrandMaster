#include "bits/stdc++.h"
using namespace std;

int main()
{
	int t;
	cin>>t;
	while (t--) {
		string a,b,c;
		cin>>a;
		cin>>b;
		cin>>c;
		int flag;
		for (int i=0;i<a.size();i++) {
			if (c[i]==a[i] or c[i]==b[i]) flag=1;
			else {flag=0;break;}
		}
		if (flag) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}

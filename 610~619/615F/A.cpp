#include "bits/stdc++.h"
using namespace std;

int main()
{
	int t;
	cin>>t;
	while (t--) {
		int a,b,c,n;
		cin>>a>>b>>c>>n;
		int tmp=a+b+c+n;
		if (tmp%3 or a>tmp/3 or b>tmp/3 or c>tmp/3) cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
		
	}
}

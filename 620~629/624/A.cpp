#include "bits/stdc++.h"
using namespace std;

int main()
{
	int t;
	cin>>t;
	while (t--) {
		int a,b;
		cin>>a>>b;
		if (a>b) {
			int tmp=a-b;
			if (tmp%2) cout<<2<<endl;
			else cout<<1<<endl;
		} 
		else if (a<b) {
			int tmp=b-a;
			if (tmp%2) cout<<1<<endl;
			else cout<<2<<endl;
		}
		else cout<<0<<endl;
	}
}

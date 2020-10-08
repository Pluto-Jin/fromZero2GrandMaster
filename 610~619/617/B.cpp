#include "bits/stdc++.h"
using namespace std;

int main() 
{
	int t;
	cin>>t;
	while (t--) {
		long long  s;
		cin>>s;
		long long tmp=s;
		long long ans=0;
		int x;
		while (1) {
			x=tmp%10;
			tmp/=10;
			ans+=tmp*10;
			if (!tmp) {ans+=x;break;}
			tmp+=x;
		}
		cout<<ans<<endl;
	}
}


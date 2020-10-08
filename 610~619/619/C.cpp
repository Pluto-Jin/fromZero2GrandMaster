#include "bits/stdc++.h"
using namespace std;

int main()
{
	int t;
	cin>>t;
	while (t--) {
		int n,m;
		cin>>n>>m;
		long long ans=0;
		if (m==0) {cout<<0<<endl;continue;}
		if (n==1) {cout<<1<<endl;continue;}
		if (n==2) {if (m==1) {cout<<2<<endl;continue;} if (m==2) {cout<<3<<endl;continue;}}
		if (n-m>m) {
			int tmp=(n-m)/(m+1);
			ans+=1ll*(1+m)*m/2;
			ans+=1ll*(n-m)*m;
			ans+=1ll*tmp*tmp*m*(m+1)/2;
			int r=(n-m)%(m+1);
			ans+=1ll*r*tmp*m;
			if (r>1) ans+=1ll*r*(r-1)/2;
		}
		else {
			ans+=1ll*(1+m)*m/2;
			ans+=1ll*(n-m)*m;
			ans+=1ll*(n-m)*(n-m-1)/2;
		}
		cout<<ans<<endl;
	}
}

#include "bits/stdc++.h"
using namespace std;

int main()
{
	int t;
	cin>>t;
	while (t--) {
		long long x,y,a,b;
		cin>>x>>y>>a>>b;
		if ((y-x)%(a+b)) cout<<-1<<endl;
		else cout<<((y-x)/(a+b))<<endl;
	}
}

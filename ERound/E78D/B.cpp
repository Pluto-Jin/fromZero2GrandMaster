#include "bits/stdc++.h"
using namespace std;

int main()
{
	int t;
	int a,b;
	cin>>t;

	while (t--)
	{
		int i;
		cin>>a>>b;
		int x=abs(a-b);
		double tmp=sqrt(2*x+0.25)-0.5;
		for (i=ceil(tmp);;i++) if ((i*(i+1)/2-x)%2==0) break;
		cout<<i<<endl;
	}
}

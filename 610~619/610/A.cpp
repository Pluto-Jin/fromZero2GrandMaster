#include "bits/stdc++.h"
using namespace std;

int t,a,b,c,r;

int main()
{
	cin>>t;
	int tmp;
	while (t--)
	{
		cin>>a>>b>>c>>r;
		if (a>b)
		{
			tmp=a;
			a=b;
			b=tmp;
		}
		if (c+r<=a or c-r>=b) cout<<b-a<<endl;
		else cout<<max(b-c-r,0)+max(c-r-a,0)<<endl;
	}
}

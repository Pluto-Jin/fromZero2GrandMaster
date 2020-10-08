#include "bits/stdc++.h"
using namespace std;

int main()
{
	int t;
	cin>>t;
	int n;
	while (t--)
	{
		cin>>n;
		int tmp=n;
		int c=1;
		while (tmp>=10)
		{
			tmp/=10;
			c++;	
		}
		int x=1;
		for (int i=1;i<c;i++) x=10*x+1;
		cout<<(c-1)*9+max(0,tmp-1)+(n>=tmp*x)<<endl;

	}
}

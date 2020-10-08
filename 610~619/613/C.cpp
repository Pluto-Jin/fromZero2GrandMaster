#include "bits/stdc++.h"
using namespace std;

#define ll long long

ll x,i,a,b,tmp;

int main()
{
	cin>>x;
	for (i=int(sqrt(x));i>0;i--)
	{
		if (x%i)
			continue;
		if (i/__gcd(i,x/i)*(x/i)!=x)
			continue;
		cout<<i<<" "<<x/i<<endl;
		break;
	}
}

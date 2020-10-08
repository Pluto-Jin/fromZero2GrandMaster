#include "bits/stdc++.h"
using namespace std;

int main()
{
	int a,b,c,d,e,f;
	int x,y;
	cin>>a;
	cin>>b;
	cin>>c;
	cin>>d;
	cin>>e;
	cin>>f;

	int ans=0;
	x=min(a,d);
	y=min(b,c);
	for (int i=0;i<=x;i++)
	{
		ans=max(ans,e*i+f*min(y,(d-i)));
	}
	cout<<ans<<endl;

}

#include "bits/stdc++.h"
using namespace std;

int main()
{
	int t;
	cin>>t;
	while (t--) {
		int n,x,y;
		cin>>n>>x>>y;
		int tmp=min(x,y);
		if (y==tmp) y=x;
		x=tmp;
		int mi=min(n,max(x+y+1-n,1)),ma=max(1,min(x+y-1,n));

		cout<<mi<<" "<<ma<<endl;

	}
}
